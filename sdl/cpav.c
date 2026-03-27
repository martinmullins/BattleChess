/*
 * sdl/cpav.c  --  Central Point Anti-Virus integrity prompt (recovery step 3a)
 *
 * Original source:
 *   src/chess.c          FUN_243e_0230 @ 243e:0230   (lines 16639-16858)
 *   CHESS_disassembly.asm  243e:0230-243e:0265
 *
 * --------------------------------------------------------------------------
 * DOS context
 * --------------------------------------------------------------------------
 * Battle Chess 1991 (Interplay) embedded a Central Point Anti-Virus (CPAV)
 * integrity check.  On startup, FUN_243e_0024 compares the game's own EXE
 * header against stored reference values; if they differ it calls
 * FUN_243e_0230 which displays this menu and reads a keystroke:
 *
 *   \rCentral Point Anti-Virus (c) 1991 CPS
 *   Integritätstest Warnung - Datei wurde geändert !
 *   Bitte eingeben:
 *   [W] Wiederherstellung        <- restore EXE from CPAV backup
 *   [F] Programm fortsetzen      <- run despite modification
 *   [B] Beenden                  <- exit
 *   W,F o B drücken
 *
 * Prompt string: CHESS.EXE.orig file offset 0x14851..0x14912 (194 bytes),
 * '$'-terminated (DOS AH=9 convention), CP437 encoding.
 * Extracted from: CS:0x0271 (with CS file offset 0x145e0, BP=0xFF03)
 *
 * Dispatch (disassembly: 243e:024b-243e:0265  src/chess.c:16699-16731):
 *   'w'/'W' (0x77/0x57) → RET               (Wiederherstellung / restore)
 *   'f'/'F' (0x66/0x46) → JMP overlay-reloc  (Programm fortsetzen / continue)
 *   'b'/'B' (0x62/0x42) → INT 21h AH=4Ch    (Beenden / quit, exit code 1)
 *   else                → JMP loop-start     (retry)
 * --------------------------------------------------------------------------
 */

#include "cpav.h"
#include <stdio.h>
#include <string.h>

/* -------------------------------------------------------------------------
 * Prompt string (CP437, reproduced verbatim from CHESS.EXE.orig:0x14851)
 *
 * Original: DOS '$'-terminated string at CS:[BP+0x36e] after ADD DX,BP
 *           MOV AH,9 / MOV DX,0x36e / ADD DX,BP / INT 21h
 *           disassembly: 243e:0230-243e:0237
 *
 * \x84 = CP437 'ä'  (ä in "Integritätstest", "geändert")
 * \x81 = CP437 'ü'  (ü in "drücken")
 * The original used CR+LF in reverse order (\n\r) as printed by DOS;
 * we normalise to \r\n for terminal output.
 * ---------------------------------------------------------------------- */
static const char CPAV_PROMPT[] =
    "\r\n"
    "Central Point Anti-Virus (c) 1991 CPS\r\n"
    "Integrit\xc3\xa4tstest Warnung - Datei wurde ge\xc3\xa4ndert !\r\n"
    /* ^^ 0x84→ä, 0x84→ä converted to UTF-8 \xc3\xa4 for terminal display */
    "Bitte eingeben:\r\n"
    "[W] Wiederherstellung\r\n"     /* restore from CPAV backup    */
    "[F] Programm fortsetzen\r\n"  /* continue despite change     */
    "[B] Beenden\r\n"              /* exit                        */
    "W,F o B dr\xc3\xbc" "cken: ";   /* 0x81→ü split to avoid \xbcc ambiguity */


/* =========================================================================
 * cpav_prompt
 *
 * Original: FUN_243e_0230 @ src/chess.c:16639   disassembly: 243e:0230
 * ======================================================================= */
CpavResult cpav_prompt(void)
{
    for (;;) {
        /* ------------------------------------------------------------------
         * Block 1: display the prompt string
         *
         * DOS original (disassembly: 243e:0230-243e:0237):
         *   MOV AH, 0x9              ; DOS print string
         *   MOV DX, 0x36e            ; string near-offset
         *   ADD DX, BP               ; BP=0xFF03 → DX = 0x0271 in CS
         *   INT 0x21                 ; print until '$'
         *
         * The string lives at CHESS.EXE.orig file offset 0x14851 (194 bytes).
         * CP437 extended chars (0x84=ä, 0x81=ü) are emitted as UTF-8 above
         * for modern terminal compatibility.
         *
         * RECOVER NEXT (step 3a-i): render this text as an SDL2 overlay
         * surface using SDL_ttf, positioned in the centre of the window,
         * replacing the fputs() call below.
         * ------------------------------------------------------------------ */
        fputs(CPAV_PROMPT, stderr);

        /* ------------------------------------------------------------------
         * Block 2: read a single keystroke
         *
         * DOS original (disassembly: 243e:0239-243e:024a):
         *   MOV AH, 0x1    ; DOS read char with echo
         *   INT 0x21       ; → AL = ASCII keycode
         *   PUSH AX
         *   MOV AH, 0x2  \ ; write LF then CR
         *   MOV DL, 0x0a  |
         *   INT 0x21       |
         *   MOV AH, 0x2  |
         *   MOV DL, 0x0d  |
         *   INT 0x21      /
         *   POP AX         ; restore keycode
         *
         * RECOVER NEXT (step 3a-ii): replace fgetc(stdin) with an SDL2
         * event loop that polls SDL_KEYDOWN events and maps SDL_Keycode
         * values to the expected ASCII chars ('w','f','b').
         *
         * SDL_Event ev;
         * while (SDL_WaitEvent(&ev)) {
         *     if (ev.type == SDL_KEYDOWN) {
         *         key = (char)ev.key.keysym.sym;
         *         break;
         *     }
         * }
         * ------------------------------------------------------------------ */
        int raw = fgetc(stdin);
        if (raw == EOF) {
            /* EOF on stdin (e.g. piped /dev/null): treat as Beenden */
            fprintf(stderr, "\n");
            return CPAV_QUIT;
        }
        char key = (char)raw;

        /* Echo LF+CR, mirroring: MOV AH,2 / MOV DL,0x0a / INT 21 /
         *                         MOV AH,2 / MOV DL,0x0d / INT 21
         * disassembly: 243e:023e-243e:0249 */
        fputc('\n', stderr);
        fputc('\r', stderr);

        /* ------------------------------------------------------------------
         * Block 3: key dispatch
         *
         * DOS original (disassembly: 243e:024b-243e:0263  src/chess.c:16699):
         *   CMP AL, 0x77  JZ → RET        'w' = Wiederherstellung
         *   CMP AL, 0x57  JZ → RET        'W'
         *   CMP AL, 0x66  JZ → overlay    'f' = Programm fortsetzen
         *   CMP AL, 0x46  JZ → overlay    'F'
         *   CMP AL, 0x62  JZ → terminate  'b' = Beenden
         *   CMP AL, 0x42  JZ → terminate  'B'
         *   JMP → loop-start              (any other key: retry)
         * ------------------------------------------------------------------ */
        if (key == 'w' || key == 'W') return CPAV_RESTORE;
        if (key == 'f' || key == 'F') return CPAV_CONTINUE;
        if (key == 'b' || key == 'B') return CPAV_QUIT;
        /* else: loop -- any other key retries (mirrors: JMP 0x2000:4610) */
    }
}
