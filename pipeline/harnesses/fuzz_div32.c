/*
 * fuzz_div32.c — LibFuzzer harness for FUN_1000_f1d6 (div32_reg).
 *
 * This is a 16-bit carry-arithmetic 32-bit operation (likely long division or
 * multiply-high) whose exact semantics are inferred from the carry chain in the
 * decompiled body.  The harness validates the result against an inline reference
 * that replicates the same carry arithmetic.
 *
 * Build:
 *   clang -fsanitize=fuzzer,address,undefined -O1 -o fuzz_div32 \
 *         fuzz_div32.c tier1_impl.c
 */
#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include "ghidra_compat.h"
#include "tier1_impl.h"

/*
 * Inline reference: identical to tier1_impl.c but expressed independently so
 * any divergence between the two expresses a transcription error, not a bug.
 */
static uint32_t ref_div32(uint16_t p1, uint16_t p2, uint16_t p3, uint16_t p4)
{
    uint32_t uVar1 = (uint16_t)(p2 - p4);
    uint32_t uVar2 = uVar1 * 0x10 + p1;
    uint32_t hi =
        (((((uint32_t)(p2 < p4) * (uint32_t)-2 + (uint32_t)CARRY2(uVar1, uVar1)) * 2 +
           (uint32_t)CARRY2(uVar1 * 2, uVar1 * 2)) * 2 +
          (uint32_t)CARRY2(uVar1 * 4, uVar1 * 4)) * 2 +
         (uint32_t)CARRY2(uVar1 * 8, uVar1 * 8) +
         (uint32_t)CARRY2(uVar1 * 0x10, p1)) -
        (uint32_t)(uVar2 < p3);
    return CONCAT22(hi, uVar2 - p3);
}

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    if (size < 4 * sizeof(uint16_t))
        return 0;

    uint16_t p1, p2, p3, p4;
    __builtin_memcpy(&p1, data,                    sizeof(uint16_t));
    __builtin_memcpy(&p2, data +   sizeof(uint16_t), sizeof(uint16_t));
    __builtin_memcpy(&p3, data + 2*sizeof(uint16_t), sizeof(uint16_t));
    __builtin_memcpy(&p4, data + 3*sizeof(uint16_t), sizeof(uint16_t));

    uint32_t r   = FUN_1000_f1d6(p1, p2, p3, p4);
    uint32_t ref = ref_div32(p1, p2, p3, p4);

    assert(r == ref);

    return 0;
}
