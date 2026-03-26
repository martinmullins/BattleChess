/*
 * sdl/main.c  --  Battle Chess SDL2 entry point (recovery step 1)
 *
 * First step in porting the DOS Battle Chess decompilation to a native
 * Linux application backed by SDL2.
 *
 * Build (single file):
 *   gcc $(pkg-config --cflags sdl2) -o battlechess main.c startup.c \
 *       $(pkg-config --libs sdl2)
 *
 * Original DOS entry chain:
 *   entry()          @ 243e:0001  (src/chess.c:16404)
 *     FUN_243e_0024()              -- main init  (-> sdl/startup.c)
 *
 * Recovery roadmap -- each "RECOVER NEXT (step N):" comment marks what
 * gets uncommented / implemented in the corresponding future step.
 */

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "startup.h"

/* -------------------------------------------------------------------------
 * Constants
 * ---------------------------------------------------------------------- */
#define WINDOW_TITLE  "Battle Chess"
#define WINDOW_W      640   /* original DOS resolution */
#define WINDOW_H      480


/* -------------------------------------------------------------------------
 * Forward declarations for subsystems to be recovered
 * ---------------------------------------------------------------------- */

/* chess_startup() is now in sdl/startup.c -- step 3 wired up. */

/* RECOVER NEXT (step 4): inner update loop from FUN_243e_0024().
 * Drives the chess engine one logical frame and returns non-zero
 * when the user requests quit. */
static int  game_tick(SDL_Renderer *renderer);

/* RECOVER NEXT (step 5): maps the DOS terminate path (int 21h AH=4Ch)
 * to a clean resource-free sequence. */
static void game_shutdown(void);


/* =========================================================================
 * main
 * ======================================================================= */
int main(int argc, char *argv[])
{

    /* --- SDL2 init -------------------------------------------------------- */
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
        fprintf(stderr, "SDL_Init failed: %s\n", SDL_GetError());
        return 1;
    }

    /* --- Window ----------------------------------------------------------- */
    SDL_Window *window = SDL_CreateWindow(
        WINDOW_TITLE,
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WINDOW_W, WINDOW_H,
        SDL_WINDOW_SHOWN
        /* RECOVER NEXT (step 7): add SDL_WINDOW_RESIZABLE once the
         * board renderer supports dynamic scaling. */
    );
    if (!window) {
        fprintf(stderr, "SDL_CreateWindow failed: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    /* --- Renderer --------------------------------------------------------- */
    SDL_Renderer *renderer = SDL_CreateRenderer(
        window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
    if (!renderer) {
        fprintf(stderr, "SDL_CreateRenderer failed: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    /* --- Game init (step 3: wired to chess_startup in sdl/startup.c) ----- */
    if (chess_startup(renderer, argc, argv) != 0) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    /* --- Main loop -------------------------------------------------------- */
    int running = 1;
    while (running) {
        /* Event pump */
        SDL_Event ev;
        while (SDL_PollEvent(&ev)) {
            if (ev.type == SDL_QUIT) {
                running = 0;
            }
            /* RECOVER NEXT (step 6): forward keyboard / mouse events to the
             * chess input handler.
             *
             * if (ev.type == SDL_KEYDOWN)
             *     chess_handle_key(ev.key.keysym.sym);
             * if (ev.type == SDL_MOUSEBUTTONDOWN)
             *     chess_handle_click(ev.button.x, ev.button.y);
             */
        }

        /* Clear */
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        /* RECOVER NEXT (step 4a): call game_tick() to update state, then
         * board_render() to blit the chess board.
         *
         * if (game_tick(renderer) != 0)
         *     running = 0;
         */

        /* Present */
        SDL_RenderPresent(renderer);
    }

    /* --- Shutdown --------------------------------------------------------- */
    game_shutdown();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}


/* =========================================================================
 * Subsystem stubs  (game_init promoted to sdl/startup.c as chess_startup)
 * ======================================================================= */

/*
 * game_tick  --  stub for the main update / render loop (step 4)
 *
 * Returns 0 to keep running, non-zero to signal quit.
 */
__attribute__((unused))
static int game_tick(SDL_Renderer *renderer)
{
    (void)renderer;
    /* RECOVER NEXT (step 4): drive one frame of chess engine logic and
     * call board_render(renderer) to draw the current board state. */
    return 0;
}

/*
 * game_shutdown  --  stub for clean exit (step 5)
 */
static void game_shutdown(void)
{
    printf("[BattleChess] game_shutdown: stub -- nothing to clean up yet\n");
    /* RECOVER NEXT (step 5): free textures, close file handles, etc. */
}
