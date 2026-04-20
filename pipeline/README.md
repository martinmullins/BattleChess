# Binary Porting Pipeline — BattleChess (CHESS.EXE)

A scalable, test-driven pipeline for porting a 16-bit DOS binary to native C
without access to the original source.  The target is `CHESS.EXE`, the main
executable of the 1988 DOS game *BattleChess* by Interplay.  All analysis is
validated against the Ghidra decompilation in `src/chess.c`.

---

## Pipeline Overview

```
Binary (CHESS.EXE)
       │
       ▼
[Step 1] Tier classification
       │  Scan the decompiled source for functions that match
       │  testability criteria (no interrupts, bounded globals, etc.)
       │
       ▼
[Step 2] Implementation extraction
       │  Copy function bodies into tier*_impl.c, replacing
       │  *(type *)0xADDR with GSEG(addr, type) via the 64 KB
       │  segment overlay.
       │
       ▼
[Step 3] Fuzz harnesses (LibFuzzer + standalone mode)
       │  One .c harness per function.  Asserts behavioral
       │  invariants on every fuzz input.  make check validates
       │  against seed corpora without needing libclang-rt.
       │
       ▼
[Step 4] Oracle (state-delta traces)
       │  oracle_driver.c exhaustively sweeps interesting inputs,
       │  emitting NDJSON records with seg_in/seg_out snapshots.
       │
       ▼
[Step 5] Quality analysis (Step 6 in the original plan)
         analyze_quality.py computes per-function pass rate,
         type recovery score, and LOC delta against clean reference
         implementations.
```

---

## Tier Definitions

| Tier | Criteria | Current count |
|------|----------|---------------|
| **1** | Pure functions — no globals, no side effects, no pointer dereferences, no calls | 11 |
| **2** | Stateful — reads/writes a bounded set of hardcoded DOS segment addresses; no interrupts, no indirect calls | 6 |
| **3** | Extended stateful — additional global-access functions not in the initial Tier 2 batch | 6 |

**Total ported: 23 / 371** functions in `src/chess.c`.

---

## Segment Overlay

The entire DOS 16-bit data segment is mocked as a 64 KB byte array:

```c
// tier2_seg.h
extern uint8_t g_chess_seg[65536];
#define GSEG(addr, type)  (*(type *)(g_chess_seg + (unsigned)(addr)))
```

Every `*(type *)0xADDR` access in the decompiled source becomes
`GSEG(addr, type)` in the ported implementation.

**16-bit width rule**: DOS `int`/`uint` are 16-bit.  Addresses that are only
2 bytes apart (e.g. `0x86`/`0x88` for nav_col/nav_row, `0x53f2`/`0x53f4` for
text width/height) **must** use `int16_t`/`uint16_t` rather than 32-bit `int`.
Using 32-bit types causes 4-byte reads/writes that overlap adjacent addresses —
a class of bug discovered and fixed during Tier 2 development.

---

## Repository Layout

```
pipeline/
├── README.md                   ← this file
├── tier1_catalog.md            ← Tier 1 function descriptions + methodology
├── tier1_candidates.json       ← machine-readable Tier 1 metadata
├── tier2_catalog.md            ← Tier 2 function descriptions
├── tier3_catalog.md            ← Tier 3 function descriptions
│
├── harnesses/
│   ├── ghidra_compat.h         ← 64-bit type aliases for Ghidra output
│   ├── tier2_seg.h             ← GSEG macro + extern g_chess_seg
│   ├── seg_storage.c           ← Sole definition of g_chess_seg[65536]
│   │
│   ├── tier1_impl.h / .c       ← 11 Tier 1 pure functions
│   ├── tier2_impl.h / .c       ← 6  Tier 2 stateful functions
│   ├── tier3_impl.h / .c       ← 6  Tier 3 extended stateful functions
│   │
│   ├── standalone_main.h       ← Shim: replaces LLVMFuzzerTestOneInput
│   │                             with main() that reads seed directories
│   ├── Makefile                ← make check | make all | make fuzz-all
│   │
│   ├── fuzz_min_int.c          ┐
│   ├── fuzz_max_int.c          │ Tier 1 harnesses (cross-validate
│   ├── fuzz_abs_int.c          │ redundant function pairs)
│   ├── fuzz_is_odd.c           │
│   ├── fuzz_is_printable.c     │
│   ├── fuzz_coord_to_zone.c    │
│   ├── fuzz_offset_sentinel.c  │
│   ├── fuzz_div32.c            ┘
│   │
│   ├── fuzz_clear_anim_flag.c  ┐
│   ├── fuzz_set_text_cursor.c  │
│   ├── fuzz_handle_nav_key.c   │ Tier 2 harnesses (state-machine
│   ├── fuzz_pack_char_cell.c   │ invariants on g_chess_seg)
│   ├── fuzz_snapshot_viewport.c│
│   ├── fuzz_push_viewport.c    ┘
│   │
│   ├── fuzz_save_game_regs.c        ┐
│   ├── fuzz_restore_game_regs.c     │ Tier 3 harnesses (slot-A save/
│   ├── fuzz_clamp_text_size.c       │ restore, slot-B save/restore,
│   ├── fuzz_save_game_regs_b.c      │ callback table init)
│   ├── fuzz_restore_game_regs_b.c   │
│   └── fuzz_init_callback_table.c   ┘
│
└── oracle/
    ├── oracle_driver.c         ← Exhaustive sweep → NDJSON traces
    ├── analyze_quality.py      ← Step 6: pass rate, type score, LOC delta
    └── corpus/
        ├── oracle.ndjson       ← 61 319 records (Tier 1/2/3)
        └── quality_report.json ← Latest quality metrics
```

