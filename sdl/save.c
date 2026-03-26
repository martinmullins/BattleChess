/*
 * sdl/save.c  --  Battle Chess save-file probe (recovery step 3a)
 *
 * Original source: src/chess.c, FUN_243e_0230 @ 243e:0230
 *
 * The DOS function ran a do-while loop that:
 *   1. Made four int-21h calls to open and read the save/config file
 *      (src/chess.c:16688-16696)
 *   2. Read the first byte as a type tag (src/chess.c:16698)
 *   3. Dispatched on the tag:
 *        'w'/'W' (0x77/0x57) -- no prior save, return immediately
 *                               (src/chess.c:16699-16701)
 *        'f'/'F' (0x66/0x46) -- copy 14-byte overlay config, walk the
 *                               far-pointer relocation table, indirect-
 *                               dispatch via function pointer
 *                               (src/chess.c:16702-16731)
 *        'b'/'B' (0x62/0x42) -- sound-hardware initialisation path:
 *                               OPL port I/O (out/in), frequency calc
 *                               (0x4120 multiplier), SoundBlaster setup
 *                               (src/chess.c:16732-16858)
 *
 * Each numbered block below is one future recovery sub-step.
 */

#include "save.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* -------------------------------------------------------------------------
 * Save file name used by the DOS original (CHESS.SAV in CWD)
 * ---------------------------------------------------------------------- */
#define SAVE_FILE_NAME  "CHESS.SAV"

/* Save-file type tags (first byte of file) */
#define TAG_SKIP         'w'   /* 0x57/'W' -- no save present, skip     */
#define TAG_OVERLAY      'f'   /* 0x46/'F' -- full overlay reload        */
#define TAG_SOUND        'b'   /* 0x42/'B' -- sound-hardware init path   */


/* -------------------------------------------------------------------------
 * Forward declarations for sub-paths to be recovered next
 * ---------------------------------------------------------------------- */

/*
 * RECOVER NEXT (step 3a-ii): handle the 'f'/'F' overlay-reload path.
 * Original: src/chess.c:16702-16731
 * Copies 14 bytes of overlay config to address 0x0000, walks the far-
 * pointer table at *0x06 / *0x18, adds load-offset, then dispatches
 * via a function pointer stored at uVar18+0x474.
 * SDL equivalent: memcpy config block, update runtime pointer table,
 * call the resolved function pointer.
 */
__attribute__((unused)) static int handle_overlay_reload(void);

/*
 * RECOVER NEXT (step 3a-iii): handle the 'b'/'B' sound-hardware path.
 * Original: src/chess.c:16732-16858
 * Initialises the OPL/SoundBlaster chip via port I/O (out/in),
 * computes OPL frequency registers (multiplier 0x4120 ≈ 16672 Hz base),
 * and stores card parameters in the game state block.
 * SDL equivalent: SDL_OpenAudioDevice + SDL_mixer or a software OPL emulator.
 */
__attribute__((unused)) static int handle_sound_init(void);


/* =========================================================================
 * save_file_probe
 *
 * Original: FUN_243e_0230() -- src/chess.c:16639
 * ======================================================================= */
int save_file_probe(void)
{
    /* ------------------------------------------------------------------
     * Block 1: open the save file
     *
     * DOS original (src/chess.c:16688-16696):
     *   Four int-21h calls in a do-while loop:
     *     AH=3Dh -- open file (CHESS.SAV)
     *     AH=3Fh -- read first record
     *     AH=3Eh -- close file
     *     (fourth call context unclear -- possibly AH=57h get file date)
     *
     * RECOVER NEXT (step 3a-i): replace with fopen / fread / fclose.
     *
     * FILE *fp = fopen(SAVE_FILE_NAME, "rb");
     * if (!fp) {
     *     // No save file present -- treat as 'w' (skip).
     *     return 0;
     * }
     * ------------------------------------------------------------------ */
    printf("[save] file open: stub\n");


    /* ------------------------------------------------------------------
     * Block 2: read the type tag (first byte)
     *
     * DOS original (src/chess.c:16698):
     *   The byte at in_stack_00000000 (a register Ghidra could not track)
     *   holds the first byte read from the file.  Ghidra shows it compared
     *   as bVar9 = (byte)in_stack_00000000.
     *
     * RECOVER NEXT (step 3a-i cont.): read one byte after fopen.
     *
     * unsigned char tag = 0;
     * if (fread(&tag, 1, 1, fp) != 1) { fclose(fp); return -1; }
     * fclose(fp);
     * ------------------------------------------------------------------ */
    unsigned char tag = TAG_SKIP;   /* default: no save present */
    printf("[save] type tag: stub (defaulting to 'skip')\n");


    /* ------------------------------------------------------------------
     * Block 3: dispatch on the type tag
     *
     * DOS original (src/chess.c:16699-16858)
     * ------------------------------------------------------------------ */
    if (tag == TAG_SKIP || tag == (TAG_SKIP & ~0x20)) {
        /* 'w' / 'W' -- no prior save, nothing to restore */
        printf("[save] tag=skip: no save file to restore\n");
        return 0;
    }

    if (tag == TAG_OVERLAY || tag == (TAG_OVERLAY & ~0x20)) {
        /* 'f' / 'F' -- full overlay reload
         *
         * RECOVER NEXT (step 3a-ii): uncomment once handle_overlay_reload()
         * has been ported from src/chess.c:16702-16731.
         *
         * return handle_overlay_reload();
         */
        printf("[save] tag=overlay-reload: stub\n");
        return 0;
    }

    if (tag == TAG_SOUND || tag == (TAG_SOUND & ~0x20)) {
        /* 'b' / 'B' -- sound-hardware init
         *
         * RECOVER NEXT (step 3a-iii): uncomment once handle_sound_init()
         * has been ported from src/chess.c:16732-16858.
         *
         * return handle_sound_init();
         */
        printf("[save] tag=sound-init: stub\n");
        return 0;
    }

    fprintf(stderr, "[save] unknown tag byte 0x%02x -- ignoring\n", tag);
    return 0;
}


/* =========================================================================
 * Sub-function stubs
 * ======================================================================= */

/*
 * handle_overlay_reload  --  'f'/'F' path (step 3a-ii)
 * Original: src/chess.c:16702-16731
 */
static int handle_overlay_reload(void)
{
    printf("[save] handle_overlay_reload: stub\n");
    /*
     * RECOVER NEXT (step 3a-ii):
     *   1. Read 14-byte overlay config block from save file.
     *   2. Walk far-pointer relocation table (count at *0x06, base at *0x18).
     *   3. Add load-offset to each pointer pair.
     *   4. Resolve and call dispatch function pointer.
     */
    return 0;
}

/*
 * handle_sound_init  --  'b'/'B' path (step 3a-iii)
 * Original: src/chess.c:16732-16858
 */
static int handle_sound_init(void)
{
    printf("[save] handle_sound_init: stub\n");
    /*
     * RECOVER NEXT (step 3a-iii):
     *   1. Open audio via SDL_OpenAudioDevice.
     *   2. Initialise software OPL emulator (e.g. nuked-opl3 or adlmidi).
     *   3. Program OPL frequency registers using base multiplier 0x4120.
     *   4. Store card parameters in the game state block.
     */
    return 0;
}
