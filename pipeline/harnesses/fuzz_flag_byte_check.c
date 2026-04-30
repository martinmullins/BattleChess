/*
 * fuzz_flag_byte_check.c — FUN_1000_f1bc
 *
 * Reads one byte from a global flag table at base 0x4a1f + param_1.
 * If bit 0 of that byte is set, returns param_1 + 0x20; else returns param_1.
 *
 * Invariants:
 *   - result == param_1 + 0x20  iff  (flag_table[param_1] & 1) != 0
 *   - result == param_1          otherwise
 *   - no other segment addresses are modified
 *
 * Build:
 *   clang -fsanitize=fuzzer,address,undefined -O1 -o fuzz_flag_byte_check \
 *         fuzz_flag_byte_check.c tier3_impl.c seg_storage.c
 */
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include "tier3_impl.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    if (size < 2)
        return 0;

    memset(g_chess_seg, 0, sizeof(g_chess_seg));

    /* Constrain param_1 to [0, 0xDF] so param_1 + 0x20 never wraps 8-bit. */
    int param_1 = data[0] & 0xFF;
    uint8_t flag_byte = data[1];

    GSEG((uint16_t)(param_1 + SEG_FLAG_TABLE), uint8_t) = flag_byte;

    int result = FUN_1000_f1bc(param_1);

    if (flag_byte & 1) {
        assert(result == param_1 + 0x20);
    } else {
        assert(result == param_1);
    }
    return 0;
}
