/*
 * sdl/save.h  --  Battle Chess save-file probe declarations
 *
 * Original source: src/chess.c, FUN_243e_0230 @ 243e:0230
 */
#ifndef SAVE_H
#define SAVE_H

/*
 * save_file_probe -- open the game save/config file, read its type tag,
 * and dispatch to the appropriate startup sub-path.
 *
 * Returns  0  on success (file absent or tag handled),
 *         -1  on I/O error.
 *
 * Original: FUN_243e_0230() -- src/chess.c:16639
 *
 * Tag dispatch:
 *   'w' / 'W'  (0x77 / 0x57)  -- no prior save, skip          src/chess.c:16699-16701
 *   'f' / 'F'  (0x66 / 0x46)  -- full overlay reload           src/chess.c:16702-16731
 *   'b' / 'B'  (0x62 / 0x42)  -- sound-hardware init path      src/chess.c:16732-16858
 */
int save_file_probe(void);

#endif /* SAVE_H */
