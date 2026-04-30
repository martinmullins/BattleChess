/*
 * fuzz_mul32.c — FUN_1000_f32e
 *
 * Lower 32 bits of the product of two signed 32-bit integers, each passed as
 * a pair of 16-bit halves: A = (param_2 << 16) | param_1,
 *                           B = (param_4 << 16) | param_3.
 *
 * When param_2 == 0 && param_4 == 0, reduces to uint16 × uint16 → uint32.
 *
 * Invariant (verified against native 64-bit multiply):
 *   result == (uint32_t)((int32_t)A * (int32_t)B)
 *
 * Build:
 *   clang -fsanitize=fuzzer,address,undefined -O1 -o fuzz_mul32 \
 *         fuzz_mul32.c tier1_impl.c
 */
#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include "tier1_impl.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    if (size < 8)
        return 0;

    uint16_t p1 = (uint16_t)(data[0] | (data[1] << 8));
    int16_t  p2 = (int16_t) (data[2] | (data[3] << 8));
    uint16_t p3 = (uint16_t)(data[4] | (data[5] << 8));
    int16_t  p4 = (int16_t) (data[6] | (data[7] << 8));

    uint32_t result = FUN_1000_f32e(p1, p2, p3, p4);

    /* Ground truth: lower 32 bits of signed 64-bit product. */
    int32_t  A = ((int32_t)(int16_t)p2 << 16) | (uint16_t)p1;
    int32_t  B = ((int32_t)(int16_t)p4 << 16) | (uint16_t)p3;
    uint32_t expected = (uint32_t)((int64_t)A * (int64_t)B);

    assert(result == expected);
    return 0;
}
