/*
 * sdl/startup.c  --  Battle Chess startup / initialisation (recovery step 3)
 *
 * Original source: src/chess.c, FUN_243e_0024 @ 243e:0024
 *                  decompiled/CHESS_disassembly.asm  243e:0024-243e:022b
 *
 * The DOS function did the following in order:
 *   1. Scan the PSP command tail for arguments   (src/chess.c:16469-16480)
 *                                                (disassembly: 243e:003e-243e:005a)
 *   2. Open save file; read 32-byte header;      (src/chess.c:16481-16488)
 *      seek to end for file size                 (disassembly: 243e:0060-243e:0083)
 *   3. Compare file size vs required and         (src/chess.c:16489-16515)
 *      set a low-memory/short-file flag          (disassembly: 243e:0085-243e:009c)
 *   4. Call FUN_243e_0230 -- startup prompt      (src/chess.c:16516-16527)
 *      (print menu, read key: w/f/b dispatch)    (disassembly: 243e:00be)
 *   5. Locate the overlay by paragraph scan      (src/chess.c:16528-16545)
 *      (CMPSW 4-word sig at ES:[6] vs ref)       (disassembly: 243e:00c8-243e:00df)
 *   6. Copy 14 bytes of overlay config to seg 0  (src/chess.c:16580-16588)
 *                                                (disassembly: 243e:01cd-243e:01d9)
 *   7. Relocate internal segment pointers        (src/chess.c:16589-16606)
 *      and far-jump into game code               (disassembly: 243e:01fa-243e:022b)
 *
 * Each numbered block below maps to one future recovery sub-step.
 * Uncomment the block when that sub-system has been ported.
 */

#include "startup.h"
#include "save.h"
#include "overlay.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* =========================================================================
 * chess_startup
 *
 * Original: FUN_243e_0024() -- src/chess.c:16440  disassembly: 243e:0024
 * ======================================================================= */
int chess_startup(SDL_Renderer *renderer, int argc, char *argv[])
{
    (void)renderer;

    /* ------------------------------------------------------------------
     * Block 1: command-line argument parsing
     *
     * DOS original (src/chess.c:16469-16480  disassembly: 243e:003e-243e:005a):
     *   ES = word ptr ES:[0x2c]        ; ES → environment segment (from PSP)
     *   SCASB.REPNE  looking for \0    ; skip env strings
     *   CMP byte ptr ES:[DI], 0x0      ; double-NUL = end of env block
     *   ADD DI, 0x3                    ; skip the word count + first char
     *   MOV word ptr CS:[BP+0x434], DI ; save pointer to command tail
     *
     * RECOVER NEXT (step 3-1): parse argc/argv for the same flags the
     * DOS version accepted (e.g. difficulty level, player side).
     *
     * const char *arg_difficulty = NULL;
     * for (int i = 1; i < argc; i++) {
     *     if (strcmp(argv[i], "-easy") == 0) arg_difficulty = argv[i];
     * }
     * ------------------------------------------------------------------ */
    (void)argc;
    (void)argv;
    printf("[startup] arg parse: stub\n");


    /* ------------------------------------------------------------------
     * Block 2: save-file open + size check
     *
     * DOS original (src/chess.c:16481-16515  disassembly: 243e:0060-243e:009c):
     *   AH=0x3d / INT 21h  -- open file (name from BP+0x434)
     *   AH=0x3f / INT 21h  -- read 0x20 (32) bytes into BP+0x438
     *   AX=0x4202/ INT 21h -- seek to end (get file size in DX:AX)
     *   AH=0x3e / INT 21h  -- close file
     *   CMP DX, CS:[BP+0x462]  ; compare size high word vs required
     *   CMP AX, CS:[BP+0x460]  ; compare size low  word vs required
     *   If size < required: MOV byte ptr CS:[BP+0x433], 0x1  (low-mem flag)
     *
     * RECOVER NEXT (step 3-2): open save file via fopen; fread 32 bytes;
     * fseek/ftell for size; compare against required minimum.
     *
     * FILE *sf = fopen(SAVE_FILE_NAME, "rb");
     * if (sf) {
     *     uint8_t hdr[32]; fread(hdr, 1, 32, sf);
     *     fseek(sf, 0, SEEK_END); long sz = ftell(sf); fclose(sf);
     *     // compare sz against required (stored in startup data block)
     * }
     * ------------------------------------------------------------------ */
    printf("[startup] save-file size check: stub\n");


    /* ------------------------------------------------------------------
     * Block 3: startup prompt  (FUN_243e_0230)
     *
     * DOS original (src/chess.c:16516-16527  disassembly: 243e:00be):
     *   CALL FUN_243e_0230
     *   That function:
     *     AH=0x9  / INT 21h  -- print prompt string at CS:[BP+0x36e]
     *     AH=0x1  / INT 21h  -- read keystroke with echo → AL
     *     AH=0x2  / INT 21h  -- write LF (0x0a) + CR (0x0d)
     *     Dispatch on AL: 'w'/'W' → return, 'f'/'F' → overlay reload,
     *                     'b'/'B' → sound init, else → loop
     *   (disassembly: 243e:0230-243e:0264  src/chess.c:16639)
     *
     * Note: this was initially named save_file_probe in save.c based on
     * Ghidra's decompilation; the disassembly clarifies it is a prompt menu.
     *
     * save_file_probe() is now in sdl/save.c -- step 3a wired up.
     * ------------------------------------------------------------------ */
    save_file_probe();   /* step 3a: runs stubs, safe to call now */


    /* ------------------------------------------------------------------
     * Block 4: overlay locate -- step 3b wired up (sdl/overlay.c)
     *
     * DOS original (src/chess.c:16528-16545  disassembly: 243e:00c8-243e:00df):
     *   AX = CS - stored_segment        ; load_offset
     *   ES = AX  (probe segment)
     *   DI = 0x6
     *   SI = CS:[BP+0x458]              ; 4-word reference signature
     *   CX = 4
     *   CMPSW.REPE  ES:DI, SI           ; compare at ES:[6]
     *   INC AX / CMP AX, 0xa000        ; next paragraph / bounds check
     *
     * ------------------------------------------------------------------ */
    OverlayState ov;
    if (overlay_locate(&ov) != 0) {
        fprintf(stderr, "[startup] overlay not found\n");
        return -1;
    }


    /* ------------------------------------------------------------------
     * Block 5: overlay relocation -- step 3c wired up (sdl/overlay.c)
     *
     * DOS original (src/chess.c:16578-16606  disassembly: 243e:01c0-243e:022b):
     *   REP MOVSB  14 bytes → ES:0      ; config copy
     *   Walk reloc table: ADD [SI+2],AX ; fix segment word in entry
     *                     LES DI,[SI]   ; follow far ptr
     *                     ADD ES:[DI],AX; fix target word
     *                     ADD SI,4      ; next entry
     *   ADD CS:[BP+0x476], AX           ; fix up stack
     *   JMPF CS:[BP+0x474]             ; dispatch
     *
     * ------------------------------------------------------------------ */
    if (overlay_relocate(&ov) != 0) {
        fprintf(stderr, "[startup] overlay relocation failed\n");
        free(ov.data);
        return -1;
    }

    /* RECOVER NEXT: free ov.data only when the game is done using it,
     * not here.  For now it is leaked (safe while stubs are in place). */

    return 0;
}
