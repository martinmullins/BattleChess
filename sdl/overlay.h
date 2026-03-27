/*
 * sdl/overlay.h  --  Battle Chess overlay loader declarations
 *
 * Original source:
 *   src/chess.c  FUN_243e_0024 @ 243e:0024  (scan + reloc)
 *   decompiled/CHESS_disassembly.asm 243e:00be-243e:022b
 */
#ifndef OVERLAY_H
#define OVERLAY_H

#include <stdint.h>
#include <stddef.h>

/*
 * OverlayState -- runtime representation of the decompressed overlay image.
 *
 * In DOS the overlay lived in a real-mode segment found by the paragraph scan.
 * Here we hold a flat heap allocation and record the equivalent metadata.
 *
 * Field traceability (all values from FUN_243e_0024 / 243e segment):
 *
 *   data          flat byte array of CHESS_decompressed.bin
 *   size          byte length of above
 *   load_offset   0x2000 - stored_segment        src/chess.c:16579  243e:01c9
 *   stored_seg    CS:[BP+0x47e]  original segment of overlay at link time
 *                                                src/chess.c:16579  243e:01c0
 *   reloc_count   overlay[0x0006] uint16         src/chess.c:16591  243e:01f2
 *   reloc_table   overlay[0x0018] uint16         src/chess.c:16593  243e:01fa
 *   dispatch_off  CS:[BP+0x474]  far-jump target src/chess.c:16605  243e:022b
 */
typedef struct {
    uint8_t  *data;
    size_t    size;
    uint16_t  load_offset;    /* paragraph delta applied to all reloc entries */
    uint16_t  stored_seg;     /* original DOS link-time segment */
    uint16_t  reloc_count;    /* number of far-pointer fixup entries */
    uint16_t  reloc_table;    /* byte offset of reloc table within data[] */
    uint16_t  dispatch_off;   /* entry-point offset after relocation */
} OverlayState;

/*
 * overlay_locate -- load CHESS_decompressed.bin and verify the 4-word
 * signature at offset 0x0006.
 *
 * Fills *ov on success.  Caller must free(ov->data) when done.
 * Returns 0 on success, -1 on failure.
 *
 * Original: paragraph scan loop  src/chess.c:16528-16545  243e:00be-243e:00df
 */
int overlay_locate(OverlayState *ov);

/*
 * overlay_relocate -- walk the relocation table and apply load_offset to
 * every far-pointer pair stored in the overlay image.
 *
 * Must be called after overlay_locate().
 * Returns 0 on success, -1 on failure.
 *
 * Original: pointer-fixup loop + far-jump  src/chess.c:16578-16606  243e:01c0-243e:022b
 */
int overlay_relocate(OverlayState *ov);

#endif /* OVERLAY_H */
