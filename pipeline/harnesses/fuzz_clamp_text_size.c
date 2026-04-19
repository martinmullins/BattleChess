/*
 * fuzz_clamp_text_size.c — FUN_1000_8a64
 *
 * Invariants:
 *   - SEG_TS_DIRTY  is always set to 1
 *   - SEG_TS_ZAP    is always set to 0
 *   - If input is "large enough"  (h >= 1, or h == 0 && w >= 3):
 *       output == input  (pass-through)
 *   - Otherwise clamp to (w=3, h=0)
 *
 * Clamping condition (from decompiled source):
 *   (iVar2 < 1) && ((iVar2 < 0) || (uVar1 < 3))
 *   where uVar1 = width (uint16), iVar2 = height (int16)
 *
 * Build:
 *   clang -fsanitize=fuzzer,address,undefined -O1 -o fuzz_clamp_text_size \
 *         fuzz_clamp_text_size.c tier3_impl.c
 */
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include "tier3_impl.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    if (size < sizeof(uint16_t) + sizeof(int16_t))
        return 0;

    memset(g_chess_seg, 0, sizeof(g_chess_seg));

    uint16_t w;
    int16_t  h;
    __builtin_memcpy(&w, data,                   sizeof(uint16_t));
    __builtin_memcpy(&h, data + sizeof(uint16_t), sizeof(int16_t));

    GSEG(SEG_TS_WIDTH,  uint16_t) = w;
    GSEG(SEG_TS_HEIGHT, int16_t)  = h;

    FUN_1000_8a64();

    /* Dirty flag and sentinel are always written. */
    assert(GSEG(SEG_TS_DIRTY, uint16_t) == 1);
    assert(GSEG(SEG_TS_ZAP,   uint16_t) == 0);

    int should_clamp = (h < 1) && ((h < 0) || (w < 3));

    if (should_clamp) {
        assert(GSEG(SEG_TS_CLAMP_W, uint16_t) == 3);
        assert(GSEG(SEG_TS_CLAMP_H, int16_t)  == 0);
    } else {
        assert(GSEG(SEG_TS_CLAMP_W, uint16_t) == w);
        assert(GSEG(SEG_TS_CLAMP_H, int16_t)  == h);
    }

    return 0;
}
