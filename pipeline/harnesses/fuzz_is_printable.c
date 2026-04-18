/*
 * fuzz_is_printable.c — LibFuzzer harness for FUN_1000_d8f6 (is_printable_ascii).
 *
 * Build:
 *   clang -fsanitize=fuzzer,address,undefined -O1 -o fuzz_is_printable \
 *         fuzz_is_printable.c tier1_impl.c
 */
#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include "tier1_impl.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    if (size < sizeof(int32_t))
        return 0;

    int32_t a;
    __builtin_memcpy(&a, data, sizeof(int32_t));

    int r = FUN_1000_d8f6(a);

    /* Return value must be 0 or 1. */
    assert(r == 0 || r == 1);

    /* Cross-validate against known-good reference. */
    int expected = (a > 0x1f && a < 0x7f) ? 1 : 0;
    assert(r == expected);

    return 0;
}
