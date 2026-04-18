# Tier 1 Pure Function Catalog — BattleChess Binary

**Binary**: `CHESS.EXE` (DOS, 16-bit x86)
**Decompiled source**: `src/chess.c` (Ghidra headless output)
**Pipeline stage**: Step 4 — LibFuzzer harness targets

Tier 1 criteria: pure functions with no globals, no side effects, no I/O, no pointer
dereferences, no calls to other functions. Same inputs always produce same outputs.
These are the first targets for the fuzz corpus / rr oracle pipeline.

---

## Confirmed Tier 1 Functions (11 total)

| # | Symbol | src/chess.c line | Probable name | Signature |
|---|--------|-----------------|---------------|-----------|
| 1 | `FUN_1000_8f95` | 8607 | `min_int` | `int (int, int, ...)` |
| 2 | `FUN_1000_8fa5` | 8620 | `max_int` | `int (int, int)` |
| 3 | `FUN_1000_8fb5` | 8633 | `abs_int` | `int (int)` |
| 4 | `FUN_1000_d840` | 12471 | `coord_to_zone` | `int (int, int, int)` |
| 5 | `FUN_1000_d8f6` | 12509 | `is_printable_ascii` | `int (int)` |
| 6 | `FUN_1000_f1d6` | 14805 | `div32_reg` | `uint32 (uint16, uint16, uint16, uint16)` |
| 7 | `FUN_1000_fd4e` | 15907 | `offset_with_sentinel` | `int (int)` |
| 8 | `FUN_1000_fdf2` | 15978 | `abs_int2` | `int (int)` |
| 9 | `FUN_1000_fe0c` | 15991 | `max_int2` | `int (int, int)` |
| 10 | `FUN_1000_fe2b` | 16004 | `min_int2` | `int (int, int)` |
| 11 | `FUN_1000_fe4a` | 16017 | `is_odd` | `uint (uint)` |

---

## Function Bodies

### FUN_1000_8f95 — `min_int`
```c
int FUN_1000_8f95(int param_1, int param_2, ...) {
  if (param_2 < param_1) { param_1 = param_2; }
  return param_1;
}
```
Returns the smaller of two integers. The varargs `...` is a Ghidra artefact from the
calling convention; functionally takes exactly two ints.

---

### FUN_1000_8fa5 — `max_int`
```c
int FUN_1000_8fa5(int param_1, int param_2) {
  if (param_1 < param_2) { param_1 = param_2; }
  return param_1;
}
```
Returns the larger of two integers.

---

### FUN_1000_8fb5 — `abs_int`
```c
int FUN_1000_8fb5(int param_1) {
  if (0 < param_1) { return param_1; }
  return -param_1;
}
```
Absolute value. Note: differs from `FUN_1000_fdf2` in condition sense (`0 < x` vs `x < 0`).

---

### FUN_1000_d840 — `coord_to_zone`
```c
int FUN_1000_d840(int param_1, int param_2, int param_3) {
  if ((0x3c < param_1 && param_1 < 0xbb) && (0x3c < param_2 && param_2 < 0x8b))
    return (param_2 + -0x3c) / 10;
  if ((200 < param_1 && param_1 < 0xfd) && (0x81 < param_2 && param_2 < 0x8d))
    return 8;
  if ((param_3 != 0 && 200 < param_1) && (param_1 < 0xfd && 0x6d < param_2 && param_2 < 0x79))
    return 9;
  return 0xff;
}
```
Maps screen (x, y) coordinates to a board zone index. Returns 0xff for out-of-bounds.
The third parameter (`param_3`) acts as a flag enabling zone 9.

---

### FUN_1000_d8f6 — `is_printable_ascii`
```c
undefined2 FUN_1000_d8f6(int param_1) {
  if (0x1f < param_1 && param_1 < 0x7f) { return 1; }
  return 0;
}
```
Returns 1 if `param_1` is in the printable ASCII range [0x20, 0x7e], else 0.

---

