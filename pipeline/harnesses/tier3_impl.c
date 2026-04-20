/*
 * tier3_impl.c — Tier 3 function implementations extracted from CHESS.EXE.
 *
 * These functions operate on the same g_chess_seg[65536] segment overlay as
 * the Tier 2 functions.  All *(type *)0xADDR accesses are replaced with
 * GSEG(addr, type).  All 16-bit DOS int/uint widths are preserved by using
 * int16_t/uint16_t rather than 32-bit int (avoids 2-byte-apart address overlap).
 *
 * Source lines in src/chess.c noted per function.
 */
#include "tier3_impl.h"

/* ---- FUN_1000_2c46 @ 1000:2c46  save_game_regs  (src line 3252) ---- */
void FUN_1000_2c46(void)
{
    uint16_t uVar1;
    GSEG(SEG_GR_DST_0, uint16_t) = GSEG(SEG_GR_SRC_0, uint16_t);
    GSEG(SEG_GR_DST_1, uint16_t) = GSEG(SEG_GR_SRC_1, uint16_t);
    GSEG(SEG_GR_DST_2, uint16_t) = GSEG(SEG_GR_SRC_2, uint16_t);
    GSEG(SEG_GR_DST_3, uint16_t) = GSEG(SEG_GR_SRC_3, uint16_t);
    GSEG(SEG_GR_DST_4, uint16_t) = GSEG(SEG_GR_SRC_4, uint16_t);
    GSEG(SEG_GR_DST_5, uint16_t) = GSEG(SEG_GR_SRC_5, uint16_t);
    uVar1 = GSEG(SEG_GR_SRC_7, uint16_t);      /* preserve load order from src */
    GSEG(SEG_GR_DST_6, uint16_t) = GSEG(SEG_GR_SRC_6, uint16_t);
    GSEG(SEG_GR_DST_7, uint16_t) = uVar1;
}

/* ---- FUN_1000_2c79 @ 1000:2c79  restore_game_regs  (src line 3274) ---- */
void FUN_1000_2c79(void)
{
    uint16_t uVar1;
    GSEG(SEG_GR_SRC_0, uint16_t) = GSEG(SEG_GR_DST_0, uint16_t);
    GSEG(SEG_GR_SRC_1, uint16_t) = GSEG(SEG_GR_DST_1, uint16_t);
    GSEG(SEG_GR_SRC_2, uint16_t) = GSEG(SEG_GR_DST_2, uint16_t);
    GSEG(SEG_GR_SRC_3, uint16_t) = GSEG(SEG_GR_DST_3, uint16_t);
    GSEG(SEG_GR_SRC_4, uint16_t) = GSEG(SEG_GR_DST_4, uint16_t);
    GSEG(SEG_GR_SRC_5, uint16_t) = GSEG(SEG_GR_DST_5, uint16_t);
    uVar1 = GSEG(SEG_GR_DST_7, uint16_t);      /* preserve load order from src */
    GSEG(SEG_GR_SRC_6, uint16_t) = GSEG(SEG_GR_DST_6, uint16_t);
    GSEG(SEG_GR_SRC_7, uint16_t) = uVar1;
}

/* ---- FUN_1000_8a64 @ 1000:8a64  clamp_text_size  (src line 8244) ---- */
/*
 * Addresses 0x53f2 and 0x53f4 are 2 bytes apart; DOS int/uint are 16-bit.
 * Using int16_t/uint16_t here avoids the 4-byte overlap bug (same pattern as
 * nav_col/nav_row at 0x86/0x88 in tier2_impl.c).
 */
void FUN_1000_8a64(void)
{
    uint16_t uVar1;
    int16_t  iVar2;
    GSEG(SEG_TS_DIRTY,   uint16_t) = 1;
    GSEG(SEG_TS_ZAP,     uint16_t) = 0;
    uVar1 = GSEG(SEG_TS_WIDTH,  uint16_t);
    iVar2 = GSEG(SEG_TS_HEIGHT, int16_t);
    GSEG(SEG_TS_CLAMP_W, uint16_t) = uVar1;
    GSEG(SEG_TS_CLAMP_H, int16_t)  = iVar2;
    if ((iVar2 < 1) && ((iVar2 < 0) || (uVar1 < 3))) {
        GSEG(SEG_TS_CLAMP_W, uint16_t) = 3;
        GSEG(SEG_TS_CLAMP_H, int16_t)  = 0;
    }
}

