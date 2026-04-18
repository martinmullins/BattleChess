/*
 * tier2_impl.c — Tier 2 function implementations extracted from CHESS.EXE.
 *
 * All hardcoded DOS segment addresses  *(type *)0xADDR  are replaced with
 * GSEG(addr, type)  which reads from/writes to the  g_chess_seg[65536]  mock.
 * 16-bit address arithmetic is preserved by casting offsets through uint16_t
 * to reproduce DOS wrap-around behaviour.
 *
 * Source lines in src/chess.c noted per function.
 */
#include "tier2_impl.h"

uint8_t g_chess_seg[65536];

/* ---- FUN_1000_e45c @ 1000:e45c  clear_anim_flag  (src line 13672) ---- */
void FUN_1000_e45c(void)
{
    GSEG(SEG_ANIM_FLAG, uint8_t) = 0;
}

/* ---- FUN_1000_f2de @ 1000:f2de  set_text_cursor  (src line 14977) ---- */
void FUN_1000_f2de(uint16_t param_1)
{
    GSEG(SEG_TEXT_POS, uint16_t) = param_1;
    GSEG(SEG_TEXT_COL, uint16_t) = 0;
}

/* ---- FUN_1000_fd6a @ 1000:fd6a  handle_nav_key  (src line 15921) ---- */
/*
 * Original DOS code uses 16-bit int for these registers; they are 2 bytes
 * apart (0x86, 0x88) so we must use int16_t to avoid 4-byte overlap.
 */
uint16_t FUN_1000_fd6a(char param_1)
{
    int16_t iVar1;
    uint16_t uVar2;

    if (param_1 == 'H') {
        iVar1 = (GSEG(SEG_NAV_ROW, int16_t) < 1) ? 7 : GSEG(SEG_NAV_ROW, int16_t) - 1;
        GSEG(SEG_NAV_ROW, int16_t) = iVar1;
        uVar2 = 1;
    } else if (param_1 == 'K') {
        iVar1 = (GSEG(SEG_NAV_COL, int16_t) < 1) ? 7 : GSEG(SEG_NAV_COL, int16_t) - 1;
        GSEG(SEG_NAV_COL, int16_t) = iVar1;
        uVar2 = 1;
    } else if (param_1 == 'M') {
        iVar1 = (GSEG(SEG_NAV_COL, int16_t) < 7) ? GSEG(SEG_NAV_COL, int16_t) + 1 : 0;
        GSEG(SEG_NAV_COL, int16_t) = iVar1;
        uVar2 = 1;
    } else if (param_1 == 'P') {
        iVar1 = (GSEG(SEG_NAV_ROW, int16_t) < 7) ? GSEG(SEG_NAV_ROW, int16_t) + 1 : 0;
        GSEG(SEG_NAV_ROW, int16_t) = iVar1;
        uVar2 = 1;
    } else {
        uVar2 = 0;
    }
    return uVar2;
}

/*
 * ---- FUN_1000_931c @ 1000:931c  pack_char_cell  (src line 8833) ----
 *
 * Writes a CGA-style 2-byte text cell into an output buffer.
 *
 * param_1: base address of the text buffer (treated as index into g_chess_seg
 *          for the harness — use a safe sub-range).
 * param_2: column offset; cell is written at base + col*2.
 *
 * byte[0] = char value      (seg[0x53a])
 * byte[1] = attr packed as: (bg & 3) | ((fg & 3) << 2) | (bold*0x40) | (uline*0x20) | (blink*0x10)
 */
void FUN_1000_931c(int param_1, uint8_t param_2)
{
    uint16_t off = (uint16_t)(param_1 + (unsigned)param_2 * 2);
    GSEG(off,     uint8_t) = GSEG(SEG_CHAR_VAL, uint8_t);
    GSEG(off + 1, uint8_t) =
        (GSEG(SEG_BG_COLOR,    uint8_t) & 3) |
        ((GSEG(SEG_FG_COLOR,   uint8_t) & 3) << 2) |
        (uint8_t)((int8_t)GSEG(SEG_TEXT_BOLD,  int8_t)  * 0x40) |
        (uint8_t)((int8_t)GSEG(SEG_TEXT_ULINE, int8_t)  * 0x20) |
        (uint8_t)((int8_t)GSEG(SEG_TEXT_BLINK, int8_t)  * 0x10);
}

/* ---- FUN_1000_7da8 @ 1000:7da8  snapshot_viewport  (src line 7220) ---- */
void FUN_1000_7da8(void)
{
    GSEG(SEG_STACK_DEPTH, uint16_t) = 0xffff;
    GSEG(SEG_VP_SNAP_0,   uint16_t) = GSEG(SEG_VP_SRC_0, uint16_t);
    GSEG(SEG_VP_SNAP_1,   uint16_t) = GSEG(SEG_VP_SRC_1, uint16_t);
    GSEG(SEG_VP_SNAP_2,   uint16_t) = GSEG(SEG_VP_SRC_2, uint16_t);
    GSEG(SEG_VP_SNAP_3,   uint16_t) = GSEG(SEG_VP_SRC_3, uint16_t);
}

/*
 * ---- FUN_1000_7c52 @ 1000:7c52  push_viewport  (src line 7125) ----
 *
 * Decrements stack_depth, shifts viewport table down one slot, then
 * writes viewport_src into the new top-of-stack slot.
 *
 * Table layout (16-bit wrap arithmetic preserved with uint16_t casts):
 *   entry[i] occupies 8 bytes at base address (uint16_t)(i*8 - 0x771c)
 *   source (next slot) is at                  (uint16_t)(i*8 - 0x7714)
 *
 * The loop copies entries [−0x68 .. new_stack_depth] downward by 8 bytes,
 * then stores viewport_src at the dst_a registers (0x85a4-0x85aa).
 */
void FUN_1000_7c52(void)
{
    int16_t local_4;

    GSEG(SEG_STACK_DEPTH, int16_t) = GSEG(SEG_STACK_DEPTH, int16_t) - 1;

    for (local_4 = -0x68; local_4 <= GSEG(SEG_STACK_DEPTH, int16_t); local_4++) {
        int iVar1 = (int16_t)(local_4 * 8);
        uint16_t dst0 = (uint16_t)(iVar1 + (int16_t)(-0x771c));
        uint16_t src0 = (uint16_t)(iVar1 + (int16_t)(-0x7714));
        GSEG(dst0,     uint16_t) = GSEG(src0,     uint16_t);
        GSEG(dst0 + 2, uint16_t) = GSEG(src0 + 2, uint16_t);
        GSEG(dst0 + 4, uint16_t) = GSEG(src0 + 4, uint16_t);
        GSEG(dst0 + 6, uint16_t) = GSEG(src0 + 6, uint16_t);
    }

    GSEG(SEG_VP_DSTA_0, uint16_t) = GSEG(SEG_VP_SRC_0, uint16_t);
    GSEG(SEG_VP_DSTA_1, uint16_t) = GSEG(SEG_VP_SRC_1, uint16_t);
    GSEG(SEG_VP_DSTA_2, uint16_t) = GSEG(SEG_VP_SRC_2, uint16_t);
    GSEG(SEG_VP_DSTA_3, uint16_t) = GSEG(SEG_VP_SRC_3, uint16_t);
}