---

## Quick Start

### Verify all harnesses (no fuzzer runtime needed)

```bash
cd pipeline/harnesses
make check          # compiles 20 check binaries and runs seeds through each
```

Expected output: `=== All check builds passed ===` with `OK` for all 20 targets.

### Build full LibFuzzer binaries

```bash
sudo apt install libclang-rt-18-dev
make all
```

### Run fuzzer for 30 s per target

```bash
make fuzz-all
```

### Rebuild oracle and re-run quality analysis

```bash
cd pipeline/oracle
clang -O2 -std=c11 -o oracle_driver oracle_driver.c \
      ../harnesses/tier1_impl.c \
      ../harnesses/tier2_impl.c \
      ../harnesses/tier3_impl.c \
      -I../harnesses
./oracle_driver > corpus/oracle.ndjson
python3 analyze_quality.py
```

---

## Current Quality Metrics

| Tier | Functions | Pass rate | Avg type score | Avg LOC delta | Tier confirmed |
|------|-----------|-----------|----------------|---------------|----------------|
| 1    | 11        | 1.0000    | 0.65           | +1.8          | 11/11          |
| 2    | 6         | 1.0000*   | 0.31           | +0.8          | 6/6            |
| 3    | 6         | 1.0000    | 0.33           | +0.5          | 6/6            |
| **All** | **23** | **1.0000** | **0.48**      | **+1.3**      | **23/23**      |

\* Two Tier 2 functions (`push_viewport`, `pack_char_cell`) have N/A pass rates
because their oracle sweeps were not yet added to `oracle_driver.c`.

**Type score** is a heuristic [0, 1] penalising Ghidra noise tokens (`undefined2`,
`unaff_DS`, `iVar`, `param_N`).  Lower scores reflect heavier Ghidra artefacts;
correctness is measured by pass rate, not type score.

---

## Key Design Decisions

### Why LibFuzzer + standalone mode?

The target environment (kernel 4.4.0 in a container) has no hardware performance
counters, so Mozilla `rr` record/replay is unavailable.  For pure Tier 1 functions
exhaustive enumeration over boundary values is equivalent.  For stateful Tier 2/3
functions, LibFuzzer drives coverage; the standalone `make check` mode validates
seed corpora without requiring `libclang-rt-18-dev`.

### Save/restore cross-validation

`FUN_1000_2c46` / `FUN_1000_2c79` (slot A) and `FUN_1000_2cac` / `FUN_1000_2ce0`
(slot B) are exact inverse pairs.  The `fuzz_restore_game_regs.c` and
`fuzz_save_game_regs_b.c` harnesses both include an inline roundtrip:

```
save(X) → corrupt SRC → restore() → assert SRC == X
```

This gives mutual verification: if either function is wrong, the roundtrip fails.

### seg_storage.c separation

`g_chess_seg[65536]` is defined in `tier2_impl.c` for Tier 2 harnesses.  Tier 3
standalone harnesses link against `seg_storage.c` instead (which provides the
same definition) so that the oracle binary — which links all three impl files —
sees exactly one definition.

---

## Porting Notes

| Issue | Root cause | Fix |
|-------|-----------|-----|
| `handle_nav_key` assertion failure `col >= 0` | 32-bit GSEG read at 0x86 overlapped 0x88 | Changed to `int16_t` throughout |
| Duplicate `main()` linker error | `-include standalone_main.h` injected `main` into all TUs | Compile impl and harness separately, link objects |
| `g_chess_seg` undefined in Tier 3 | Tier 3 impl needed storage not provided by tier2 | Created `seg_storage.c` |

---

## Next Steps

- **Extend Tier 2 oracle coverage** for `push_viewport` and `pack_char_cell`
- **True Tier 3**: identify functions whose full call graph lands in Tier 1 ∪ Tier 2
  (candidates with `halt_baddata()` at the end require partial-function harnesses)
- **Tier 4 planning**: complex callers like `FUN_1000_323a` (calls `div32_reg`)
- **Coverage dashboard**: compute % of binary bytes covered by ported functions
