/*
 * fuzz_save_game_regs.c — FUN_1000_2c46
 *
 * Invariants:
 *   - Each of the 8 DST slots equals the corresponding SRC value after call
 *   - SRC slots are not modified by the call
 *
 * Build:
 *   clang -fsanitize=fuzzer,address,undefined -O1 -o fuzz_save_game_regs \
 *         fuzz_save_game_regs.c tier3_impl.c
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
    if (size < 8 * sizeof(uint16_t))
        return 0;

    memset(g_chess_seg, 0, sizeof(g_chess_seg));

    uint16_t src[8];
    __builtin_memcpy(src, data, 8 * sizeof(uint16_t));
    for (int i = 0; i < 8; i++)
        GSEG(SRC_ADDRS[i], uint16_t) = src[i];

    FUN_1000_2c46();

    for (int i = 0; i < 8; i++) {
        /* Every DST slot must now hold the corresponding SRC value. */
        assert(GSEG(DST_ADDRS[i], uint16_t) == src[i]);
        /* SRC slots must be untouched. */
        assert(GSEG(SRC_ADDRS[i], uint16_t) == src[i]);
    }
    return 0;
}
