/*
 * fuzz_rand_step.c — FUN_1000_f2f0
 *
 * One step of the BattleChess LCG: state = state * 0x343fd + 0x269ec3
 * State is stored as two 16-bit words at SEG_RNG_LO / SEG_RNG_HI.
 * Returns upper 15 bits of new state.
 *
 * Invariants:
 *   - return value is in [0, 0x7fff]
 *   - new state words match the LCG formula exactly
 *
 * Build:
 *   clang -fsanitize=fuzzer,address,undefined -O1 -o fuzz_rand_step \
 *         fuzz_rand_step.c tier3_impl.c tier1_impl.c seg_storage.c
 */
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include "tier3_impl.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    if (size < 4)
        return 0;

    uint16_t state_lo = (uint16_t)(data[0] | ((uint16_t)data[1] << 8));
    uint16_t state_hi = (uint16_t)(data[2] | ((uint16_t)data[3] << 8));

    memset(g_chess_seg, 0, sizeof(g_chess_seg));
    GSEG(SEG_RNG_LO, uint16_t) = state_lo;
    GSEG(SEG_RNG_HI, uint16_t) = state_hi;

    uint result = FUN_1000_f2f0();

    /* Return value must be in [0, 0x7fff]. */
    assert(result <= 0x7fff);

    /* Verify state matches LCG: new_state = old_state * 0x343fd + 0x269ec3. */
    uint32_t lVar2    = FUN_1000_f32e(state_lo, (int16_t)state_hi, 0x43fd, 3);
    uint32_t expected = lVar2 + 0x269ec3U;
    assert(GSEG(SEG_RNG_LO, uint16_t) == (uint16_t)expected);
    assert(GSEG(SEG_RNG_HI, uint16_t) == (uint16_t)(expected >> 16));
    assert(result == (uint)((expected >> 16) & 0x7fff));

    return 0;
}
