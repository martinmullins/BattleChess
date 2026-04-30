# BattleChess Binary Porting Pipeline — Strategy & Architecture

## Background

**Target**: `CHESS.EXE` — a 16-bit DOS chess game (BattleChess). The binary has been disassembled and decompiled by Ghidra into `src/chess.c`, which contains raw Ghidra output: unnamed functions (`FUN_1000_XXXX`), untyped variables (`undefined2`, `iVar1`), and hard-coded segment addresses (`*(int *)0x4a02`).

**Goal**: Systematically port every function from the Ghidra decompilation into clean, testable C with named functions, correct types, and verified behavior — building a portable reimplementation of the game logic.

---

## Architecture

All DOS segment memory accesses (`*(type *)0xADDR`) are mapped through a single 64 KB array:

```c
uint8_t g_chess_seg[65536];
#define GSEG(addr, type) (*(type *)(g_chess_seg + (addr)))
```

This lets the code run natively on any platform while preserving the original memory layout.

---

## Tier System

Functions are classified into three tiers based on their dependencies:

| Tier | Criteria | Examples |
|------|----------|---------|
| **1** | Pure arithmetic — no globals, no calls, no pointer dereference | `min_int`, `abs_int`, `mul32`, `div32` |
| **2** | Reads/writes `g_chess_seg` directly | `handle_nav_key`, `pack_char_cell`, `snapshot_viewport` |
| **3** | Stateful like tier 2, but discovered/ported later; may call tier 1/2 functions | `save_game_regs`, `rand_step`, `notation_to_coord` |

---

## Pipeline Steps (per batch of functions)

1. **Identify candidates** — grep `src/chess.c` for functions with no external calls (or only already-ported calls), short bodies, clear logic
2. **Port** — translate Ghidra output into clean C in `tier{N}_impl.c`, replacing `*(type *)0xADDR` with `GSEG(addr, type)`, adding named constants to `tier{N}_impl.h`
3. **Harness** — write a `fuzz_{name}.c` LibFuzzer harness with `assert`-based invariant checks; create seed files
4. **Oracle** — add a `sweep_*()` function to `oracle_driver.c` that exhaustively exercises the function and emits NDJSON records (`{"fn":…,"tier":…,"args":…,"seg_in":…,"seg_out":…,"ret":…}`)
5. **Quality analysis** — run `analyze_quality.py` which measures per-function: corpus pass rate, type recovery score, LOC delta vs. reference, and tier classification accuracy

---

## Current Progress

**31 functions ported across 5 batches. All pass at 1.0000 corpus pass rate.**

### Tier 1 (12 functions)
`min_int` × 2, `max_int` × 2, `abs_int` × 2, `is_odd`, `is_printable_ascii`, `coord_to_zone`, `offset_sentinel`, `div32`, `mul32`

### Tier 2 (6 functions)
`clear_anim_flag`, `set_text_cursor`, `handle_nav_key`, `pack_char_cell`, `snapshot_viewport`, `push_viewport`

### Tier 3 (13 functions)
`save_game_regs` (slots A+B), `restore_game_regs` (slots A+B), `clamp_text_size`, `init_callback_table`, `flag_byte_check`, `compute_row_bitmasks`, `write_tile_entry`, `next_slot_fwd`, `next_slot_bwd`, `rand_step`, `notation_to_coord`

### Quality metrics (latest run)
- Oracle records: 70,971
- Tier confirmed: 30/31 (one expected NO — `notation_to_coord` accesses the segment indirectly via a callee, which the heuristic misses)
- Avg pass rate: 1.0000
- Avg type recovery score: 0.46
- Avg LOC delta: +3.0 (Ghidra output is ~3 lines noisier than the clean reference per function)

---

## Key Technical Decisions

- **`GSEG` macro** replaces all `*(type *)0xADDR` patterns — safe, auditable, portable
- **16-bit width preservation**: DOS `int` is 16-bit; all segment-adjacent fields use `int16_t`/`uint16_t` to avoid 4-byte overlap bugs
- **Oracle key uniqueness**: `seg_in` must include all addresses the function *reads*, not just writes, so the pass-rate checker can distinguish different input states
- **Brace-depth counting**: Python's `re` can't handle nested braces for body extraction; replaced with explicit character scanning
- **Tier 1 linked into Tier 3 builds**: `FUN_1000_f2f0` (rand_step) calls `FUN_1000_f32e` (mul32, tier 1), so all tier 3 Makefile targets also link `tier1_impl.c`

---

## Remaining Work / Next Steps

- Continue identifying and porting functions from `src/chess.c` — there are hundreds remaining
- Natural next candidates: functions that call only already-ported functions, have short bodies, and clear semantics
- Eventual goal: full reimplementation of game logic (move generation, AI, board rendering pipeline) in portable C with 100% oracle-verified behavior
