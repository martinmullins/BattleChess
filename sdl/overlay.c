/*
 * sdl/overlay.c  --  Battle Chess overlay loader (recovery step 3b + 3c)
 *
 * Original source:
 *   src/chess.c      FUN_243e_0024 @ 243e:0024  (lines 16528-16606)
 *   decompiled/CHESS_disassembly.asm  243e:00be - 243e:022b
 *
 * --------------------------------------------------------------------------
 * DOS context (for reference)
 * --------------------------------------------------------------------------
 * The original Battle Chess EXE is LZEXE-compressed.  The stub decompressor
 * expands the code+data into a 401 KB image (CHESS_decompressed.bin).  The
 * startup segment (CS=0x243e in Ghidra's 0x1000-base view, actually 0x143e
 * relative to the MZ load base) contains a self-relocation routine that:
 *
 *   1. Scans real-mode paragraphs to find the overlay (step 3b / overlay_locate)
 *   2. Copies a 14-byte config block and walks the relocation table (step 3c / overlay_relocate)
 *   3. Far-jumps into the relocated game code
 *
 * SDL port strategy: CHESS_decompressed.bin IS the overlay image.  Instead of
 * scanning memory paragraphs, we load the file directly and verify the known
 * 4-word signature.  Instead of patching real-mode segment:offset pointers,
 * we compute flat addresses (segment*16 + offset) relative to a base pointer.
 * --------------------------------------------------------------------------
 */

#include "overlay.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* -------------------------------------------------------------------------
 * Overlay file
 * ---------------------------------------------------------------------- */
#define OVERLAY_FILE  "CHESS_decompressed.bin"

/* -------------------------------------------------------------------------
 * Signature constants
 *
 * The DOS scan loop (243e:00db-243e:00de) compared CX=4 words starting at
 * ES:[0x0006] against the 4 words stored in the startup data block at
 * CS:[BP+0x458..0x45f].  We extracted those 4 words from the actual binary:
 *
 *   CHESS_decompressed.bin offset 0x0006: 22 19 35 93 59 57 54 80
 *   As little-endian uint16: 0x1922  0x9335  0x5759  0x8054
 *
 * Original decompiled:  piVar15 = (int *)0x6;  iVar10 = 4;
 *                       CMPSW.REPE ES:DI, SI
 *   src/chess.c:16530, 16533, 16542
 *   disassembly: 243e:00c8-243e:00de
 * ---------------------------------------------------------------------- */
#define OVERLAY_SIG_OFFSET   0x0006u
#define OVERLAY_SIG_NWORDS   4

static const uint16_t OVERLAY_SIGNATURE[OVERLAY_SIG_NWORDS] = {
    0x1922,  /* overlay[0x06..0x07] -- also the relocation entry count */
    0x9335,  /* overlay[0x08..0x09] */
    0x5759,  /* overlay[0x0a..0x0b] */
    0x8054   /* overlay[0x0c..0x0d] */
};

/* -------------------------------------------------------------------------
 * Overlay header offsets  (all within the flat overlay image at index 0)
 *
 * In the DOS version these were accessed as DS:[SI + offset] where SI=0
 * after the scan loop placed DS at the found overlay segment.
 * ---------------------------------------------------------------------- */

/*
 * OVERLAY_RELOC_COUNT_OFFSET -- uint16 relocation entry count.
 *
 * DOS: MOV CX, word ptr [SI + 0x6]   (SI=0, DS=overlay segment)
 *      src/chess.c:16591  disassembly: 243e:01f2
 *
 * Verified: CHESS_decompressed.bin[0x0006] = 0x1922 = 6434 entries
 */
#define OVERLAY_RELOC_COUNT_OFFSET  0x0006u

/*
 * OVERLAY_RELOC_TABLE_OFFSET -- uint16 byte-offset of the relocation table.
 *
 * DOS: ADD SI, word ptr [SI + 0x18]   (sets SI = table start)
 *      src/chess.c:16593  disassembly: 243e:01fa
 *
 * Verified: CHESS_decompressed.bin[0x0018] = 0x56ec
 *           Table spans 0x56ec .. 0xbb74 (6434 * 4 bytes)
 */
#define OVERLAY_RELOC_TABLE_OFFSET  0x0018u