### FUN_1000_f1d6 — `div32_reg`
```c
undefined4 FUN_1000_f1d6(uint p1, uint p2, uint p3, uint p4) {
  uint uVar1 = p2 - p4;
  uint uVar2 = uVar1 * 0x10 + p1;
  return CONCAT22(
    (carry_chain(p2, p4, uVar1)) - (uint)(uVar2 < p3),
    uVar2 - p3
  );
}
```
16-bit era 32-bit division helper. Implements long division using carry arithmetic
(Ghidra `CARRY2` / `CONCAT22` intrinsics). Takes two 16-bit halves of dividend (p1 high,
p2 low) and divisor (p3, p4). Returns 32-bit quotient. Parameters are passed via CPU
registers — Ghidra emits them as `param_N = 0` initializers.

---

### FUN_1000_fd4e — `offset_with_sentinel`
```c
int FUN_1000_fd4e(int param_1) {
  param_1 = param_1 + 0x14;
  if (param_1 == -0x7234) { param_1 = -0x72d4; }
  return param_1;
}
```
Adds a fixed offset (20) with a sentinel substitution: input value `-0x7248` maps to
output `-0x72d4` instead of the normal result. Likely a wrap-around guard.

---

### FUN_1000_fdf2 — `abs_int2`
```c
int FUN_1000_fdf2(int param_1) {
  if (param_1 < 0) { param_1 = -param_1; }
  return param_1;
}
```
Absolute value (condition-inverted variant of `FUN_1000_8fb5`).

---

### FUN_1000_fe0c — `max_int2`
```c
int FUN_1000_fe0c(int param_1, int param_2) {
  if (param_2 <= param_1) { param_2 = param_1; }
  return param_2;
}
```
Returns the larger of two integers (returns via param_2 slot, compare direction flipped
vs `FUN_1000_8fa5`).

---

### FUN_1000_fe2b — `min_int2`
```c
int FUN_1000_fe2b(int param_1, int param_2) {
  if (param_1 <= param_2) { param_2 = param_1; }
  return param_2;
}
```
Returns the smaller of two integers (returns via param_2, compare direction flipped vs
`FUN_1000_8f95`).

---

### FUN_1000_fe4a — `is_odd`
```c
uint FUN_1000_fe4a(uint param_1) {
  return param_1 & 1;
}
```
Returns 1 if `param_1` is odd, 0 if even (lowest-bit extraction).

---

## Fuzzing Priority Order

Priority is highest-confidence, simplest oracle first:

| Priority | Symbol | Rationale |
|----------|--------|-----------|
| 1 | `FUN_1000_fe4a` | 1-line, trivially correct oracle |
| 2 | `FUN_1000_8f95` | min — well-known semantics |
| 3 | `FUN_1000_8fa5` | max — well-known semantics |
| 4 | `FUN_1000_8fb5` | abs — well-known semantics |
| 5 | `FUN_1000_fdf2` | abs variant — cross-checks FUN_1000_8fb5 |
| 6 | `FUN_1000_fe0c` | max variant — cross-checks FUN_1000_8fa5 |
| 7 | `FUN_1000_fe2b` | min variant — cross-checks FUN_1000_8f95 |
| 8 | `FUN_1000_d8f6` | is_printable — simple range check |
| 9 | `FUN_1000_fd4e` | offset+sentinel — tests sentinel handling |
| 10 | `FUN_1000_d840` | coord_to_zone — more complex branching |
| 11 | `FUN_1000_f1d6` | div32 — most complex; validate last |

---

## Methodology Notes

**Detection approach**: Static analysis of Ghidra decompiled C output (`src/chess.c`).
Purity was verified by rejecting any function body containing:
- `*(type *)0xADDR` — hardcoded global dereference
- `*variable` — any pointer dereference (could be segment-relative)
- `FUN_xxxx(` — calls to other functions
- `DAT_xxxx` — named global data
- `swi(` / `halt_` — interrupts and traps
- `unaff_X` (non-segment registers) — hidden register side effects
- `in_XX` / `in_stack_` — register or stack-pointer inputs

`unaff_DS`/`unaff_ES`/`unaff_SS` (segment registers) were allowed as these are Ghidra
artefacts of the 16-bit segmented memory model, not actual side effects.

**Total functions scanned**: 383
**Stubs discarded**: 8
**Tier 1 confirmed**: 11