/* ---- FUN_1000_2cac @ 1000:2cac  save_game_regs_b  (src line ~3290) ---- */
/* Same 8 SRC addresses as FUN_1000_2c46; writes to the alternate slot-B bank. */
void FUN_1000_2cac(void)
{
    uint16_t uVar1;
    GSEG(SEG_GR_DSTB_0, uint16_t) = GSEG(SEG_GR_SRC_0, uint16_t);
    GSEG(SEG_GR_DSTB_1, uint16_t) = GSEG(SEG_GR_SRC_1, uint16_t);
    GSEG(SEG_GR_DSTB_2, uint16_t) = GSEG(SEG_GR_SRC_2, uint16_t);
    GSEG(SEG_GR_DSTB_3, uint16_t) = GSEG(SEG_GR_SRC_3, uint16_t);
    GSEG(SEG_GR_DSTB_4, uint16_t) = GSEG(SEG_GR_SRC_4, uint16_t);
    GSEG(SEG_GR_DSTB_5, uint16_t) = GSEG(SEG_GR_SRC_5, uint16_t);
    uVar1 = GSEG(SEG_GR_SRC_7, uint16_t);
    GSEG(SEG_GR_DSTB_6, uint16_t) = GSEG(SEG_GR_SRC_6, uint16_t);
    GSEG(SEG_GR_DSTB_7, uint16_t) = uVar1;
}

/* ---- FUN_1000_2ce0 @ 1000:2ce0  restore_game_regs_b  (src line ~3308) ---- */
/* Exact inverse of FUN_1000_2cac. */
void FUN_1000_2ce0(void)
{
    uint16_t uVar1;
    GSEG(SEG_GR_SRC_0, uint16_t) = GSEG(SEG_GR_DSTB_0, uint16_t);
    GSEG(SEG_GR_SRC_1, uint16_t) = GSEG(SEG_GR_DSTB_1, uint16_t);
    GSEG(SEG_GR_SRC_2, uint16_t) = GSEG(SEG_GR_DSTB_2, uint16_t);
    GSEG(SEG_GR_SRC_3, uint16_t) = GSEG(SEG_GR_DSTB_3, uint16_t);
    GSEG(SEG_GR_SRC_4, uint16_t) = GSEG(SEG_GR_DSTB_4, uint16_t);
    GSEG(SEG_GR_SRC_5, uint16_t) = GSEG(SEG_GR_DSTB_5, uint16_t);
    uVar1 = GSEG(SEG_GR_DSTB_7, uint16_t);
    GSEG(SEG_GR_SRC_6, uint16_t) = GSEG(SEG_GR_DSTB_6, uint16_t);
    GSEG(SEG_GR_SRC_7, uint16_t) = uVar1;
}

/* ---- FUN_1000_29b9 @ 1000:29b9  init_callback_table  (src line ~3105) ---- */
/*
 * Writes 8 DOS far-pointers (offset:segment pairs) to fixed segment addresses.
 * All share the same code segment 0x5cc2; offsets identify each callback entry
 * point.  In the harness these are treated as opaque uint16 constants.
 */
void FUN_1000_29b9(void)
{
    GSEG(SEG_CB0_OFF, uint16_t) = 0x2cee;  GSEG(SEG_CB0_SEG, uint16_t) = 0x5cc2;
    GSEG(SEG_CB1_OFF, uint16_t) = 0x2d0e;  GSEG(SEG_CB1_SEG, uint16_t) = 0x5cc2;
    GSEG(SEG_CB2_OFF, uint16_t) = 0x2d8a;  GSEG(SEG_CB2_SEG, uint16_t) = 0x5cc2;
    GSEG(SEG_CB3_OFF, uint16_t) = 0x2dbe;  GSEG(SEG_CB3_SEG, uint16_t) = 0x5cc2;
    GSEG(SEG_CB4_OFF, uint16_t) = 0x2b2e;  GSEG(SEG_CB4_SEG, uint16_t) = 0x5cc2;
    GSEG(SEG_CB5_OFF, uint16_t) = 0x2b4e;  GSEG(SEG_CB5_SEG, uint16_t) = 0x5cc2;
    GSEG(SEG_CB6_OFF, uint16_t) = 0x2bca;  GSEG(SEG_CB6_SEG, uint16_t) = 0x5cc2;
    GSEG(SEG_CB7_OFF, uint16_t) = 0x2bfe;  GSEG(SEG_CB7_SEG, uint16_t) = 0x5cc2;
}
