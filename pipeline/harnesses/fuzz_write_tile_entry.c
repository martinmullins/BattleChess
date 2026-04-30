/*
 * fuzz_write_tile_entry.c — FUN_1000_7dbf
 *
 * Writes a byte pair into the stride-4 tile table at 0xa8ba:
 *   tile_table[param_3 * 4]     = param_1
 *   tile_table[param_3 * 4 + 1] = param_2
 *
 * Invariants:
 *   - g_chess_seg[0xa8ba + param_3*4]     == param_1
 *   - g_chess_seg[0xa8ba + param_3*4 + 1] == param_2
 *   - No other addresses modified
 *
 * Build:
 *   clang -fsanitize=fuzzer,address,undefined -O1 -o fuzz_write_tile_entry \
 *         fuzz_write_tile_entry.c tier3_impl.c seg_storage.c
 */
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include "tier3_impl.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    /* param_1, param_2 (byte values), param_3 (index 0–127) */
    if (size < 3)
        return 0;

    uint8_t p1 = data[0];
    uint8_t p2 = data[1];
    int     p3 = (int)(data[2] & 0x7f);  /* keep addresses in safe range */

    memset(g_chess_seg, 0, sizeof(g_chess_seg));

    FUN_1000_7dbf(p1, p2, p3);

    uint16_t addr0 = (uint16_t)(SEG_TILE_TABLE + (unsigned)p3 * 4);
    uint16_t addr1 = (uint16_t)(SEG_TILE_TABLE + (unsigned)p3 * 4 + 1);

    assert(GSEG(addr0, uint8_t) == p1);
    assert(GSEG(addr1, uint8_t) == p2);

    /* Verify nothing else was written (spot-check neighbours). */
    uint16_t addr2 = (uint16_t)(SEG_TILE_TABLE + (unsigned)p3 * 4 + 2);
    uint16_t addr3 = (uint16_t)(SEG_TILE_TABLE + (unsigned)p3 * 4 + 3);
    assert(GSEG(addr2, uint8_t) == 0);
    assert(GSEG(addr3, uint8_t) == 0);

    return 0;
}
