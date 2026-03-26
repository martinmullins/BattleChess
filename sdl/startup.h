/*
 * sdl/startup.h  --  Battle Chess startup declarations
 *
 * Original source: src/chess.c, FUN_243e_0024 @ 243e:0024
 */
#ifndef STARTUP_H
#define STARTUP_H

#include <SDL2/SDL.h>

/*
 * chess_startup -- initialise the game and return the SDL renderer to use.
 *
 * Returns 0 on success, non-zero on failure.
 *
 * Original: FUN_243e_0024() -- src/chess.c:16440
 */
int chess_startup(SDL_Renderer *renderer, int argc, char *argv[]);

#endif /* STARTUP_H */
