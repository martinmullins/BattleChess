/*
 * fuzz_offset_sentinel.c — LibFuzzer harness for FUN_1000_fd4e (offset_with_sentinel).
 *
 * Adds 0x14 (20) to the input, with a special substitution:
 *   input -0x7248  →  output -0x72d4  (instead of the normal -0x7234)
 *
 * Build:
 *   clang -fsanitize=fuzzer,address,undefined -O1 -o fuzz_offset_sentinel \
 *         fuzz_offset_sentinel.c tier1_impl.c
 */
#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include "tier1_impl.h"

static int ref_offset_sentinel(int a)
{
    int r = a + 0x14;
    if (r == -0x7234)
        r = -0x72d4;
    return r;
}

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    if (size < sizeof(int32_t))
        return 0;

    int32_t a;
    __builtin_memcpy(&a, data, sizeof(int32_t));

    /* Skip inputs that would cause signed overflow (INT_MAX - 0x13 onwards). */
    if (a > (int32_t)0x7FFFFFEB)
        return 0;

    int r   = FUN_1000_fd4e(a);
    int ref = ref_offset_sentinel(a);

    assert(r == ref);

    /* Sentinel check: the one special-cased input must produce the right output. */
    if (a == -0x7248) {
        assert(r == -0x72d4);
    } else {
        assert(r == a + 0x14);
    }

    return 0;
}
