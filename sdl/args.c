/*
 * sdl/args.c  --  command-line / PSP environment argument parsing (recovery step 3-1)
 *
 * Original source:
 *   src/chess.c          FUN_243e_0024 @ 243e:0024  (lines 16469-16480)
 *   CHESS_disassembly.asm  243e:003e - 243e:005b
 *
 * --------------------------------------------------------------------------
 * DOS context
 * --------------------------------------------------------------------------
 * Before running any game code, FUN_243e_0024 locates the program's own
 * fully-qualified path.  DOS stores this after the environment block in the
 * Program Segment Prefix (PSP).  The layout is:
 *
 *   Environment segment (pointed to by word at PSP:0x2c):
 *     NUL-terminated strings: "VAR=value\0VAR2=value2\0...\0\0"
 *     2-byte program-filename count word  (always 0x0001 for a single name)
 *     Fully-qualified program path string (e.g. "C:\CHESS\CHESS.EXE\0")
 *
 * The startup code:
 *   MOV  ES, word ptr ES:[0x2c]     ; ES → environment segment  243e:0037
 *   PUSH ES / POP DS                ; DS = ES                   243e:003c
 *   MOV  CX, 0x1000                 ; scan limit                243e:003e
 *   MOV  DI, 0x0                    ; start offset              243e:0041
 *   ; --- loop: skip one NUL-terminated string ---
 *   SCASB.REPNE  ES:DI              ; scan for NUL              243e:004e
 *   CMP  byte ptr ES:[DI], 0x0      ; double-NUL? (end of env)  243e:0050
 *   JNZ  → loop-start              ; no → skip next string      243e:0054
 *   ; --- landed at double-NUL ---
 *   ADD  DI, 0x3                    ; skip count word + 1 byte  243e:0056
 *   MOV  word ptr CS:[BP + 0x434], DI  ; save exe-path offset   243e:005b
 *
 * The saved offset (CS:[BP+0x434] = CS:0x0337) is later used as the path
 * argument to INT 21h AH=3Dh (open file) at 243e:0064 and as the DX
 * argument to INT 21h AX=4301h (set attributes) at 243e:00f3.
 *
 * In the SDL flat-model port, argv[0] is the direct equivalent.
 *
 * --------------------------------------------------------------------------
 * Step 3-1 scope
 * --------------------------------------------------------------------------
 * This step wires up the minimum needed to replace the stub in startup.c
 * Block 1 and propagate argv[0] to gamebin_check() and overlay_locate().
 * Full flag parsing (step 3-1-ii) is deferred until the flags themselves
 * are identified in the disassembly.
 * --------------------------------------------------------------------------
 */

#include "args.h"
#include <stdio.h>
#include <string.h>

/* =========================================================================
 * args_parse
 *
 * Original: inline in FUN_243e_0024
 *   src/chess.c:16469-16480   disassembly: 243e:003e-243e:005b
 * ======================================================================= */
int args_parse(ArgsState *out, int argc, char *argv[])
{
    /* ------------------------------------------------------------------
     * Block 1: locate the program path
     *
     * DOS original (disassembly: 243e:0037-243e:005b):
     *   ES = word ptr ES:[0x2c]         ; env segment from PSP
     *   CX = 0x1000                     ; scan limit
     *   DI = 0x0                        ; start offset
     *   SCASB.REPNE  ES:DI              ; skip NUL-terminated env strings
     *   CMP byte ptr ES:[DI], 0x0       ; check for double-NUL
     *   JNZ → loop                      ; repeat if not at end
     *   ADD DI, 0x3                     ; skip count word (2 bytes) + 1 char
     *   MOV word ptr CS:[BP + 0x434], DI ; save ptr to exe path
     *
     * In the SDL port argv[0] is the flat equivalent of that saved pointer.
     * ------------------------------------------------------------------ */
    if (argc < 1 || !argv || !argv[0]) {
        fprintf(stderr, "[args] no argv[0] -- cannot determine exe path\n");
        out->exe_path = NULL;
        return -1;
    }

    out->exe_path = argv[0];
    printf("[args] exe path: %s\n", out->exe_path);


    /* ------------------------------------------------------------------
     * Block 2: command-tail flag scan
     *
     * DOS original (src/chess.c:16469-16480  disassembly: 243e:003e-243e:005a):
     *   The disassembly shows no explicit flag dispatch in this range;
     *   the scan locates the exe-path only.  Any game flags would be in
     *   the PSP command tail at PSP:0x81 (length byte at PSP:0x80), which
     *   is a separate area not accessed in this function.
     *
     * RECOVER NEXT (step 3-1-ii): once the disassembly reveals that the
     * game reads PSP:0x81, add flag parsing here:
     *
     *   for (int i = 1; i < argc; i++) {
     *       if (strcmp(argv[i], "-easy") == 0)     out->flag_easy    = 1;
     *       else if (strcmp(argv[i], "-hard") == 0) out->flag_hard   = 1;
     *       else fprintf(stderr, "[args] unknown flag: %s\n", argv[i]);
     *   }
     * ------------------------------------------------------------------ */
    (void)argc;   /* argv[1..] not yet parsed -- see RECOVER NEXT above */

    return 0;
}
