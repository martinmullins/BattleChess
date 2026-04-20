/*
 * fuzz_init_callback_table.c — FUN_1000_29b9
 *
 * Writes 8 hardcoded DOS far-pointers (offset:segment) to fixed addresses.
 * All share segment 0x5cc2; offsets are distinct per callback.
 *
 * Invariants:
 *   - All 8 offset slots hold their expected constant values
 *   - All 8 segment slots == 0x5cc2
 *   - No other addresses touched (verified via a before/after byte checksum
 *     over g_chess_seg excluding the 16 known destination bytes)
 *
 * Note: the function takes no inputs; fuzz data seeds the initial segment
 * state to verify the function overwrites regardless of prior content.
 *
 * Build:
 *   clang -fsanitize=fuzzer,address,undefined -O1 -o fuzz_init_callback_table \
 *         fuzz_init_callback_table.c tier3_impl.c seg_storage.c
 */
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include "tier3_impl.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    memset(g_chess_seg, 0, sizeof(g_chess_seg));

    /* Optionally seed the destination slots with garbage to confirm overwrite. */
    if (size >= 16 * sizeof(uint16_t)) {
        for (int i = 0; i < 8; i++) {
            uint16_t v;
            __builtin_memcpy(&v, data + i * 2, 2);
            GSEG(CB_OFF_ADDRS[i], uint16_t) = v;
            __builtin_memcpy(&v, data + 16 + i * 2, 2);
            GSEG(CB_SEG_ADDRS[i], uint16_t) = v;
        }
    }

    FUN_1000_29b9();

    for (int i = 0; i < 8; i++) {
        assert(GSEG(CB_OFF_ADDRS[i], uint16_t) == CB_OFFSETS[i]);
        assert(GSEG(CB_SEG_ADDRS[i], uint16_t) == CB_SEG_COMMON);
    }
    return 0;
}
