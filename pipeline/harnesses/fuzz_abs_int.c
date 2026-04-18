/*
 * fuzz_abs_int.c — LibFuzzer harness for abs_int variants.
 *
 * Targets: FUN_1000_8fb5, FUN_1000_fdf2
 * Cross-validation: both must return the same result for all inputs.
 *
 * Note: INT_MIN abs is undefined behaviour in C.  We exclude it so UBSan
 * doesn't fire on a known platform limitation rather than a real bug.
 *
 * Build:
 *   clang -fsanitize=fuzzer,address,undefined -O1 -o fuzz_abs_int \
 *         fuzz_abs_int.c tier1_impl.c
 */
#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include <limits.h>
#include "tier1_impl.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    if (size < sizeof(int32_t))
        return 0;

    int32_t a;
    __builtin_memcpy(&a, data, sizeof(int32_t));

    /* Skip INT_MIN: -INT_MIN overflows in C (UB), original 16-bit code wraps. */
    if (a == INT_MIN)
        return 0;

    int r1 = FUN_1000_8fb5(a);
    int r2 = FUN_1000_fdf2(a);

    assert(r1 == r2);
    assert(r1 >= 0);

    return 0;
}
