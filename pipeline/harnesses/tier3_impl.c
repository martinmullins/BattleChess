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

/* ---- FUN_1000_f1bc @ 1000:f1bc  flag_byte_check  (src line ~14807) ---- */
/*
 * Reads one byte from a flag table at base 0x4a1f + param_1.
 * If bit 0 is set, returns param_1 + 0x20; otherwise returns param_1.
 * DOS int is 16-bit; address arithmetic is done via uint16_t cast.
 */
int FUN_1000_f1bc(int param_1)
{
    if ((GSEG((uint16_t)(param_1 + 0x4a1f), uint8_t) & 1) != 0) {
        return param_1 + 0x20;
    }
    return param_1;
}

/* ---- FUN_1000_fce8 @ 1000:fce8  compute_row_bitmasks  (src line ~8090) ---- */
/*
 * For each of 8 board rows, scans 8 columns and sets a bit in the row's
 * output byte for every cell that belongs to the selected player.
 *
 * Board layout: byte[row*8 + col] at 0x1166.
 *   bits[2:0] = piece type (0 = empty)
 *   bit  6    = player flag (0 = player A, 1 = player B)
 *
 * param_1 == 0 → output bitmasks for player B (bit6 set)
 * param_1 != 0 → output bitmasks for player A (bit6 clear)
 *
 * Output: byte[row] at (uint16_t)(row - 0x6dd0) = 0x9230 + row
 */
void FUN_1000_fce8(int param_1)
{
    for (int iVar2 = 0; iVar2 < 8; iVar2++) {
        uint16_t row_addr = (uint16_t)(iVar2 - 0x6dd0);
        GSEG(row_addr, uint8_t) = 0;
        for (int iVar3 = 0; iVar3 < 8; iVar3++) {
            uint16_t cell_addr = (uint16_t)(iVar2 * 8 + iVar3 + 0x1166);
            uint8_t bVar1 = GSEG(cell_addr, uint8_t);
            if ((bVar1 & 7) != 0) {
                if ((bVar1 & 0x40) == 0) {
                    if (param_1 != 0)
                        GSEG(row_addr, uint8_t) |= (uint8_t)('\x01' << ((uint8_t)iVar3 & 0x1f));
                } else if (param_1 == 0) {
                    GSEG(row_addr, uint8_t) |= (uint8_t)('\x01' << ((uint8_t)iVar3 & 0x1f));
                }
            }
        }
    }
}

/* ---- FUN_1000_7dbf @ 1000:7dbf  write_tile_entry ----
 *
 * Writes a byte pair at stride-4 offset into the tile table at 0xa8ba.
 *   tile_table[param_3 * 4 + 0] = param_1   (value byte)
 *   tile_table[param_3 * 4 + 1] = param_2   (flag byte)
 *
 * Address: (uint16_t)(param_3 * 4 + -0x5746) = 0xa8ba + param_3 * 4
 */
void FUN_1000_7dbf(uint8_t param_1, uint8_t param_2, int param_3)
{
    GSEG((uint16_t)(param_3 * 4 - 0x5746), uint8_t) = param_1;
    GSEG((uint16_t)(param_3 * 4 - 0x5745), uint8_t) = param_2;
}

/* ---- FUN_1000_db3d @ 1000:db3d  next_slot_fwd ----
 *
 * Advances slot index forward (mod 8) until a non-empty slot is found.
 * Each slot is 0x10 bytes; occupancy sentinel is at byte offset 0x0f.
 * Occupied: sentinel != -1.  Empty: sentinel == -1 (0xff as int8_t).
 *
 * param_1 = base address of the 8-element slot table in g_chess_seg
 * param_2 = starting slot index (0–7)
 */
int FUN_1000_db3d(int param_1, int param_2)
{
    do {
        param_2 = param_2 + 1;
        if (7 < param_2) param_2 = 0;
    } while (GSEG((uint16_t)(param_1 + param_2 * 0x10 + 0xf), int8_t) == -1);
    return param_2;
}

/* ---- FUN_1000_db65 @ 1000:db65  next_slot_bwd ----
 *
 * Same as FUN_1000_db3d but scans backwards (mod 8).
 */
int FUN_1000_db65(int param_1, int param_2)
{
    do {
        param_2 = param_2 - 1;
        if (param_2 < 0) param_2 = 7;
    } while (GSEG((uint16_t)(param_1 + param_2 * 0x10 + 0xf), int8_t) == -1);
    return param_2;
}
