/*
 * fuzz_is_odd.c — LibFuzzer harness for FUN_1000_fe4a (is_odd).
 *
 * Build:
 *   clang -fsanitize=fuzzer,address,undefined -O1 -o fuzz_is_odd \
 *         fuzz_is_odd.c tier1_impl.c
 */
#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include "tier1_impl.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    if (size < sizeof(uint32_t))
        return 0;

    uint32_t a;
    __builtin_memcpy(&a, data, sizeof(uint32_t));

    uint r = FUN_1000_fe4a(a);

    assert(r == 0 || r == 1);
    assert(r == (a & 1));

    return 0;
}
