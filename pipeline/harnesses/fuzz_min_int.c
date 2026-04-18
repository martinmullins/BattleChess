/*
 * fuzz_min_int.c — LibFuzzer harness for min_int variants.
 *
 * Targets: FUN_1000_8f95, FUN_1000_fe2b
 * Both implement min(a, b) with slightly different compare directions.
 * Cross-validation: both must return the same result for all inputs.
 *
 * Build:
 *   clang -fsanitize=fuzzer,address,undefined -O1 -o fuzz_min_int \
 *         fuzz_min_int.c tier1_impl.c
 *
 * Run:
 *   ./fuzz_min_int seeds/min_int/
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

    int r1 = FUN_1000_8f95(a, b);
    int r2 = FUN_1000_fe2b(a, b);

    /* Cross-validate: both variants must agree. */
    assert(r1 == r2);

    /* Sanity: result must be <= both inputs. */
    assert(r1 <= a);
    assert(r1 <= b);
    /* And must equal one of them. */
    assert(r1 == a || r1 == b);

    return 0;
}
