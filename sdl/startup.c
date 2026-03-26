/*
 * sdl/startup.c  --  Battle Chess startup / initialisation (recovery step 3)
 *
 * Original source: src/chess.c, FUN_243e_0024 @ 243e:0024
 *
 * The DOS function did the following in order:
 *   1. Scan the PSP command tail for arguments   (src/chess.c:16469-16480)
 *   2. Issue four DOS int-21h calls to query     (src/chess.c:16481-16488)
 *      available memory (AH=48h / AH=4Ah)
 *   3. Compare available vs required memory and  (src/chess.c:16489-16515)
 *      set an "insufficient memory" flag
 *   4. Call FUN_243e_0230 to validate / load     (src/chess.c:16516-16527)
 *      an existing save file
 *   5. Locate the overlay data inside the        (src/chess.c:16528-16570)
 *      executable image (magic-byte scan)
 *   6. Copy 14 bytes of overlay config to seg 0  (src/chess.c:16580-16588)
 *   7. Relocate internal segment pointers by     (src/chess.c:16589-16606)
 *      a load-offset and jump via a function ptr
 *
 * Each numbered block below maps to one future recovery sub-step.
 * Uncomment the block when that sub-system has been ported.
 */

#include "startup.h"
#include "save.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* -------------------------------------------------------------------------
 * Forward declarations for sub-functions to be recovered next
 * ---------------------------------------------------------------------- */

/* save_file_probe() is now in sdl/save.c -- step 3a wired up. */

/*
 * RECOVER NEXT (step 3b): locate and map the compressed overlay buffer
 * that is appended to the DOS executable image.
 * Original: the magic-byte scan loop -- src/chess.c:16529-16545
 * SDL equivalent: SDL_RWops on the game binary or a dedicated data file.
 */
__attribute__((unused)) static int overlay_locate(void);    /* stub defined below */

/*
 * RECOVER NEXT (step 3c): relocate internal far-pointer tables after
 * the overlay is mapped at its runtime address.
 * Original: pointer-fixup loop + indirect jump -- src/chess.c:16589-16606
 */
__attribute__((unused)) static int overlay_relocate(void);  /* stub defined below */


/* =========================================================================
 * chess_startup
 *
 * Original: FUN_243e_0024() -- src/chess.c:16440
 * ======================================================================= */
int chess_startup(SDL_Renderer *renderer, int argc, char *argv[])
{
    (void)renderer;

    /* ------------------------------------------------------------------
     * Block 1: command-line argument parsing
     *
     * DOS original (src/chess.c:16469-16480):
     *   Scanned PSP segment 0x0000 from offset 0x80 (the command tail)
     *   looking for double-NUL termination, then stored the pointer to
     *   the first argument at stack+0x331.
     *
     * RECOVER NEXT (step 3-1): parse argc/argv for the same flags the
     * DOS version accepted (e.g. difficulty level, player side).
     *
     * const char *arg_difficulty = NULL;
     * for (int i = 1; i < argc; i++) {
     *     if (strcmp(argv[i], "-easy") == 0) arg_difficulty = argv[i];
     * }
     * ------------------------------------------------------------------ */
    (void)argc;
    (void)argv;
    printf("[startup] arg parse: stub\n");


    /* ------------------------------------------------------------------
     * Block 2: memory availability check
     *
     * DOS original (src/chess.c:16481-16515):
     *   Four int-21h calls (AH=48h / AH=4Ah) queried and resized the
     *   DOS memory arena.  If available paragraphs < required (0x43e4 =
     *   353 KB), a low-memory flag was set at stack+0x198.
     *
     * RECOVER NEXT (step 3-2): on Linux/SDL2 use malloc/mmap; the 353 KB
     * overlay buffer is always available so this check can be a no-op,
     * but we keep the flag for future compatibility.
     *
     * #define OVERLAY_SIZE_BYTES  (0x43e4 * 16)   // ~353 KB
     * void *overlay_buf = malloc(OVERLAY_SIZE_BYTES);
     * if (!overlay_buf) { fprintf(stderr, "OOM\n"); return -1; }
     * ------------------------------------------------------------------ */
    printf("[startup] memory check: stub\n");


    /* ------------------------------------------------------------------
     * Block 3: save-state validation
     *
     * DOS original (src/chess.c:16516-16527):
     *   Calls FUN_243e_0230 in two different branches depending on the
     *   memory flag.  One branch also issues int-21h file-open calls
     *   (AH=3Dh) before invoking the validator.
     *
     * RECOVER NEXT (step 3-3 cont.): save_file_probe() is now wired in;
     * uncomment the call below once the file-open block inside save.c
     * (step 3a-i) has been ported.
     *
     * if (save_file_probe() != 0) {
     *     fprintf(stderr, "[startup] save probe failed\n");
     *     // not fatal -- start a fresh game
     * }
     * ------------------------------------------------------------------ */
    save_file_probe();   /* step 3a: runs stubs, safe to call now */


    /* ------------------------------------------------------------------
     * Block 4: overlay location
     *
     * DOS original (src/chess.c:16528-16545):
     *   Scanned the loaded executable image from just past the code
     *   segment looking for a 4-byte magic marker (value 0x00000006)
     *   to find the start of the compressed overlay data.
     *
     * RECOVER NEXT (step 3-4): call overlay_locate() once the overlay
     * format has been mapped from CHESS_decompressed.bin.
     *
     * if (overlay_locate() != 0) {
     *     fprintf(stderr, "[startup] overlay not found\n");
     *     return -1;
     * }
     * ------------------------------------------------------------------ */
    printf("[startup] overlay locate: stub\n");


    /* ------------------------------------------------------------------
     * Block 5: overlay relocation
     *
     * DOS original (src/chess.c:16580-16606):
     *   Copied 14 bytes of config from the overlay into segment 0,
     *   then walked an internal pointer table (count at *0x06, base at
     *   *0x18) adding the load-offset iVar9 to each far-pointer pair.
     *   Finally dispatched through a function pointer at stack+0x371.
     *
     * RECOVER NEXT (step 3-5): call overlay_relocate() after the overlay
     * buffer is mapped at a known virtual address.
     *
     * if (overlay_relocate() != 0) {
     *     fprintf(stderr, "[startup] overlay relocation failed\n");
     *     return -1;
     * }
     * ------------------------------------------------------------------ */
    printf("[startup] overlay relocate: stub\n");

    return 0;
}


/* =========================================================================
 * Sub-function stubs  (each replaced by its own file when ported)
 * ======================================================================= */

/*
 * overlay_locate  --  stub for overlay magic-byte scan (step 3b)
 * Original: inline scan loop -- src/chess.c:16529-16545
 */
static int overlay_locate(void)
{
    printf("[startup] overlay_locate: stub\n");
    /* RECOVER NEXT (step 3b): open CHESS_decompressed.bin via SDL_RWops
     * and locate the 4-byte magic marker 0x00000006. */
    return 0;
}

/*
 * overlay_relocate  --  stub for pointer-fixup + dispatch (step 3c)
 * Original: pointer-fixup loop + indirect jump -- src/chess.c:16589-16606
 */
static int overlay_relocate(void)
{
    printf("[startup] overlay_relocate: stub\n");
    /* RECOVER NEXT (step 3c): walk the internal far-pointer table and
     * apply the load-offset, then resolve the dispatch function pointer. */
    return 0;
}
