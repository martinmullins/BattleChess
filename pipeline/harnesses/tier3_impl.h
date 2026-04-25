#ifndef TIER3_IMPL_H
#define TIER3_IMPL_H

#include <stdint.h>
#include "ghidra_compat.h"
#include "tier2_seg.h"

/* save_game_regs / restore_game_regs — slot A (FUN_1000_2c46 / FUN_1000_2c79) */
#define SEG_GR_SRC_0   0x936c  /* uint16 — live game-register 0  */
#define SEG_GR_SRC_1   0xb07e  /* uint16 — live game-register 1  */
#define SEG_GR_SRC_2   0x96    /* uint16 — live game-register 2  */
#define SEG_GR_SRC_3   0x94    /* uint16 — live game-register 3  */
#define SEG_GR_SRC_4   0x98    /* uint16 — live game-register 4  */
#define SEG_GR_SRC_5   0x92    /* uint16 — live game-register 5  */
#define SEG_GR_SRC_6   0x9238  /* uint16 — live game-register 6  */
#define SEG_GR_SRC_7   0x923a  /* uint16 — live game-register 7  */

#define SEG_GR_DST_0   0x933e  /* uint16 — slot-A save area 0 */
#define SEG_GR_DST_1   0xa84e  /* uint16 — slot-A save area 1 */
#define SEG_GR_DST_2   0x8180  /* uint16 — slot-A save area 2 */
#define SEG_GR_DST_3   0x8186  /* uint16 — slot-A save area 3 */
#define SEG_GR_DST_4   0x936e  /* uint16 — slot-A save area 4 */
#define SEG_GR_DST_5   0x987e  /* uint16 — slot-A save area 5 */
#define SEG_GR_DST_6   0x9368  /* uint16 — slot-A save area 6 */
#define SEG_GR_DST_7   0x936a  /* uint16 — slot-A save area 7 */

/* save_game_regs_b / restore_game_regs_b — slot B (FUN_1000_2cac / FUN_1000_2ce0)
 * Same 8 SRC addresses; different destination bank. */
#define SEG_GR_DSTB_0  0xb0ca  /* uint16 — slot-B save area 0 */
#define SEG_GR_DSTB_1  0xb080  /* uint16 — slot-B save area 1 */
#define SEG_GR_DSTB_2  0x95fe  /* uint16 — slot-B save area 2 */
#define SEG_GR_DSTB_3  0x8e22  /* uint16 — slot-B save area 3 */
#define SEG_GR_DSTB_4  0xa834  /* uint16 — slot-B save area 4 */
#define SEG_GR_DSTB_5  0x964e  /* uint16 — slot-B save area 5 */
#define SEG_GR_DSTB_6  0x9344  /* uint16 — slot-B save area 6 */
#define SEG_GR_DSTB_7  0x9346  /* uint16 — slot-B save area 7 */

/* clamp_text_size (FUN_1000_8a64) */
#define SEG_TS_WIDTH   0x53f2  /* uint16 — raw text-cell width   */
#define SEG_TS_HEIGHT  0x53f4  /* int16  — raw text-cell height  */
#define SEG_TS_DIRTY   0xcbd2  /* uint16 — dirty flag            */
#define SEG_TS_ZAP     0x934c  /* uint16 — zeroed sentinel       */
#define SEG_TS_CLAMP_W 0x818a  /* uint16 — clamped width output  */
#define SEG_TS_CLAMP_H 0x818c  /* int16  — clamped height output */

/* init_callback_table (FUN_1000_29b9) — 8 far-pointer pairs (offset:segment) */
#define SEG_CB0_OFF  0x9240   /* uint16 — callback 0 offset  */
#define SEG_CB0_SEG  0x9242   /* uint16 — callback 0 segment */
#define SEG_CB1_OFF  0x8de4   /* uint16 — callback 1 offset  */
#define SEG_CB1_SEG  0x8de6   /* uint16 — callback 1 segment */
#define SEG_CB2_OFF  0x9648   /* uint16 — callback 2 offset  */
#define SEG_CB2_SEG  0x964a   /* uint16 — callback 2 segment */
#define SEG_CB3_OFF  0x817c   /* uint16 — callback 3 offset  */
#define SEG_CB3_SEG  0x817e   /* uint16 — callback 3 segment */
#define SEG_CB4_OFF  0x987a   /* uint16 — callback 4 offset  */
#define SEG_CB4_SEG  0x987c   /* uint16 — callback 4 segment */
#define SEG_CB5_OFF  0x9848   /* uint16 — callback 5 offset  */
#define SEG_CB5_SEG  0x984a   /* uint16 — callback 5 segment */
#define SEG_CB6_OFF  0xa8b6   /* uint16 — callback 6 offset  */
#define SEG_CB6_SEG  0xa8b8   /* uint16 — callback 6 segment */
#define SEG_CB7_OFF  0x8d00   /* uint16 — callback 7 offset  */
#define SEG_CB7_SEG  0x8d02   /* uint16 — callback 7 segment */

/* Hardcoded far-pointer values written by FUN_1000_29b9 */
#define CB_SEG_COMMON  0x5cc2  /* segment portion — same for all 8 callbacks */
static const uint16_t CB_OFFSETS[8] = {
    0x2cee, 0x2d0e, 0x2d8a, 0x2dbe, 0x2b2e, 0x2b4e, 0x2bca, 0x2bfe
};
static const uint16_t CB_OFF_ADDRS[8] = {
    SEG_CB0_OFF, SEG_CB1_OFF, SEG_CB2_OFF, SEG_CB3_OFF,
    SEG_CB4_OFF, SEG_CB5_OFF, SEG_CB6_OFF, SEG_CB7_OFF,
};
static const uint16_t CB_SEG_ADDRS[8] = {
    SEG_CB0_SEG, SEG_CB1_SEG, SEG_CB2_SEG, SEG_CB3_SEG,
    SEG_CB4_SEG, SEG_CB5_SEG, SEG_CB6_SEG, SEG_CB7_SEG,
};

/* flag_byte_check (FUN_1000_f1bc) */
#define SEG_FLAG_TABLE   0x4a1f  /* byte[] — flag table, indexed by param_1 */

/* compute_row_bitmasks (FUN_1000_fce8) */
#define SEG_BOARD_STATE  0x1166  /* byte[64] — 8×8 board (row-major)        */
#define SEG_ROW_BMASK_0  0x9230  /* byte[8]  — row bitmasks (= -0x6dd0+0)   */

/* write_tile_entry (FUN_1000_7dbf) — stride-4 table at 0xa8ba */
#define SEG_TILE_TABLE   0xa8ba  /* byte[0] of entry at index i: 0xa8ba + i*4 */

/* next_slot_fwd / next_slot_bwd (FUN_1000_db3d / FUN_1000_db65)
 * 8-element circular slot table; each entry is 0x10 bytes; occupancy byte at +0x0f */

void FUN_1000_2c46(void);
void FUN_1000_2c79(void);
void FUN_1000_8a64(void);
void FUN_1000_2cac(void);
void FUN_1000_2ce0(void);
void FUN_1000_29b9(void);
int  FUN_1000_f1bc(int param_1);
void FUN_1000_fce8(int param_1);
void FUN_1000_7dbf(uint8_t param_1, uint8_t param_2, int param_3);
int  FUN_1000_db3d(int param_1, int param_2);
int  FUN_1000_db65(int param_1, int param_2);

#endif /* TIER3_IMPL_H */
