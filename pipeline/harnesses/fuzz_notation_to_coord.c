/*
 * fuzz_notation_to_coord.c — FUN_1000_8856
 *
 * Converts chess notation (column char, row char) to a 0x88 board index.
 * The column char is first run through flag_byte_check (FUN_1000_f1bc):
 * if bit 0 of the flag table entry for that char is set, 0x20 is added
 * (upper→lower case fold).
 *
 * Valid after folding: column in ['a'..'h'], row in ['1'..'8'].
 * Result = row_char * 0x10 + col_char - 0x371 => [0x00, 0x77].
 * Invalid inputs return 0.
 *
 * Input layout (3 bytes):
 *   data[0] — param_1  (column char)
 *   data[1] — param_2  (row char)
 *   data[2] — flag byte stored at flag_table[param_1]
 *
 * Invariants:
 *   - for valid notation: result in [0, 0x77]
 *   - for invalid notation: result == 0
 *   - segment is not modified by the call
 *
 * Build:
 *   clang -fsanitize=fuzzer,address,undefined -O1 -o fuzz_notation_to_coord \
 *         fuzz_notation_to_coord.c tier3_impl.c tier1_impl.c seg_storage.c
 */
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include "tier3_impl.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    if (size < 3)
        return 0;

    char    p1   = (char)data[0];
    char    p2   = (char)data[1];
    uint8_t flag = data[2];

    memset(g_chess_seg, 0, sizeof(g_chess_seg));

    /* Place flag byte at the address FUN_1000_f1bc will read. */
    uint16_t flag_addr = (uint16_t)(SEG_FLAG_TABLE + (int)p1);
    GSEG(flag_addr, uint8_t) = flag;

    int result = FUN_1000_8856(p1, p2);

    /* Compute what cVar1 should be. */
    char cVar1 = (char)FUN_1000_f1bc((int)p1);

    int valid = (('`' < cVar1) && (cVar1 < 'i')) &&
                (('0' < p2)    && (p2    < '9'));

    if (valid) {
        assert(result >= 0 && result <= 0x77);
        int expected = (int16_t)((int)p2 * 0x10 + (int)cVar1 + -0x371);
        assert(result == expected);
    } else {
        assert(result == 0);
    }

    /* Segment must be unchanged (function only reads). */
    assert(GSEG(flag_addr, uint8_t) == flag);

    return 0;
}
