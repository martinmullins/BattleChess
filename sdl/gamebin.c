/*
 * sdl/gamebin.c  --  game-binary integrity check (recovery step 3-2)
 *
 * Original source:
 *   src/chess.c          FUN_243e_0024 @ 243e:0024  (lines 16481-16515)
 *   CHESS_disassembly.asm  243e:0060 - 243e:00c0
 *
 * --------------------------------------------------------------------------
 * DOS context
 * --------------------------------------------------------------------------
 * Battle Chess ships with a Central Point Anti-Virus (CPAV) self-integrity
 * check baked into the LZEXE decompressor stub (startup segment 243e).
 * On every launch, before decompressing or running any game code, the stub:
 *
 *   1. Finds its own EXE path from the DOS PSP environment block
 *      (PSP offset 0x2c → env segment, SCASB scan for double-NUL,
 *       +3 bytes → full program path)    disassembly: 243e:003c-243e:005a
 *
 *   2. Opens that EXE file (INT 21h AH=3Dh, read-only)
 *      disassembly: 243e:0060-243e:0067
 *
 *   3. Reads 32 bytes from file offset 0 into CS:[BP+0x438]
 *      (INT 21h AH=3Fh CX=0x20 DX=BP+0x438)
 *      disassembly: 243e:0068-243e:0075
 *
 *   4. Seeks to end of file to obtain file size in DX:AX
 *      (INT 21h AX=0x4202 CX=0 DX=0)
 *      disassembly: 243e:0076-243e:007c
 *
 *   5. Closes the file (INT 21h AH=3Eh)
 *      disassembly: 243e:007d-243e:0083
 *
 *   6. Compares DX (file-size high word) against CS:[BP+0x462]
 *      and AX (file-size low word) against CS:[BP+0x460]
 *      If below expected: sets integrity flag CS:[BP+0x433] = 1
 *      disassembly: 243e:0085-243e:009c   src/chess.c:16489-16515
 *
 *   7. Compares 16 words (32 bytes) of the read buffer
 *      against the 32-byte reference at CS:0x0006
 *      (CMPSW.REPE CX=16  SI=CS:[BP+0x438]  DI=CS:0x0006)
 *      disassembly: 243e:00a3-243e:00b9   src/chess.c:16489
 *
 * If either check fails → CPAV prompt (FUN_243e_0230, see sdl/cpav.c).
 *
 * --------------------------------------------------------------------------
 * Reference data extracted from CHESS.EXE.orig
 * --------------------------------------------------------------------------
 * GAMEBIN_HDR_REF: CS:0x0006 in the startup segment, file offset 0x145e6.
 *   Equals CHESS.EXE.orig[2:34] -- MZ header bytes from last_page_sz onward,
 *   skipping the two-byte 'MZ' magic that LZEXE writes.
 *
 * GAMEBIN_EXPECTED_SIZE: 84337 bytes (0x14971).
 *   Stored as DX:AX = 0x0001:0x4971 at CS:[BP+0x462] / CS:[BP+0x460].
 *
 * GAMEBIN_READ_OFFSET: file position 0 (no seek before AH=3Fh read).
 *   The reference is bytes [2..33] of the file; the read buffer holds
 *   bytes [0..31].  On an unmodified EXE the CMPSW comparison of the
 *   buffer against the reference succeeds starting from word index 1
 *   (bytes 2-3 onward), meaning the first word ('MZ' magic) is NOT
 *   checked -- only the 30 bytes after it.
 *
 *   RECOVER NEXT (step 3-2-iv): verify exact match semantics by
 *   tracing the DOS execution with a debugger against CHESS.EXE.orig.
 * --------------------------------------------------------------------------
 */

#include "gamebin.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>

/* -------------------------------------------------------------------------
 * Default game binary path
 *
 * At DOS runtime this came from the PSP environment block
 * (disassembly: 243e:003c-243e:005a).  For the SDL port we fall back to
 * looking for CHESS.EXE.orig in the current directory.
 *
 * RECOVER NEXT (step 3-2-i): accept this as a parameter from argv once
 * args_parse() (step 3-1) is implemented, mirroring the DOS PSP scan.
 * ---------------------------------------------------------------------- */
#define GAMEBIN_DEFAULT_PATH  "CHESS.EXE.orig"

