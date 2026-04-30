/*
 * fuzz_next_slot_fwd.c — FUN_1000_db3d
 *
 * Scans forward (mod 8) through a circular 8-entry slot table, skipping entries
 * whose occupancy byte (at offset +0x0f within each 0x10-byte entry) equals -1.
 * Returns the index of the first occupied slot found after the start.
 *
 * Invariants:
 *   - returned slot is occupied (sentinel != -1)
 *   - every slot between (start+1 mod 8) and the returned slot is empty
 *
 * Build:
 *   clang -fsanitize=fuzzer,address,undefined -O1 -o fuzz_next_slot_fwd \
 *         fuzz_next_slot_fwd.c tier3_impl.c seg_storage.c
 */
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include "tier3_impl.h"

#define SLOT_BASE  0x2000   /* fixed base address for the slot table */
#define SLOT_OFFY  0x0f     /* occupancy byte offset within each 0x10-byte entry */

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    /* 8 occupancy bytes + 1 start slot byte */
    if (size < 9)
        return 0;

    /* Need at least one occupied slot to avoid an infinite loop. */
    int any_occupied = 0;
    for (int i = 0; i < 8; i++)
        if ((int8_t)data[i] != -1) { any_occupied = 1; break; }
    if (!any_occupied)
        return 0;

    memset(g_chess_seg, 0, sizeof(g_chess_seg));

    for (int i = 0; i < 8; i++)
        GSEG((uint16_t)(SLOT_BASE + i * 0x10 + SLOT_OFFY), uint8_t) = data[i];

    int start  = (int)(data[8] % 8);
    int result = FUN_1000_db3d(SLOT_BASE, start);

    /* Result must be a valid slot index. */
    assert(result >= 0 && result <= 7);

    /* The returned slot must be occupied. */
    assert(GSEG((uint16_t)(SLOT_BASE + result * 0x10 + SLOT_OFFY), int8_t) != -1);

    /* Every slot scanned before result must be empty. */
    int slot = (start + 1) % 8;
    while (slot != result) {
        assert(GSEG((uint16_t)(SLOT_BASE + slot * 0x10 + SLOT_OFFY), int8_t) == -1);
        slot = (slot + 1) % 8;
    }

    return 0;
}
