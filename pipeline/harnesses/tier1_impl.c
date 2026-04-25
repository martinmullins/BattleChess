/*
 * tier1_impl.c — Tier 1 pure function implementations extracted from CHESS.EXE.
 *
 * Source: src/chess.c (Ghidra headless decompilation of CHESS.EXE).
 * These functions are copied verbatim except for FUN_1000_f1d6 whose register
 * parameters are promoted to explicit function arguments (see note in header).
 *
 * Build target: native Linux x86-64 with clang -fsanitize=fuzzer,address,undefined.
 */
#include "tier1_impl.h"

/* ---- FUN_1000_8f95 @ 1000:8f95  min(a, b) ---- */
int FUN_1000_8f95(int param_1, int param_2)
{
    if (param_2 < param_1) {
        param_1 = param_2;
    }
    return param_1;
}

/* ---- FUN_1000_8fa5 @ 1000:8fa5  max(a, b) ---- */
int FUN_1000_8fa5(int param_1, int param_2)
{
    if (param_1 < param_2) {
        param_1 = param_2;
    }
    return param_1;
}

/* ---- FUN_1000_8fb5 @ 1000:8fb5  abs(a) ---- */
int FUN_1000_8fb5(int param_1)
{
    if (0 < param_1) {
        return param_1;
    }
    return -param_1;
}

/* ---- FUN_1000_d840 @ 1000:d840  coord_to_zone(x, y, flag) ---- */
int FUN_1000_d840(int param_1, int param_2, int param_3)
{
    if ((((0x3c < param_1) && (param_1 < 0xbb)) && (0x3c < param_2)) && (param_2 < 0x8b)) {
        return (param_2 + -0x3c) / 10;
    }
    if (((200 < param_1) && (param_1 < 0xfd)) && ((0x81 < param_2 && (param_2 < 0x8d)))) {
        return 8;
    }
    if (((param_3 != 0) && (200 < param_1)) &&
        ((param_1 < 0xfd && ((0x6d < param_2 && (param_2 < 0x79)))))) {
        return 9;
    }
    return 0xff;
}

/* ---- FUN_1000_d8f6 @ 1000:d8f6  is_printable_ascii ---- */
int FUN_1000_d8f6(int param_1)
{
    if ((0x1f < param_1) && (param_1 < 0x7f)) {
        return 1;
    }
    return 0;
}

/*
 * ---- FUN_1000_f1d6 @ 1000:f1d6  div32_reg ----
 *
 * Original Ghidra output used register-passed params (emitted as `uint param_N = 0`).
 * Rewritten with explicit uint16_t arguments so the fuzzer can supply all four
 * independent inputs.  The body is unchanged — only the signature differs.
 */
undefined4 FUN_1000_f1d6(uint16_t p1, uint16_t p2, uint16_t p3, uint16_t p4)
{
    uint uVar1 = (uint16_t)(p2 - p4);
    uint uVar2 = uVar1 * 0x10 + p1;
    return CONCAT22(
        (((((uint)(p2 < p4) * (uint)-2 + (uint)CARRY2(uVar1, uVar1)) * 2 +
           (uint)CARRY2(uVar1 * 2, uVar1 * 2)) * 2 +
          (uint)CARRY2(uVar1 * 4, uVar1 * 4)) * 2 +
         (uint)CARRY2(uVar1 * 8, uVar1 * 8) + (uint)CARRY2(uVar1 * 0x10, p1)) -
            (uint)(uVar2 < p3),
        uVar2 - p3);
}

/* ---- FUN_1000_fd4e @ 1000:fd4e  offset_with_sentinel ---- */
int FUN_1000_fd4e(int param_1)
{
    param_1 = param_1 + 0x14;
    if (param_1 == -0x7234) {
        param_1 = -0x72d4;
    }
    return param_1;
}

/* ---- FUN_1000_fdf2 @ 1000:fdf2  abs(a) variant ---- */
int FUN_1000_fdf2(int param_1)
{
    if (param_1 < 0) {
        param_1 = -param_1;
    }
    return param_1;
}

/* ---- FUN_1000_fe0c @ 1000:fe0c  max(a, b) variant ---- */
int FUN_1000_fe0c(int param_1, int param_2)
{
    if (param_2 <= param_1) {
        param_2 = param_1;
    }
    return param_2;
}

/* ---- FUN_1000_fe2b @ 1000:fe2b  min(a, b) variant ---- */
int FUN_1000_fe2b(int param_1, int param_2)
{
    if (param_1 <= param_2) {
        param_2 = param_1;
    }
    return param_2;
}

/* ---- FUN_1000_fe4a @ 1000:fe4a  is_odd ---- */
uint FUN_1000_fe4a(uint param_1)
{
    return param_1 & 1;
}

/*
 * ---- FUN_1000_f32e @ 1000:f32e  mul32 ----
 *
 * Lower 32 bits of the product of two signed 32-bit integers, each supplied as
 * a (hi, lo) uint16/int16 pair: A = param_2:param_1, B = param_4:param_3.
 * When both high halves are zero it reduces to a plain 16×16→32 unsigned multiply.
 * Signature derived by promoting Ghidra's register-implicit params to explicit args.
 */
uint32_t FUN_1000_f32e(uint16_t param_1, int16_t param_2, uint16_t param_3, int16_t param_4)
{
    if (param_4 == 0 && param_2 == 0)
        return (uint32_t)param_1 * (uint32_t)param_3;
    uint32_t prod = (uint32_t)param_1 * (uint32_t)param_3;
    uint16_t hi   = (uint16_t)((uint16_t)(prod >> 16)
                              + (uint16_t)((int)param_2 * (int)param_3)
                              + (uint16_t)((int)param_1 * (int)param_4));
    return ((uint32_t)hi << 16) | (uint16_t)prod;
}
