/*
 * fuzz_compute_row_bitmasks.c — FUN_1000_fce8
 *
 * Scans the 8×8 board state (64 bytes at 0x1166) and writes 8 row bitmasks
 * to 0x9230..0x9237.  param_1 selects which player's pieces to map:
 *   param_1 == 0 → player B (cells with bit 6 set)
 *   param_1 != 0 → player A (cells with bit 6 clear)
 *
 * Piece encoding: bits[2:0] = piece type (0 = empty), bit 6 = player flag.
 *
 * Invariants (verified against an inline reference):
 *   - For each row r, bit c of output[r] is set iff:
 *       board[r*8+c] has a piece AND belongs to the selected player
 *   - Only addresses 0x9230..0x9237 are written; board state unchanged
 *
 * Build:
 *   clang -fsanitize=fuzzer,address,undefined -O1 -o fuzz_compute_row_bitmasks \
 *         fuzz_compute_row_bitmasks.c tier3_impl.c seg_storage.c
 */
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include "tier3_impl.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    /* 64 bytes board + 1 byte param_1 */
    if (size < 65)
        return 0;

    memset(g_chess_seg, 0, sizeof(g_chess_seg));

    /* Load board state. */
    for (int i = 0; i < 64; i++)
        GSEG((uint16_t)(SEG_BOARD_STATE + i), uint8_t) = data[i];

    int param_1 = data[64] & 1;  /* only bit 0 is semantically relevant */

    FUN_1000_fce8(param_1);

    /* Verify each row bitmask against the inline reference. */
    for (int row = 0; row < 8; row++) {
        uint8_t expected = 0;
        for (int col = 0; col < 8; col++) {
            uint8_t cell = GSEG((uint16_t)(SEG_BOARD_STATE + row * 8 + col), uint8_t);
            if ((cell & 7) != 0) {
                if ((cell & 0x40) == 0) {
                    if (param_1 != 0)
                        expected |= (uint8_t)(1u << col);
                } else if (param_1 == 0) {
                    expected |= (uint8_t)(1u << col);
                }
            }
        }
        uint16_t mask_addr = (uint16_t)(SEG_ROW_BMASK_0 + row);
        assert(GSEG(mask_addr, uint8_t) == expected);
    }

    /* Board state must be unchanged. */
    for (int i = 0; i < 64; i++)
        assert(GSEG((uint16_t)(SEG_BOARD_STATE + i), uint8_t) == data[i]);

    return 0;
}
