/*
 * fuzz_save_game_regs_b.c — FUN_1000_2cac
 *
 * Slot-B save: same 8 SRC registers as FUN_1000_2c46, different DST bank.
 *
 * Invariants:
 *   - Each DSTB slot == corresponding SRC after call
 *   - SRC slots unchanged
 *   - Roundtrip: save_b → corrupt SRC → restore_b → SRC == original
 *
 * Build:
 *   clang -fsanitize=fuzzer,address,undefined -O1 -o fuzz_save_game_regs_b \
 *         fuzz_save_game_regs_b.c tier3_impl.c seg_storage.c
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
static const uint16_t DSTB_ADDRS[8] = {
    SEG_GR_DSTB_0, SEG_GR_DSTB_1, SEG_GR_DSTB_2, SEG_GR_DSTB_3,
    SEG_GR_DSTB_4, SEG_GR_DSTB_5, SEG_GR_DSTB_6, SEG_GR_DSTB_7,
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

    FUN_1000_2cac();

    for (int i = 0; i < 8; i++) {
        assert(GSEG(DSTB_ADDRS[i], uint16_t) == src[i]);
        assert(GSEG(SRC_ADDRS[i],  uint16_t) == src[i]);
    }

    /* Roundtrip with restore_b. */
    for (int i = 0; i < 8; i++)
        GSEG(SRC_ADDRS[i], uint16_t) = (uint16_t)~src[i];
    FUN_1000_2ce0();
    for (int i = 0; i < 8; i++)
        assert(GSEG(SRC_ADDRS[i], uint16_t) == src[i]);

    return 0;
}
