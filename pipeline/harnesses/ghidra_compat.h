/*
 * ghidra_compat.h — 64-bit compatible re-mapping of Ghidra decompiler types.
 *
 * Replaces the DOS/Open-Watcom ghidra_types.h for building Tier 1 functions
 * as a native Linux fuzz target.  Only the types and macros actually used by
 * the 11 Tier 1 pure functions are included.
 */
#ifndef GHIDRA_COMPAT_H
#define GHIDRA_COMPAT_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef uint8_t   undefined1;
typedef uint16_t  undefined2;
typedef uint32_t  undefined4;

typedef uint8_t   byte;
typedef uint32_t  uint;    /* In DOS 16-bit code uint==16-bit; we widen to 32 here. */
typedef uint16_t  ushort;
typedef uint32_t  ulong;

/* Ghidra carry/overflow helpers — keep bit widths matching original 16-bit code. */
#define CARRY1(a,b)   ((uint8_t)(b)  > (uint8_t)(~(uint8_t)(a)))
#define CARRY2(a,b)   ((uint16_t)(b) > (uint16_t)(~(uint16_t)(a)))
#define SBORROW2(a,b) ((int16_t)(b)  > (int16_t)(a))

/* CONCAT22: pack two 16-bit halves into a 32-bit value. */
#define CONCAT22(hi,lo) \
    (((uint32_t)(uint16_t)(hi) << 16) | (uint16_t)(lo))

#endif /* GHIDRA_COMPAT_H */
