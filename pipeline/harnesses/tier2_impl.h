#ifndef TIER2_IMPL_H
#define TIER2_IMPL_H

#include <stdint.h>
#include "ghidra_compat.h"
#include "tier2_seg.h"

/* Segment address constants (for documentation + harness clarity) */
#define SEG_NAV_COL        0x86   /* int16 — horizontal nav index [0-7] */
#define SEG_NAV_ROW        0x88   /* int16 — vertical   nav index [0-7] */
#define SEG_ANIM_FLAG      0x44de /* byte  — animation gate             */
#define SEG_TEXT_POS       0x4a02 /* int16 — text output position       */
#define SEG_TEXT_COL       0x4a04 /* int16 — text column (auto-cleared) */
#define SEG_VP_SRC_0       0x4e2  /* int16 — viewport source reg 0      */
#define SEG_VP_SRC_1       0x4e4  /* int16 — viewport source reg 1      */
#define SEG_VP_SRC_2       0x4e6  /* int16 — viewport source reg 2      */
#define SEG_VP_SRC_3       0x4e8  /* int16 — viewport source reg 3      */
#define SEG_CHAR_VAL       0x53a  /* byte  — character for next cell     */
#define SEG_FG_COLOR       0x53c  /* byte  — foreground color nibble    */
#define SEG_BG_COLOR       0x53e  /* byte  — background color nibble    */
#define SEG_VP_DSTA_0      0x85a4 /* int16 — push dst a, slot 0         */
#define SEG_VP_DSTA_1      0x85a6 /* int16 — push dst a, slot 1         */
#define SEG_VP_DSTA_2      0x85a8 /* int16 — push dst a, slot 2         */
#define SEG_VP_DSTA_3      0x85aa /* int16 — push dst a, slot 3         */
#define SEG_TEXT_BOLD      0x8176 /* char  — bold flag (0/1)            */
#define SEG_TEXT_ULINE     0x8188 /* char  — underline flag (0/1)       */
#define SEG_VP_SNAP_0      0x88dc /* int16 — viewport snapshot slot 0   */
#define SEG_VP_SNAP_1      0x88de /* int16 — viewport snapshot slot 1   */
#define SEG_VP_SNAP_2      0x88e0 /* int16 — viewport snapshot slot 2   */
#define SEG_VP_SNAP_3      0x88e2 /* int16 — viewport snapshot slot 3   */
#define SEG_STACK_DEPTH    0x9880 /* int16 — viewport stack depth       */
#define SEG_TEXT_BLINK     0xef6  /* char  — blink flag (0/1)           */

/* Push-viewport table bounds (from decompiled loop: local_4 = -0x68 to stack_depth) */
#define SEG_VP_TABLE_BASE  0x7714 /* base address of push table (0x7714 = -(-0x7714)) */
#define VP_TABLE_ENTRY_SZ  8      /* 8 bytes per entry (4 x int16) */

void     FUN_1000_e45c(void);
void     FUN_1000_f2de(uint16_t param_1);
uint16_t FUN_1000_fd6a(char param_1);
void     FUN_1000_931c(int param_1, uint8_t param_2);
void     FUN_1000_7da8(void);
void     FUN_1000_7c52(void);

#endif /* TIER2_IMPL_H */