/* -------------------------------------------------------------------------
 * 32-byte MZ header reference
 *
 * DOS: 32-byte buffer at CS:0x0006  (= CS:[BP+0x103+0x0103] with DI)
 *      Filled with CHESS.EXE.orig bytes 2..33 at link time by CPAV/LZEXE.
 *      disassembly: 243e:00b2-243e:00b7  src/chess.c:16489
 *
 * Extracted from CHESS.EXE.orig file offset 0x145e6
 * (CS segment at 0x145e0, reference at CS:0x0006):
 *
 *   Offset  Field (MZ header)         Value
 *   ------  ------------------------  -----
 *   00      last_page_sz (bytes 2-3)  0x0171  (361 bytes in last 512-byte page)
 *   02      page_count   (bytes 4-5)  0x00a5  (165 pages = 84480 bytes rounded)
 *   04      reloc_count  (bytes 6-7)  0x0000  (no relocation entries)
 *   06      hdr_paras    (bytes 8-9)  0x0020  (32 paragraphs = 512-byte header)
 *   08      min_alloc    (bytes 10-11)0x5643  (required extra paragraphs)
 *   0a      max_alloc    (bytes 12-13)0xffff  (use all available memory)
 *   0c      SS           (bytes 14-15)0x143e  (stack segment, relative)
 *   0e      SP           (bytes 16-17)0x0521  (initial stack pointer)
 *   10      checksum     (bytes 18-19)0x0000
 *   12      IP           (bytes 20-21)0x0001  (initial instruction pointer)
 *   14      CS           (bytes 22-23)0x143e  (code segment, relative)
 *   16      reloc_tbl    (bytes 24-25)0x001e  (relocation table offset)
 *   18      overlay_num  (bytes 26-27)0x0000
 *   1a-1f   (reserved / LZEXE data)  0x01 0x00 0x00 0x00 0x00 0x00
 * ---------------------------------------------------------------------- */
static const uint8_t GAMEBIN_HDR_REF[32] = {
    /* last_page_sz  page_count   reloc_count  hdr_paras    */
    0x71, 0x01,  0xa5, 0x00,  0x00, 0x00,  0x20, 0x00,
    /* min_alloc     max_alloc    SS           SP            */
    0x43, 0x56,  0xff, 0xff,  0x3e, 0x14,  0x21, 0x05,
    /* checksum      IP           CS           reloc_tbl     */
    0x00, 0x00,  0x01, 0x00,  0x3e, 0x14,  0x1e, 0x00,
    /* overlay_num   LZEXE reserved                          */
    0x00, 0x00,  0x01, 0x00,  0x00, 0x00,  0x00, 0x00,
};

/*
 * GAMEBIN_READ_OFFSET -- byte offset within the EXE to start the 32-byte read.
 *
 * DOS: AH=3Fh with no preceding seek → reads from position 0.
 *      disassembly: 243e:0068-243e:0075
 *
 * The comparison reference starts at MZ byte 2, so the match begins at
 * read_buffer[2] vs GAMEBIN_HDR_REF[0].  The two-byte MZ magic is not
 * covered by the reference (it is assumed constant by LZEXE).
 *
 * RECOVER NEXT (step 3-2-iv): confirm via debugger whether the CMPSW
 * compares buffer[0..31] vs ref[0..31] (offset mismatch, always fails)
 * or buffer[2..33] vs ref[0..31] (offset-2 match, passes on unmodified EXE).
 */
#define GAMEBIN_READ_OFFSET   0          /* file position before AH=3Fh read */
#define GAMEBIN_READ_BYTES    32         /* CX=0x20 in AH=3Fh call           */
#define GAMEBIN_CMP_SKIP      2          /* MZ magic skipped in comparison    */

/*
 * GAMEBIN_EXPECTED_SIZE -- required file size in bytes.
 *
 * DOS: DX:AX from INT21h AX=0x4202 (seek to end) compared against
 *      CS:[BP+0x462] (hi word) and CS:[BP+0x460] (lo word).
 *      disassembly: 243e:0085-243e:009c  src/chess.c:16489
 *
 * Stored as DX:AX = 0x0001:0x4971 at CS:[BP+0x462]/[BP+0x460].
 * (CS file offset 0x145e0, BP+0x462 → CS:0x0365, BP+0x460 → CS:0x0363)
 * This equals 0x14971 = 84337 bytes -- the exact size of CHESS.EXE.orig.
 */
#define GAMEBIN_EXPECTED_SIZE  84337L    /* 0x14971 bytes */


/* =========================================================================
 * gamebin_check
 *
 * Original: inline in FUN_243e_0024
 *   src/chess.c:16481-16515   disassembly: 243e:0060-243e:00c0
 * ======================================================================= */
