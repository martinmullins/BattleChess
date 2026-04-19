#ifndef TIER3_IMPL_H
#define TIER3_IMPL_H

#include <stdint.h>
#include "ghidra_compat.h"
#include "tier2_seg.h"

/* save_game_regs / restore_game_regs (FUN_1000_2c46 / FUN_1000_2c79) */
#define SEG_GR_SRC_0   0x936c  /* uint16 — live game-register 0  */
#define SEG_GR_SRC_1   0xb07e  /* uint16 — live game-register 1  */
#define SEG_GR_SRC_2   0x96    /* uint16 — live game-register 2  */
#define SEG_GR_SRC_3   0x94    /* uint16 — live game-register 3  */
#define SEG_GR_SRC_4   0x98    /* uint16 — live game-register 4  */
#define SEG_GR_SRC_5   0x92    /* uint16 — live game-register 5  */
#define SEG_GR_SRC_6   0x9238  /* uint16 — live game-register 6  */
#define SEG_GR_SRC_7   0x923a  /* uint16 — live game-register 7  */

#define SEG_GR_DST_0   0x933e  /* uint16 — saved-register slot 0 */
#define SEG_GR_DST_1   0xa84e  /* uint16 — saved-register slot 1 */
#define SEG_GR_DST_2   0x8180  /* uint16 — saved-register slot 2 */
#define SEG_GR_DST_3   0x8186  /* uint16 — saved-register slot 3 */
#define SEG_GR_DST_4   0x936e  /* uint16 — saved-register slot 4 */
#define SEG_GR_DST_5   0x987e  /* uint16 — saved-register slot 5 */
#define SEG_GR_DST_6   0x9368  /* uint16 — saved-register slot 6 */
#define SEG_GR_DST_7   0x936a  /* uint16 — saved-register slot 7 */

/* clamp_text_size (FUN_1000_8a64) */
#define SEG_TS_WIDTH   0x53f2  /* uint16 — raw text-cell width   */
#define SEG_TS_HEIGHT  0x53f4  /* int16  — raw text-cell height  */
#define SEG_TS_DIRTY   0xcbd2  /* uint16 — dirty flag            */
#define SEG_TS_ZAP     0x934c  /* uint16 — zeroed sentinel       */
#define SEG_TS_CLAMP_W 0x818a  /* uint16 — clamped width output  */
#define SEG_TS_CLAMP_H 0x818c  /* int16  — clamped height output */

void FUN_1000_2c46(void);
void FUN_1000_2c79(void);
void FUN_1000_8a64(void);

#endif /* TIER3_IMPL_H */
