/*
 * fuzz_restore_game_regs.c — FUN_1000_2c79
 *
 * Invariants:
 *   - Each of the 8 SRC slots equals the corresponding DST value after call
 *   - DST slots are not modified by the call
 *   - Roundtrip: save(orig_src) → corrupt src → restore() → src == orig_src
 *
 * Build:
 *   clang -fsanitize=fuzzer,address,undefined -O1 -o fuzz_restore_game_regs \
 *         fuzz_restore_game_regs.c tier3_impl.c
 */
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include "tier3_impl.h"

static const uint16_t SRC_ADDRS[8] = {
    SEG_GR_SRC_0, SEG_GR_SRC_1, SEG_GR_SRC_2, SEG_GR_SRC_3,
    SEG_GR_SRC_4, SEG_GR_SRC_5, SEG_GR_SRC_6, SEG_GR_SRC_7,
};
static const uint16_t DST_ADDRS[8] = {
    SEG_GR_DST_0, SEG_GR_DST_1, SEG_GR_DST_2, SEG_GR_DST_3,
    SEG_GR_DST_4, SEG_GR_DST_5, SEG_GR_DST_6, SEG_GR_DST_7,
};

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    /* First 16 bytes: saved (DST) values.  Next 16 bytes: original SRC values
     * used for the roundtrip half of the test. */
    if (size < 16 * sizeof(uint16_t))
        return 0;

    memset(g_chess_seg, 0, sizeof(g_chess_seg));

    uint16_t dst[8], orig_src[8];
    __builtin_memcpy(dst,      data,                        8 * sizeof(uint16_t));
    __builtin_memcpy(orig_src, data + 8 * sizeof(uint16_t), 8 * sizeof(uint16_t));

    for (int i = 0; i < 8; i++)
        GSEG(DST_ADDRS[i], uint16_t) = dst[i];

    FUN_1000_2c79();

    /* Every SRC slot must hold the corresponding DST value. */
    for (int i = 0; i < 8; i++) {
        assert(GSEG(SRC_ADDRS[i], uint16_t) == dst[i]);
        /* DST slots must be untouched. */
        assert(GSEG(DST_ADDRS[i], uint16_t) == dst[i]);
    }

    /* --- Roundtrip cross-validation ---
     * save(orig_src) captures orig values into DST, then restore() must
     * recover them back into SRC even after SRC was clobbered. */
    for (int i = 0; i < 8; i++)
        GSEG(SRC_ADDRS[i], uint16_t) = orig_src[i];

    FUN_1000_2c46();   /* save: DST ← orig_src */
    for (int i = 0; i < 8; i++)
        GSEG(SRC_ADDRS[i], uint16_t) = (uint16_t)~orig_src[i];  /* corrupt SRC */

    FUN_1000_2c79();   /* restore: SRC ← DST == orig_src */
    for (int i = 0; i < 8; i++)
        assert(GSEG(SRC_ADDRS[i], uint16_t) == orig_src[i]);

    return 0;
}
