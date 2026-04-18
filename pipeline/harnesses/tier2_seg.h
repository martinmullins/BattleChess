/*
 * tier2_seg.h — 64 KB segment overlay for Tier 2 function fuzzing.
 *
 * Tier 2 functions use hardcoded DOS segment addresses (*(int *)0x88 etc.).
 * On 64-bit Linux those addresses are unmapped.  We mock the full 16-bit
 * data segment as a static byte array and redirect all accesses through
 * the GSEG() macro.
 *
 * Usage in implementations:
 *   #include "tier2_seg.h"
 *   // replace  *(int *)0x88  with  GSEG(0x88, int)
 *
 * Usage in harnesses:
 *   memset(g_chess_seg, 0, sizeof(g_chess_seg));
 *   GSEG(0x88, int) = initial_value_from_fuzz;
 *   call_function(...);
 *   assert(GSEG(0x88, int) == expected);
 */
#ifndef TIER2_SEG_H
#define TIER2_SEG_H

#include <stdint.h>
#include <string.h>

/* The full 16-bit DOS data segment, zero-initialised. */
extern uint8_t g_chess_seg[65536];

/* Type-safe accessor: GSEG(0x88, int) == *(int *)(g_chess_seg + 0x88) */
#define GSEG(addr, type)  (*(type *)(g_chess_seg + (unsigned)(addr)))

#endif /* TIER2_SEG_H */