GamebinStatus gamebin_check(const char *path)
{
    /*
     * Path resolution:
     *   - NULL           → fall back to GAMEBIN_DEFAULT_PATH ("CHESS.EXE.orig")
     *   - any other path → use as-is (caller passes argv[0] after step 3-1)
     *
     * RECOVER NEXT (step 3-2-i): when args_parse() provides a real argv[0]
     * (e.g. "./battlechess"), strip to directory and append "CHESS.EXE.orig"
     * to derive the correct sibling path, mirroring the DOS PSP env scan
     * which always yielded the fully-qualified CHESS.EXE path.
     */
    if (!path) path = GAMEBIN_DEFAULT_PATH;

    /* ------------------------------------------------------------------
     * Block 1: open the game binary
     *
     * DOS original (disassembly: 243e:0060-243e:0067):
     *   MOV AL, 0x0      ; access = read-only
     *   MOV AH, 0x3d     ; open file
     *   INT 0x21         ; → BX = file handle
     *   (DX = path pointer from BP+0x434, filled by PSP env scan)
     *
     * RECOVER NEXT (step 3-2-i): derive path from args_parse() result
     * (the DOS PSP environment scan at 243e:003c-005a).
     * ------------------------------------------------------------------ */
    FILE *fp = fopen(path, "rb");
    if (!fp) {
        fprintf(stderr, "[gamebin] cannot open '%s': ", path);
        perror("");
        return GAMEBIN_ERROR;
    }

    /* ------------------------------------------------------------------
     * Block 2: read 32 bytes from file offset GAMEBIN_READ_OFFSET
     *
     * DOS original (disassembly: 243e:0068-243e:0075):
     *   MOV CX, 0x20     ; bytes to read
     *   MOV DX, BP+0x438 ; destination buffer
     *   MOV AH, 0x3f     ; read from file
     *   INT 0x21
     *   (no seek before read → reads from position 0)
     * ------------------------------------------------------------------ */
    uint8_t buf[GAMEBIN_READ_BYTES];
    if (fseek(fp, GAMEBIN_READ_OFFSET, SEEK_SET) != 0 ||
        fread(buf, 1, GAMEBIN_READ_BYTES, fp) != GAMEBIN_READ_BYTES) {
        fprintf(stderr, "[gamebin] read error on '%s'\n", path);
        fclose(fp);
        return GAMEBIN_ERROR;
    }

    /* ------------------------------------------------------------------
     * Block 3: get file size via seek to end
     *
     * DOS original (disassembly: 243e:0076-243e:0083):
     *   MOV AX, 0x4202   ; seek method = from end
     *   XOR CX, CX       ; offset high = 0
     *   XOR DX, DX       ; offset low  = 0
     *   INT 0x21         ; → DX:AX = file size in bytes
     *   PUSH AX          ; save low word
     *   MOV AH, 0x3e     ; close file
     *   INT 0x21
     *   POP AX           ; restore low word
     * ------------------------------------------------------------------ */
    if (fseek(fp, 0, SEEK_END) != 0) {
        fclose(fp);
        return GAMEBIN_ERROR;
    }
    long file_size = ftell(fp);
    fclose(fp);

    /* ------------------------------------------------------------------
     * Block 4: compare file size against expected
     *
     * DOS original (disassembly: 243e:0085-243e:009c  src/chess.c:16489):
     *   CMP DX, CS:[BP+0x462]   ; high word: 0x0001
     *   JA  → (above expected, continue)
     *   JZ  → check low word
     *   JMP → (below expected → set integrity flag)
     *   CMP AX, CS:[BP+0x460]   ; low word:  0x4971
     *   JZ  → (exact match, continue)
     *   JA  → (above expected, continue)
     *   JMP → (below expected → set integrity flag = 1)
     *
     * The flag (CS:[BP+0x433]) signals insufficient file size / tamper.
     * ------------------------------------------------------------------ */
    if (file_size < GAMEBIN_EXPECTED_SIZE) {
        fprintf(stderr,
            "[gamebin] file size %ld < expected %ld -- integrity flag set\n",
            file_size, (long)GAMEBIN_EXPECTED_SIZE);
        return GAMEBIN_MODIFIED;
    }

    /* ------------------------------------------------------------------
     * Block 5: compare 32-byte header against reference
     *
     * DOS original (disassembly: 243e:00a3-243e:00b9  src/chess.c:16489):
     *   MOV CX, 0x10             ; 16 words
     *   MOV SI, BP+0x438         ; source: read buffer
     *   MOV DI, CS:0x0006        ; dest:   32-byte reference
     *   PUSH DS / POP ES
     *   REPE CMPSW ES:DI, SI     ; compare word by word until mismatch
     *   JNZ → (mismatch → CPAV prompt)
     *   JMP → (match → normal startup)
     *
     * The reference at CS:0x0006 equals CHESS.EXE.orig[2:34].
     * The read buffer holds CHESS.EXE.orig[0:32] (from file offset 0).
     * The match therefore starts at buf[GAMEBIN_CMP_SKIP] vs ref[0],
     * comparing 30 bytes (the MZ magic in buf[0:2] has no counterpart
     * in the reference and is implicitly skipped).
     *
     * RECOVER NEXT (step 3-2-iv): confirm exact comparison semantics
     * with a DOS debugger trace -- specifically whether buf[0:2] is
     * compared against ref[0:2] or skipped entirely.
     * ------------------------------------------------------------------ */
    int match = (memcmp(buf + GAMEBIN_CMP_SKIP, GAMEBIN_HDR_REF,
                        GAMEBIN_READ_BYTES - GAMEBIN_CMP_SKIP) == 0);

    if (!match) {
        fprintf(stderr, "[gamebin] header mismatch -- CPAV integrity check failed\n");
        return GAMEBIN_MODIFIED;
    }

    printf("[gamebin] integrity OK (size=%ld, header matches)\n", file_size);
    return GAMEBIN_OK;
}
