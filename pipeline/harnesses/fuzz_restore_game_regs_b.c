/*
 * fuzz_restore_game_regs_b.c — FUN_1000_2ce0
 *
 * Slot-B restore: exact inverse of FUN_1000_2cac.
 *
 * Invariants:
 *   - Each SRC slot == corresponding DSTB after call
 *   - DSTB slots unchanged
 *
 * Build:
 *   clang -fsanitize=fuzzer,address,undefined -O1 -o fuzz_restore_game_regs_b \
 *         fuzz_restore_game_regs_b.c tier3_impl.c seg_storage.c
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

    uint16_t dstb[8];
    __builtin_memcpy(dstb, data, 8 * sizeof(uint16_t));
    for (int i = 0; i < 8; i++)
        GSEG(DSTB_ADDRS[i], uint16_t) = dstb[i];

    FUN_1000_2ce0();

    for (int i = 0; i < 8; i++) {
        assert(GSEG(SRC_ADDRS[i],  uint16_t) == dstb[i]);
        assert(GSEG(DSTB_ADDRS[i], uint16_t) == dstb[i]);
    }
    return 0;
}
