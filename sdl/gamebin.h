/*
 * sdl/gamebin.h  --  game-binary integrity check declarations
 *
 * Original source:
 *   src/chess.c          FUN_243e_0024 @ 243e:0024  (lines 16481-16515)
 *   CHESS_disassembly.asm  243e:0060 - 243e:00c0
 */
#ifndef GAMEBIN_H
#define GAMEBIN_H

/*
 * GamebinStatus -- result of the integrity check.
 *
 * Original: the low-memory/integrity flag at CS:[BP+0x433] (1 byte)
 *   0 = header matches and file size is correct (src/chess.c:16489)
 *   1 = header mismatch or file size below expected (src/chess.c:16491)
 *       → caller invokes the CPAV prompt (FUN_243e_0230 / cpav_prompt)
 */
typedef enum {
    GAMEBIN_OK       = 0,   /* header matches, size OK -- continue normally   */
    GAMEBIN_MODIFIED = 1,   /* mismatch detected       -- CPAV prompt needed  */
    GAMEBIN_ERROR    = -1,  /* I/O failure opening or reading the binary      */
} GamebinStatus;

/*
 * gamebin_check -- open the game binary, read its 32-byte MZ header
 * (from file offset 2, skipping the 'MZ' magic), compare against the
 * known-good reference, then verify the file size.
 *
 * path   -- path to CHESS.EXE.orig (or the original CHESS.EXE at runtime).
 *           In DOS this came from the PSP environment block; here it is
 *           passed explicitly.
 *
 * Returns GAMEBIN_OK, GAMEBIN_MODIFIED, or GAMEBIN_ERROR.
 *
 * Original: inline in FUN_243e_0024
 *   src/chess.c:16481-16515   disassembly: 243e:0060-243e:00c0
 */
GamebinStatus gamebin_check(const char *path);

#endif /* GAMEBIN_H */
