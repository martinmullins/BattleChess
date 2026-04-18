/*
 * fuzz_max_int.c — LibFuzzer harness for max_int variants.
 *
 * Targets: FUN_1000_8fa5, FUN_1000_fe0c
 * Cross-validation: both must return the same result for all inputs.
 *
 * Build:
 *   clang -fsanitize=fuzzer,address,undefined -O1 -o fuzz_max_int \
 *         fuzz_max_int.c tier1_impl.c
 */
#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include "tier1_impl.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    if (size < 2 * sizeof(int32_t))
        return 0;

    int32_t a, b;
    __builtin_memcpy(&a, data,                  sizeof(int32_t));
    __builtin_memcpy(&b, data + sizeof(int32_t), sizeof(int32_t));

    int r1 = FUN_1000_8fa5(a, b);
    int r2 = FUN_1000_fe0c(a, b);

    assert(r1 == r2);

    assert(r1 >= a);
    assert(r1 >= b);
    assert(r1 == a || r1 == b);

    return 0;
}