/*
 * OVERLAY_STORED_SEG_OFFSET -- uint16 original DOS load segment of overlay.
 *
 * DOS: MOV DX, word ptr CS:[BP + 0x47e]  ; stored_segment
 *      SUB AX, DX                         ; load_offset = CS(0x243e) - stored_seg
 *      src/chess.c:16579  disassembly: 243e:01c0, 243e:01c9
 *
 * RECOVER NEXT (step 3b-i): read this value from the startup data block
 * embedded at CS:[BP+0x47e] to compute the authentic load_offset.
 * For now we use 0 (identity offset, no patching) as a safe default.
 */
#define OVERLAY_STORED_SEG_OFFSET   0x047eu   /* offset within startup block */

/*
 * OVERLAY_DISPATCH_OFFSET -- uint16 far-jump entry point within overlay.
 *
 * DOS: JMPF CS:[BP + 0x474]
 *      src/chess.c:16605  disassembly: 243e:022b
 *
 * RECOVER NEXT (step 3c-ii): resolve this from the startup data block.
 */
#define OVERLAY_DISPATCH_OFFSET     0x0474u   /* offset within startup block */

/* -------------------------------------------------------------------------
 * Relocation entry layout
 *
 * Each entry is 4 bytes: (uint16 offset, uint16 segment) -- a DOS far pointer
 * to the word in the overlay that must have load_offset added to it.
 *
 * DOS fixup loop (src/chess.c:16594-16599  disassembly: 243e:01fd-243e:020a):
 *   ADD word ptr [SI + 0x2], AX      ; patch segment part of far ptr itself
 *   LES DI, [SI]                     ; load the far pointer
 *   ADD word ptr ES:[DI], AX         ; patch the pointed-to word
 *   ADD SI, 0x4                      ; advance to next entry
 *   LOOP ...
 *
 * In the SDL flat model we convert segment:offset → flat_base + seg*16 + off.
 * ---------------------------------------------------------------------- */
typedef struct {
    uint16_t offset;   /* near offset within the target segment */
    uint16_t segment;  /* segment (relative to overlay base) to patch */
} RelocEntry;


/* =========================================================================
 * overlay_locate
 *
 * Original: paragraph scan loop
 *   src/chess.c:16528-16545   disassembly: 243e:00be-243e:00df
 *
 * DOS behaviour:
 *   AX  = CS - stored_segment          (load_offset, computed before the loop)
 *   ES  = AX  (current probe segment)
 *   SI  = CS:[BP + 0x458]              (pointer to 4-word reference signature)
 *   DI  = 0x0006                       (fixed: compare from offset 6)
 *   CX  = 4
 *   CMPSW.REPE ES:DI, SI               (compare 4 words)
 *   INC AX  / CMP AX, 0xa000           (next paragraph; stop if AX wraps)
 *
 * SDL equivalent: load the file, verify the known 4-word signature.
 * ======================================================================= */
