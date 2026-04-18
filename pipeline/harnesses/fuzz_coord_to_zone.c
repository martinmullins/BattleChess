/*
 * fuzz_coord_to_zone.c — LibFuzzer harness for FUN_1000_d840 (coord_to_zone).
 *
 * Maps screen pixel (x, y) with an optional flag to a board zone index.
 * Valid return values: 0-9 (zone indices) or 0xff (out of bounds).
 *
 * Build:
 *   clang -fsanitize=fuzzer,address,undefined -O1 -o fuzz_coord_to_zone \
 *         fuzz_coord_to_zone.c tier1_impl.c
 */
#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include "tier1_impl.h"

/* Reference: known zone boundaries derived from the original code. */
static int ref_coord_to_zone(int x, int y, int flag)
{
    if (x > 0x3c && x < 0xbb && y > 0x3c && y < 0x8b)
        return (y - 0x3c) / 10;
    if (x > 200 && x < 0xfd && y > 0x81 && y < 0x8d)
        return 8;
    if (flag && x > 200 && x < 0xfd && y > 0x6d && y < 0x79)
        return 9;
    return 0xff;
}

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    if (size < 3 * sizeof(int32_t))
        return 0;

    int32_t x, y, flag;
    __builtin_memcpy(&x,    data,                    sizeof(int32_t));
    __builtin_memcpy(&y,    data + sizeof(int32_t),  sizeof(int32_t));
    __builtin_memcpy(&flag, data + 2*sizeof(int32_t), sizeof(int32_t));

    int r   = FUN_1000_d840(x, y, flag);
    int ref = ref_coord_to_zone(x, y, flag);

    /* Must match reference. */
    assert(r == ref);

    /* Return value must be a valid zone index or the sentinel 0xff. */
    assert((r >= 0 && r <= 9) || r == 0xff);

    return 0;
}
