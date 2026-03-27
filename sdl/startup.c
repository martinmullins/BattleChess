/*
 * sdl/startup.c  --  Battle Chess startup / initialisation (recovery step 3)
 *
 * Original source: src/chess.c, FUN_243e_0024 @ 243e:0024
 *                  decompiled/CHESS_disassembly.asm  243e:0024-243e:022b
 *
 * The DOS function did the following in order:
 *   1. Scan the PSP command tail for arguments   (src/chess.c:16469-16480)
 *                                                (disassembly: 243e:003e-243e:005a)
 *   2. Open CHESS.EXE; read 32-byte MZ header;   (src/chess.c:16481-16488)
 *      seek to end for file size                 (disassembly: 243e:0060-243e:0083)
 *   3. Compare header + size vs reference and    (src/chess.c:16489-16515)
 *      set integrity/tamper flag if mismatch     (disassembly: 243e:0085-243e:00c0)
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
#include "args.h"
#include "save.h"
#include "gamebin.h"
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
     * Block 1: command-line argument parsing -- step 3-1 wired (sdl/args.c)
     *
     * DOS original (src/chess.c:16469-16480  disassembly: 243e:003e-243e:005b):
     *   ES = word ptr ES:[0x2c]           ; ES → environment segment (PSP)
     *   SCASB.REPNE  looking for \0       ; skip NUL-terminated env strings
     *   CMP byte ptr ES:[DI], 0x0         ; double-NUL = end of env block
     *   ADD DI, 0x3                       ; skip count word + first char
     *   MOV word ptr CS:[BP + 0x434], DI  ; save exe-path offset (CS:0x0337)
     *
     * args_parse() extracts argv[0] as the exe-path equivalent of the saved
     * CS:[BP+0x434] pointer, and stores it in args.exe_path for forwarding
     * to gamebin_check() (step 3-2-i) and overlay_locate() (step 3b-i).
     * ------------------------------------------------------------------ */
    ArgsState args;
    if (args_parse(&args, argc, argv) != 0) {
        fprintf(stderr, "[startup] args_parse failed\n");
        return -1;
    }


    /* ------------------------------------------------------------------
     * Block 2: game-binary integrity check -- step 3-2 wired (sdl/gamebin.c)
     *
     * DOS original (src/chess.c:16481-16515  disassembly: 243e:0060-243e:00c0):
     *   Path found by PSP env scan → CS:[BP+0x434]  (243e:003c-005a)
     *   AH=0x3d / INT 21h   open CHESS.EXE            (243e:0060-0067)
     *   AH=0x3f / INT 21h   read 32 bytes → BP+0x438  (243e:0068-0075)
     *   AX=0x4202/ INT 21h  seek to end → DX:AX size  (243e:0076-007c)
     *   AH=0x3e / INT 21h   close file                 (243e:007d-0083)
     *   CMP DX, CS:[BP+0x462]  compare size hi word    (243e:0085)
     *   CMP AX, CS:[BP+0x460]  compare size lo word    (243e:0091)
     *   → set CS:[BP+0x433]=1 if mismatch              (243e:009d)
     *   CMPSW.REPE CX=16 SI=BP+0x438 DI=CS:0x0006      (243e:00b7)
     *   → jump to CPAV prompt if mismatch              (243e:00b9)
     *
     * args.exe_path (from step 3-1 / args_parse) is passed as the path so
     * that the file opened here matches the running binary, mirroring the
     * DOS PSP env scan that stored the path at CS:[BP+0x434].
     *
     * RECOVER NEXT (step 3-2-i): gamebin_check() derives the CHESS.EXE.orig
     * path from args.exe_path once the path-construction logic is clear.
     * ------------------------------------------------------------------ */
    {
        GamebinStatus gbs = gamebin_check(args.exe_path);
        if (gbs == GAMEBIN_MODIFIED) {
            /* Integrity mismatch -- mirrors CS:[BP+0x433] = 1 path.
             * In DOS this triggers the CPAV prompt (FUN_243e_0230) which
             * is already called in Block 3 via save_file_probe().
             * No extra action needed here; the prompt handles dispatch.
             * src/chess.c:16491  disassembly: 243e:009d */
            fprintf(stderr, "[startup] CPAV flag set (binary modified or missing)\n");
        } else if (gbs == GAMEBIN_ERROR) {
            fprintf(stderr, "[startup] game binary not found -- CPAV check skipped\n");
        }
        /* GAMEBIN_OK: fall through, CPAV prompt skipped in DOS (243e:0173) */
    }


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