int overlay_locate(OverlayState *ov)
{
    if (!ov) return -1;
    memset(ov, 0, sizeof(*ov));

    /* ------------------------------------------------------------------
     * Block 1: open and read CHESS_decompressed.bin
     *
     * DOS equivalent: the overlay was already in memory (loaded by the
     * LZEXE decompressor stub in the first 0x200 bytes of CHESS.EXE.orig).
     * The paragraph scan searched starting from CS - stored_segment.
     *
     * RECOVER NEXT (step 3b-i): derive the path from argc/argv or a config
     * variable rather than hardcoding it, to support different install dirs.
     * ------------------------------------------------------------------ */
    FILE *fp = fopen(OVERLAY_FILE, "rb");
    if (!fp) {
        fprintf(stderr, "[overlay] cannot open '%s': ", OVERLAY_FILE);
        perror("");
        return -1;
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

    uint8_t *data = malloc((size_t)file_size);
    if (!data) {
        fprintf(stderr, "[overlay] out of memory (%ld bytes)\n", file_size);
        fclose(fp);
        return -1;
    }

    if (fread(data, 1, (size_t)file_size, fp) != (size_t)file_size) {
        fprintf(stderr, "[overlay] read error on '%s'\n", OVERLAY_FILE);
        fclose(fp);
        free(data);
        return -1;
    }
    fclose(fp);

    /* ------------------------------------------------------------------
     * Block 2: verify the 4-word signature at offset 0x0006
     *
     * DOS equivalent: CMPSW.REPE CX=4 at ES:[0x0006] vs CS:[BP+0x458]
     *   src/chess.c:16530, 16533, 16542
     *   disassembly: 243e:00c8-243e:00de
     *
     * The signature words are the first 4 uint16 values starting at
     * overlay byte 6: 0x1922, 0x9335, 0x5759, 0x8054
     * (verified from CHESS_decompressed.bin with Python).
     *
     * RECOVER NEXT (step 3b-ii): if supporting different game versions,
     * read the reference signature from a version table rather than the
     * compile-time constants above.
     * ------------------------------------------------------------------ */
    if ((size_t)file_size < OVERLAY_SIG_OFFSET + OVERLAY_SIG_NWORDS * 2) {
        fprintf(stderr, "[overlay] file too small to contain signature\n");
        free(data);
        return -1;
    }

    for (int i = 0; i < OVERLAY_SIG_NWORDS; i++) {
        uint16_t word;
        memcpy(&word, data + OVERLAY_SIG_OFFSET + i * 2, 2);
        if (word != OVERLAY_SIGNATURE[i]) {
            fprintf(stderr,
                "[overlay] signature mismatch at word %d: "
                "got 0x%04x expected 0x%04x\n",
                i, word, OVERLAY_SIGNATURE[i]);
            free(data);
            return -1;
        }
    }
    printf("[overlay] signature OK\n");

    /* ------------------------------------------------------------------
     * Block 3: read relocation metadata from the overlay header
     *
     * DOS equivalent (src/chess.c:16591-16593  243e:01f2-243e:01fa):
     *   CX = word ptr [SI + 0x6]      ; reloc entry count
     *   ADD SI, word ptr [SI + 0x18]  ; SI → reloc table
     * ------------------------------------------------------------------ */
    uint16_t reloc_count, reloc_table;
    memcpy(&reloc_count, data + OVERLAY_RELOC_COUNT_OFFSET, 2);
    memcpy(&reloc_table,  data + OVERLAY_RELOC_TABLE_OFFSET,  2);

    printf("[overlay] reloc entries: %u  table offset: 0x%04x\n",
           reloc_count, reloc_table);

    /* Bounds check: table must fit inside the file */
    size_t table_end = (size_t)reloc_table + (size_t)reloc_count * sizeof(RelocEntry);
    if (table_end > (size_t)file_size) {
        fprintf(stderr, "[overlay] reloc table extends past end of file\n");
        free(data);
        return -1;
    }

    /* ------------------------------------------------------------------
     * Block 4: compute load_offset
     *
     * DOS: AX = CS - stored_segment  (CS=0x243e at runtime)
     *   src/chess.c:16579  disassembly: 243e:01c9
     *
     * RECOVER NEXT (step 3b-i): read stored_segment from the startup data
     * block (at CS:[BP+0x47e]) once that block is parsed.  For now, use 0
     * (identity) -- relocation patches will be no-ops until this is set.
     * ------------------------------------------------------------------ */
    uint16_t stored_seg   = 0;   /* RECOVER NEXT: parse from startup block */
    uint16_t load_offset  = 0;   /* RECOVER NEXT: = CS(0x243e) - stored_seg */

    ov->data         = data;
    ov->size         = (size_t)file_size;
    ov->load_offset  = load_offset;
    ov->stored_seg   = stored_seg;
    ov->reloc_count  = reloc_count;
    ov->reloc_table  = reloc_table;
    ov->dispatch_off = 0;   /* RECOVER NEXT: parse from startup block */

    return 0;
}


/* =========================================================================
 * overlay_relocate
 *
 * Original: config-copy + pointer-fixup loop + far-jump
 *   src/chess.c:16578-16606   disassembly: 243e:01c0-243e:022b
 *
 * DOS behaviour:
 *   LAB_243e_01c0:
 *     ES = load_offset
 *     REP MOVSB  14 bytes from CS:[BP+0x466] → ES:0x0000  (config copy)
 *
 *     DS = CS - reloc_segment                               (243e:01e4-01eb)
 *     CX = DS:[SI+0x6]                                     (243e:01f2)
 *     ADD SI, DS:[SI+0x18]  (SI now → reloc table)         (243e:01fa)
 *     loop:
 *       ADD  word ptr [SI+0x2], ES   ; patch segment word in entry  (243e:01ff)
 *       LES  DI, [SI]                ; follow far ptr               (243e:0202)
 *       ADD  word ptr ES:[DI], ES    ; patch target word            (243e:0204)
 *       ADD  SI, 0x4                                                (243e:0207)
 *     ADD  CS:[BP+0x476], AX         ; fix up stack offset          (243e:020e)
 *     JMPF CS:[BP+0x474]             ; dispatch into game           (243e:022b)
 *
 * SDL equivalent: for each reloc entry, compute the flat byte offset of the
 * target word and add load_offset to it.
 * ======================================================================= */
int overlay_relocate(OverlayState *ov)
{
    if (!ov || !ov->data) return -1;

    /* ------------------------------------------------------------------
     * Block 1: 14-byte config copy
     *
     * DOS: REP MOVSB  CX=0xe  SI=CS:[BP+0x466]  DI=0  ES=load_offset
     *   src/chess.c:16580-16588  disassembly: 243e:01cd-243e:01d9
     *
     * In DOS, 14 bytes from the startup segment's data block were copied
     * to offset 0 in the overlay segment.  Those bytes set up the overlay's
     * own header (entry point, stack values, etc.).
     *
     * RECOVER NEXT (step 3c-i): once the startup data block is parsed,
     * copy the 14-byte field at BP+0x466 into ov->data[0..13].
     * ------------------------------------------------------------------ */
    printf("[overlay] config copy: stub (startup block not yet parsed)\n");
    /* RECOVER NEXT (step 3c-i):
     * memcpy(ov->data, startup_block + 0x466, 14);
     */

    /* ------------------------------------------------------------------
     * Block 2: relocation table walk
     *
     * DOS inner loop (src/chess.c:16594-16599  disassembly: 243e:01fd-243e:020a):
     *   Each entry = { uint16 offset, uint16 segment }.
     *   "segment" is the overlay segment (relative to overlay base) that
     *   contains the far pointer to fix up.
     *   "offset"  is the byte offset within that segment.
     *
     * The fixup:
     *   entry.segment += load_offset            (patch the entry itself)
     *   target = &overlay[entry.segment * 16 + entry.offset]
     *   *(uint16_t *)target += load_offset      (patch the pointed-to word)
     *
     * RECOVER NEXT (step 3c-ii): uncomment once load_offset is computed
     * correctly from the startup data block (step 3b-i).
     * ------------------------------------------------------------------ */
    printf("[overlay] reloc walk: stub (load_offset=0x%04x, %u entries at 0x%04x)\n",
           ov->load_offset, ov->reloc_count, ov->reloc_table);

    /* RECOVER NEXT (step 3c-ii):
    if (ov->load_offset == 0) {
        printf("[overlay] load_offset is 0 -- skipping relocation (no-op)\n");
    } else {
        const uint8_t *table = ov->data + ov->reloc_table;
        for (uint16_t i = 0; i < ov->reloc_count; i++) {
            RelocEntry e;
            memcpy(&e, table + i * sizeof(RelocEntry), sizeof(RelocEntry));

            // Patch the segment word stored in the reloc entry itself
            // (mirrors: ADD word ptr [SI+0x2], AX  at 243e:01ff)
            e.segment += ov->load_offset;

            // Compute flat byte offset of the target word in the overlay
            // (mirrors: LES DI, [SI]  then  ADD word ptr ES:[DI], AX  at 243e:0202-0204)
            size_t flat = (size_t)e.segment * 16 + e.offset;
            if (flat + 2 > ov->size) {
                fprintf(stderr, "[overlay] reloc entry %u out of bounds (flat=0x%zx)\n", i, flat);
                return -1;
            }
            uint16_t val;
            memcpy(&val, ov->data + flat, 2);
            val += ov->load_offset;
            memcpy(ov->data + flat, &val, 2);
        }
        printf("[overlay] patched %u reloc entries\n", ov->reloc_count);
    }
    */

    /* ------------------------------------------------------------------
     * Block 3: entry point dispatch
     *
     * DOS: ADD CS:[BP+0x476], AX   ; fix stack SP         (243e:020e)
     *      JMPF CS:[BP+0x474]      ; far-jump into game   (243e:022b)
     *   src/chess.c:16602-16605
     *
     * RECOVER NEXT (step 3c-iii): after relocation is complete, set
     * ov->dispatch_off from the startup data block at BP+0x474 and
     * call the appropriate game-init function.
     * ------------------------------------------------------------------ */
    printf("[overlay] dispatch: stub (entry point not yet resolved)\n");
    /* RECOVER NEXT (step 3c-iii):
     * void (*game_entry)(void) = (void(*)(void))(ov->data + ov->dispatch_off);
     * game_entry();
     */

    return 0;
}
