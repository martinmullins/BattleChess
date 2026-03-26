/*
 * ghidra_types.h - Type definitions for Ghidra-decompiled code
 *
 * Maps Ghidra internal types to Open Watcom / C89-compatible equivalents
 * for 16-bit x86 DOS compilation.
 */
#ifndef GHIDRA_TYPES_H
#define GHIDRA_TYPES_H

#include <stddef.h>

/* Ghidra undefined byte-width types */
typedef unsigned char   undefined1;
typedef unsigned short  undefined2;
typedef unsigned long   undefined4;

/* Common integer aliases used by Ghidra output */
typedef unsigned char   byte;
typedef unsigned char   bool;
typedef unsigned int    uint;
typedef unsigned short  ushort;
typedef unsigned long   ulong;

/* Boolean constants */
#define true  1
#define false 0

/* Ghidra calling convention shims for Open Watcom */
#ifndef __cdecl16near
#define __cdecl16near __cdecl
#endif
#ifndef __cdecl16far
#define __cdecl16far __cdecl __far
#endif

/* DOS interrupt / BIOS helper (stub; real DOS calls go via int86) */
#ifndef MK_FP
#define MK_FP(seg, off) ((void __far *)(((unsigned long)(seg) << 16) | (unsigned short)(off)))
#endif


/* Ghidra CONCAT macros: combine two N-byte values into one 2N-byte value.
 * In 16-bit real mode, CONCAT22 forms a segment:offset far pointer.
 * We store as unsigned long; cast to (byte *) truncates to near offset only
 * which is correct for small-model code that stays within one segment.
 */
#define CONCAT11(hi, lo) ((unsigned short)((unsigned char)(hi) << 8 | (unsigned char)(lo)))
/* CONCAT22: pack segment:offset into unsigned long (hi=segment, lo=offset)
 * Cast hi to unsigned long BEFORE shifting to avoid W135 (shift on 16-bit type) */
#define CONCAT22(hi, lo) (((unsigned long)(unsigned short)(hi) << 16) | (unsigned short)(unsigned int)(lo))
/* Ghidra sub-field access macros */
#define GH_HI16(v)       ((unsigned short)((unsigned long)(v) >> 16))
#define GH_LO16(v)       ((unsigned short)(unsigned long)(v))


/* Ghidra function pointer type: callable via (*(code *)ptr)(args) */
/* Returns uint to allow result capture from swi/interrupt calls */
typedef uint (*code)();

/* Ghidra carry/borrow arithmetic helpers.
 * CARRY2(a,b)   - unsigned carry out of 16-bit addition a+b
 * CARRY1(a,b)   - unsigned carry out of 8-bit addition a+b
 * SBORROW2(a,b) - signed borrow: overflow from signed 16-bit subtraction a-b
 * SUB21(a,b)    - sign-extended 8-bit minus unsigned 16-bit
 */
#define CARRY1(a,b)   ((unsigned char)(b) > (unsigned char)(~(a)))
#define CARRY2(a,b)   ((unsigned short)(b) > (unsigned short)(~(a)))
#define SBORROW2(a,b) ((short)(b) > (short)(a))
#define SUB21(a,b)    ((int)(signed char)(a) - (int)(unsigned short)(b))

/* DOS hardware I/O: use Open Watcom intrinsics that generate IN/OUT instructions */
#include <conio.h>
#define in(port)          ((unsigned short)inp((unsigned)(port)))
#define out(port,val)     outp((unsigned)(port),(unsigned)(val))
/* swi(num): software interrupt - Ghidra artifact for INT n; return value is
 * a decompiler artifact; use 0 since we can't reconstruct register state. */
#define swi(num)          ((int)((void)(num),0))
#define halt_baddata()    ((void)0)

/* Stub for unresolved Ghidra cross-segment function references */
#define _GHIDRA_STUB(name) static void name(void) {}

#endif /* GHIDRA_TYPES_H */
