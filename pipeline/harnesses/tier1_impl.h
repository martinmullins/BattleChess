#ifndef TIER1_IMPL_H
#define TIER1_IMPL_H

#include "ghidra_compat.h"

/* min(a, b) */
int  FUN_1000_8f95(int param_1, int param_2);
/* max(a, b) */
int  FUN_1000_8fa5(int param_1, int param_2);
/* abs(a) — condition: 0 < a */
int  FUN_1000_8fb5(int param_1);
/* coord_to_zone(x, y, flag) */
int  FUN_1000_d840(int param_1, int param_2, int param_3);
/* is_printable_ascii */
int  FUN_1000_d8f6(int param_1);
/* div32_reg — register params rewritten as explicit uint16 args */
undefined4 FUN_1000_f1d6(uint16_t p1, uint16_t p2, uint16_t p3, uint16_t p4);
/* offset + 0x14, sentinel at -0x7234 → -0x72d4 */
int  FUN_1000_fd4e(int param_1);
/* abs(a) — condition: a < 0 */
int  FUN_1000_fdf2(int param_1);
/* max(a, b) variant */
int  FUN_1000_fe0c(int param_1, int param_2);
/* min(a, b) variant */
int  FUN_1000_fe2b(int param_1, int param_2);
/* is_odd: param_1 & 1 */
uint FUN_1000_fe4a(uint param_1);
/* mul32: lower 32 bits of signed 32-bit × 32-bit, inputs as 16-bit halves */
uint32_t FUN_1000_f32e(uint16_t param_1, int16_t param_2, uint16_t param_3, int16_t param_4);

#endif /* TIER1_IMPL_H */
