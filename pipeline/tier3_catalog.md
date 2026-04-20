# Tier 3 Function Catalog — BattleChess Pipeline

## Definition

Tier 3 extends the Tier 2 stateful cohort with additional global-access-only functions
not in the initial Tier 2 batch.  All three functions here:

- Read and write a bounded set of hardcoded DOS segment addresses via GSEG
- Make no external function calls (pure state transformation)
- Are individually harness-testable under the existing 64 KB segment overlay

The most important new validation pattern introduced at this tier is **save/restore
cross-validation**: `FUN_1000_2c46` and `FUN_1000_2c79` are exact inverses, so the
roundtrip `save → corrupt → restore` must be an identity on all 8 source registers.

---

## Global Address Map (new symbols)

| Address | Width | Semantic name      | Used by       |
|---------|-------|--------------------|---------------|
| `0x92`  | int16 | game_reg_src_5     | 2c46, 2c79    |
| `0x94`  | int16 | game_reg_src_3     | 2c46, 2c79    |
| `0x96`  | int16 | game_reg_src_2     | 2c46, 2c79    |
| `0x98`  | int16 | game_reg_src_4     | 2c46, 2c79    |
| `0x933e`| int16 | game_reg_dst_0     | 2c46, 2c79    |
| `0x9238`| int16 | game_reg_src_6     | 2c46, 2c79    |
| `0x923a`| int16 | game_reg_src_7     | 2c46, 2c79    |
| `0x9368`| int16 | game_reg_dst_6     | 2c46, 2c79    |
| `0x936a`| int16 | game_reg_dst_7     | 2c46, 2c79    |
| `0x936c`| int16 | game_reg_src_0     | 2c46, 2c79    |
| `0x936e`| int16 | game_reg_dst_4     | 2c46, 2c79    |
| `0x987e`| int16 | game_reg_dst_5     | 2c46, 2c79    |
| `0xa84e`| int16 | game_reg_dst_1     | 2c46, 2c79    |
| `0xb07e`| int16 | game_reg_src_1     | 2c46, 2c79    |
| `0x53f2`| int16 | text_size_width    | 8a64          |
| `0x53f4`| int16 | text_size_height   | 8a64          |
| `0x818a`| int16 | text_clamp_width   | 8a64          |
| `0x818c`| int16 | text_clamp_height  | 8a64          |
| `0x934c`| int16 | text_size_zap      | 8a64          |
| `0xcbd2`| int16 | text_size_dirty    | 8a64          |

> **16-bit width note**: All addresses at offsets `0x92–0x98`, `0x818a/818c`, and
> `0x53f2/53f4` are 2 bytes apart.  The tier3_impl.c uses `int16_t`/`uint16_t` for
> all these (not 32-bit `int`) to avoid the 4-byte overlap bug documented in tier2.

---

## Functions

### FUN_1000_2c46 — `save_game_regs`  (src line 3252)

```c
void FUN_1000_2c46(void)
{
    uint16_t uVar1;
    uVar1 = GSEG(SEG_GR_SRC_7, uint16_t);          /* load src_7 before overwrite */
    GSEG(SEG_GR_DST_0..7) = GSEG(SEG_GR_SRC_0..7); /* 8 copies */
}
```

**Role**: Snapshot 8 "live game registers" into a save-area.  Called at context
switch boundaries before the game state changes hands.

**Harness**: `fuzz_save_game_regs.c`
- Seeds all 8 SRC addresses with fuzz data
- Asserts every DST slot == corresponding SRC after call
- Asserts SRC slots are untouched

---

### FUN_1000_2c79 — `restore_game_regs`  (src line 3274)

```c
void FUN_1000_2c79(void)
{
    uint16_t uVar1;
    uVar1 = GSEG(SEG_GR_DST_7, uint16_t);          /* preserve load order */
    GSEG(SEG_GR_SRC_0..7) = GSEG(SEG_GR_DST_0..7); /* exact inverse of 2c46 */
}
```

**Role**: Exact inverse of `save_game_regs`.

**Harness**: `fuzz_restore_game_regs.c`
- Verifies SRC[i] == DST[i] after call
- **Roundtrip cross-validation**: `save(X) → corrupt SRC → restore()` must return
  `SRC == X` for all 16-bit inputs.  This is the only harness that calls two
  functions in sequence, providing mutual verification.

---

### FUN_1000_8a64 — `clamp_text_size`  (src line 8244)

```c
void FUN_1000_8a64(void)
{
    GSEG(SEG_TS_DIRTY, uint16_t) = 1;   /* always mark dirty */
    GSEG(SEG_TS_ZAP,   uint16_t) = 0;   /* always zero sentinel */
    uint16_t w = GSEG(SEG_TS_WIDTH,  uint16_t);
    int16_t  h = GSEG(SEG_TS_HEIGHT, int16_t);
    GSEG(SEG_TS_CLAMP_W, uint16_t) = w;
    GSEG(SEG_TS_CLAMP_H, int16_t)  = h;
    if ((h < 1) && ((h < 0) || (w < 3))) {
        GSEG(SEG_TS_CLAMP_W, uint16_t) = 3;  /* minimum width */
        GSEG(SEG_TS_CLAMP_H, int16_t)  = 0;  /* reset height  */
    }
}
```

**Role**: Copies raw text-cell dimensions to the clamped output registers,
enforcing a minimum of (width=3, height=0) for degenerate sizes.

**Clamping condition** (from decompiled source):
```
clamp if: (h < 1) AND ((h < 0) OR (w < 3))
      ↔  h < 0,  OR  (h == 0 AND w < 3)
```

**Harness**: `fuzz_clamp_text_size.c`
- Verifies dirty=1 and zap=0 unconditionally
- Checks pass-through vs clamp against the inline reference predicate

---

## Quality Metrics (from Step 6 analysis)

| Symbol         | Name               | PassRate | TypeScore | DecompLOC | RefLOC | LOCDelta |
|----------------|--------------------|----------|-----------|-----------|--------|----------|
| FUN_1000_2c46  | save_game_regs     | 1.0000   | 0.30      | 5         | 3      | +2       |
| FUN_1000_2c79  | restore_game_regs  | 1.0000   | 0.30      | 5         | 3      | +2       |
| FUN_1000_8a64  | clamp_text_size    | 1.0000   | 0.30      | 7         | 5      | +2       |

**Type score note**: The 0.30 reflects Ghidra's use of `undefined2`, `unaff_DS`, and
unnamed `uVar`/`iVar` locals — consistent with all other Tier 2/3 stateful functions.
The behavioral pass rate of 1.0000 confirms the implementation is correct.

---

## Infrastructure Changes

| File                          | Change                                              |
|-------------------------------|-----------------------------------------------------|
| `harnesses/tier3_impl.h`      | New — 20 SEG_ address constants + 3 prototypes      |
| `harnesses/tier3_impl.c`      | New — GSEG implementations of 3 functions           |
| `harnesses/seg_storage.c`     | New — standalone `g_chess_seg[65536]` definition    |
| `harnesses/fuzz_save_game_regs.c`    | New — harness                                |
| `harnesses/fuzz_restore_game_regs.c` | New — harness + roundtrip cross-validation   |
| `harnesses/fuzz_clamp_text_size.c`   | New — harness                                |
| `harnesses/Makefile`          | Updated — TIER3_TARGETS, TIER3_CHECK, seg_storage   |
| `oracle/oracle_driver.c`      | Extended — Tier 2 + Tier 3 state-delta sweeps (+481 LOC)|
| `oracle/analyze_quality.py`   | Extended — all-tier report, state_pass_rate()       |
