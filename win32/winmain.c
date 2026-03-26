/*
 * winmain.c  --  Battle Chess Win32 entry point (recovery step 1)
 *
 * This file is the first step in porting the DOS Battle Chess decompilation
 * to a native Win32 application.  It compiles cleanly with:
 *
 *   gcc  (Linux / CI):   gcc -o winmain winmain.c
 *   MinGW (Windows):     gcc -mwindows -o BattleChess.exe winmain.c
 *
 * Each section labelled "RECOVER NEXT:" marks the next incremental step.
 * Uncomment those blocks only after the corresponding subsystem has been
 * ported from src/chess.c.
 *
 * Original DOS entry chain:
 *   entry()          @ 243e:0001  (src/chess.c:16404)
 *     FUN_243e_0024()              -- main init, DOS int-21h calls
 */

/* -------------------------------------------------------------------------
 * Platform detection
 * ---------------------------------------------------------------------- */
#ifdef _WIN32
#  include <windows.h>
#else
/* Minimal stubs so the file compiles on Linux/GCC without Windows headers. */
#  include <stdio.h>
#  include <stdlib.h>
typedef void*    HINSTANCE;
typedef void*    HWND;
typedef char*    LPSTR;
typedef int      INT;
#  define WINAPI
#  define CALLBACK
/* RECOVER NEXT (step 2): pull in a real Win32 message loop when building
 * under MinGW -- remove the stubs above and add -mwindows to CFLAGS. */
#endif


/* -------------------------------------------------------------------------
 * Forward declarations for subsystems to be recovered
 * ---------------------------------------------------------------------- */

/* RECOVER NEXT (step 3): game_init() will map to FUN_243e_0024()
 * in src/chess.c.  Restore DOS int-21h calls as Win32 equivalents
 * (file I/O → CreateFile, memory alloc → HeapAlloc, etc.). */
static int  game_init(void);   /* stub defined below */

/* RECOVER NEXT (step 4): game_tick() will hold the main update loop
 * that currently lives inside FUN_243e_0024()'s inner do-while. */
static void game_tick(void);   /* stub defined below */

/* RECOVER NEXT (step 5): game_shutdown() maps the DOS terminate
 * path (int 21h, AH=4Ch) to a clean Win32 exit sequence. */
static void game_shutdown(void);


/* =========================================================================
 * Win32 window procedure  (RECOVER NEXT step 6)
 * =========================================================================
 * When the window subsystem is restored, uncomment and flesh out this
 * WndProc.  It will handle:
 *   WM_CREATE   -- allocate game resources
 *   WM_PAINT    -- blit the chess board (GDI / BitBlt)
 *   WM_KEYDOWN  -- forward key codes to the chess engine input handler
 *   WM_DESTROY  -- PostQuitMessage(0)
 * ======================================================================= */
#ifdef _WIN32
static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        /* RECOVER NEXT (step 6a):
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // board_render(hdc);   <-- ported from DOS video output
            EndPaint(hWnd, &ps);
            return 0;
        }
        */

        /* RECOVER NEXT (step 6b):
        case WM_KEYDOWN:
            // chess_handle_key((int)wParam);
            return 0;
        */

        default:
            return DefWindowProc(hWnd, msg, wParam, lParam);
    }
}
#endif /* _WIN32 */


/* =========================================================================
 * Win32 entry point
 * =========================================================================
 * On Windows this is the real subsystem entry point (-mwindows).
 * On Linux the #else branch provides a plain main() so CI can verify
 * the file compiles without a Windows toolchain.
 * ======================================================================= */
#ifdef _WIN32

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR     lpCmdLine,
                   INT       nCmdShow)
{
    (void)hPrevInstance;
    (void)lpCmdLine;

    /* ------------------------------------------------------------------
     * RECOVER NEXT (step 7): register and create the main window.
     * Uncomment after step 6 (WndProc) is complete.
     *
     * static const char CLASS_NAME[] = "BattleChessWnd";
     *
     * WNDCLASS wc = {0};
     * wc.lpfnWndProc   = WndProc;
     * wc.hInstance     = hInstance;
     * wc.lpszClassName = CLASS_NAME;
     * wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
     * wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
     * if (!RegisterClass(&wc)) return 1;
     *
     * HWND hWnd = CreateWindowEx(
     *     0, CLASS_NAME, "Battle Chess",
     *     WS_OVERLAPPEDWINDOW,
     *     CW_USEDEFAULT, CW_USEDEFAULT,
     *     640, 480,           // original DOS resolution
     *     NULL, NULL, hInstance, NULL);
     * if (!hWnd) return 1;
     *
     * ShowWindow(hWnd, nCmdShow);
     * UpdateWindow(hWnd);
     * ------------------------------------------------------------------ */

    if (game_init() != 0)
        return 1;

    /* ------------------------------------------------------------------
     * RECOVER NEXT (step 8): replace this stub loop with a real message
     * pump that also calls game_tick() on each frame.
     *
     * MSG msg = {0};
     * while (GetMessage(&msg, NULL, 0, 0)) {
     *     TranslateMessage(&msg);
     *     DispatchMessage(&msg);
     *     game_tick();
     * }
     * return (int)msg.wParam;
     * ------------------------------------------------------------------ */

    game_tick();
    game_shutdown();
    return 0;
}

#else  /* Linux / plain GCC */

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    if (game_init() != 0)
        return 1;

    game_tick();
    game_shutdown();
    return 0;
}

#endif /* _WIN32 */


/* =========================================================================
 * Subsystem stubs
 * =========================================================================
 * These will be replaced one by one as code is recovered from src/chess.c.
 * ======================================================================= */

/*
 * game_init  --  stub for FUN_243e_0024() recovery (step 3)
 *
 * The real init:
 *   - Parses the DOS PSP command tail (int 21h, AH=62h)
 *   - Allocates a 353 KB overlay buffer (DAT_243e_051f = 0x43e4)
 *   - Sets up video mode (int 10h, AH=00h)
 *   - Loads piece animation data from ALLCANM1 / ALLCANM2
 *   - Initialises the chess engine state tables
 * Each bullet becomes one sub-step when that block is uncommented.
 */
static int game_init(void)
{
#ifndef _WIN32
    printf("[BattleChess] game_init: stub -- nothing initialised yet\n");
#endif
    /* RECOVER NEXT (step 3): call ported FUN_243e_0024() here */
    return 0;  /* 0 = success */
}

/*
 * game_tick  --  stub for the main update loop (step 4)
 */
static void game_tick(void)
{
#ifndef _WIN32
    printf("[BattleChess] game_tick: stub -- no game logic yet\n");
#endif
    /* RECOVER NEXT (step 4): drive the chess engine one frame */
}

/*
 * game_shutdown  --  stub for clean exit (step 5)
 */
static void game_shutdown(void)
{
#ifndef _WIN32
    printf("[BattleChess] game_shutdown: stub -- nothing to clean up yet\n");
#endif
    /* RECOVER NEXT (step 5): free resources, close handles */
}
