/*
 * sdl/save.c  --  Battle Chess CPAV startup gate (recovery step 3a)
 *
 * Original source:
 *   src/chess.c          FUN_243e_0230 @ 243e:0230   (lines 16639-16858)
 *   CHESS_disassembly.asm  243e:0230-243e:0265
 *
 * --------------------------------------------------------------------------
 * Correction note
 * --------------------------------------------------------------------------
 * The initial stub in this file (based on Ghidra's C decompilation) was
 * named save_file_probe() and treated FUN_243e_0230 as a file-open/read
 * sequence.  The disassembly proved this wrong:
 *
 *   Ghidra (src/chess.c:16688-16696): showed four swi(0x21) calls in a
 *     do-while loop with the first byte tested as a "file type tag".
 *   Reality (243e:0230-243e:0237): MOV AH,9 + INT 21h (print string),
 *     MOV AH,1 + INT 21h (read char), MOV AH,2 + INT 21h x2 (write CR/LF).
 *
 * Ghidra's decompiler was confused by the overlapping-instruction warnings
 * at this address and the many "removing unreachable block" entries.
 * The disassembly is authoritative.
 *
 * The function is the CPAV (Central Point Anti-Virus) integrity-check menu.
 * Its body is now in sdl/cpav.c as cpav_prompt().
 * --------------------------------------------------------------------------
 */

#include "save.h"
#include "cpav.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * save_file_probe  (name retained for startup.c API compatibility)
 *
 * Wraps cpav_prompt() and maps its result to the three paths that
 * FUN_243e_0230's dispatch leads to in FUN_243e_0024:
 *
 *   CPAV_RESTORE   ('w'/'W') → return 0  (caller continues normally)
 *                              disassembly: 243e:0265  RET
 *
 *   CPAV_CONTINUE  ('f'/'F') → return 0  (caller triggers overlay dispatch)
 *                              disassembly: 243e:0267  JMP → LAB_243e_01c0
 *                              RECOVER NEXT (step 3a-ii): signal to startup.c
 *                              that an explicit overlay re-dispatch is needed.
 *
 *   CPAV_QUIT      ('b'/'B') → exit(1)   (mirrors DOS INT 21h AH=4Ch, code 1)
 *                              disassembly: 243e:026a-243e:026d
 *
 * Original: FUN_243e_0230 @ src/chess.c:16639   disassembly: 243e:0230
 */
int save_file_probe(void)
{
    CpavResult result = cpav_prompt();

    switch (result) {

    case CPAV_RESTORE:
        /*
         * 'w'/'W' -- Wiederherstellung (restore)
         * DOS: RET  (disassembly: 243e:0265)
         * Return to caller; startup continues normally.
         */
        return 0;

    case CPAV_CONTINUE:
        /*
         * 'f'/'F' -- Programm fortsetzen (continue despite change)
         * DOS: JMP → LAB_243e_01c0 (overlay reloc + far-jump dispatch)
         *      disassembly: 243e:0267
         *
         * RECOVER NEXT (step 3a-ii): propagate this as a distinct return
         * code so startup.c can call overlay_relocate() + dispatch directly,
         * rather than re-running the whole startup sequence.
         *
         * For now, fall through to normal return; the overlay is already
         * loaded and will be dispatched in the normal flow.
         */
        fprintf(stderr, "[save] CPAV: user chose to continue despite change\n");
        return 0;

    case CPAV_QUIT:
        /*
         * 'b'/'B' -- Beenden (exit)
         * DOS: MOV AX, 0x4c01 / INT 21h  (exit code 1)
         *      disassembly: 243e:026a-243e:026d
         */
        fprintf(stderr, "[save] CPAV: user chose to exit\n");
        exit(1);

    default:
        return 0;
    }
}
