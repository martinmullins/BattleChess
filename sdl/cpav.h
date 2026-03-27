/*
 * sdl/cpav.h  --  Central Point Anti-Virus integrity prompt declarations
 *
 * Original source:
 *   src/chess.c      FUN_243e_0230 @ 243e:0230   (lines 16639-16858)
 *   CHESS_disassembly.asm  243e:0230-243e:0265
 *   CHESS.EXE.orig   prompt string @ file offset 0x14851..0x14913
 */
#ifndef CPAV_H
#define CPAV_H

/*
 * CpavResult -- return value of cpav_prompt(), mirrors the key dispatch.
 *
 * Original key comparisons (disassembly: 243e:024b-243e:0261):
 *   'w'/'W' (0x77/0x57) → RET              src/chess.c:16699-16701
 *   'f'/'F' (0x66/0x46) → overlay dispatch  src/chess.c:16702-16731
 *   'b'/'B' (0x62/0x42) → DOS terminate     disassembly: 243e:026a-243e:026d
 *   else                → retry loop        disassembly: 243e:0263
 */
typedef enum {
    CPAV_RESTORE  = 'w',   /* [W] Wiederherstellung  -- restore & continue */
    CPAV_CONTINUE = 'f',   /* [F] Programm fortsetzen -- run despite change */
    CPAV_QUIT     = 'b',   /* [B] Beenden            -- exit                */
} CpavResult;

/*
 * cpav_prompt -- display the CPAV integrity-check menu and return the
 * player's choice.  Loops until a valid key is pressed.
 *
 * Original: FUN_243e_0230 @ src/chess.c:16639  disassembly: 243e:0230
 *
 * DOS behaviour:
 *   AH=9  INT 21h  -- print '$'-terminated string at CS:[BP+0x36e+BP]
 *   AH=1  INT 21h  -- read char with echo → AL
 *   AH=2  INT 21h  -- write LF (0x0a) then CR (0x0d)
 *   Loop until AL ∈ { 'w','W','f','F','b','B' }
 */
CpavResult cpav_prompt(void);

#endif /* CPAV_H */
