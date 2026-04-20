# Tier 2 Function Catalog — BattleChess Binary

**Pipeline stage**: Step 4b — Tier 2 LibFuzzer harness targets  
**Tier definition**: Functions with bounded global state — reads/writes a small, enumerable
set of hardcoded DOS segment addresses, no I/O, no interrupts, no indirect calls.

**Key difference from Tier 1**: These functions touch global segment memory
(`*(int *)0x88` etc.).  The harness mocks the full DOS data segment as a 64 KB byte array
(`g_chess_seg[65536]`), initialised from fuzz input at the relevant addresses before each call.

---

## Selected Tier 2 Functions (6 total)

| # | Symbol | Line | Sub-tier | Globals R/W | Probable name |
|---|--------|------|----------|-------------|---------------|
| 1 | `FUN_1000_e45c` | 13672 | 2B | 0 R / 1 W | `clear_anim_flag` |
| 2 | `FUN_1000_f2de` | 14977 | 2B | 0 R / 2 W | `set_text_cursor` |
| 3 | `FUN_1000_fd6a` | 15921 | 2B | 2 R / 2 W | `handle_nav_key` |
| 4 | `FUN_1000_931c` | 8833  | 2A | 6 R / 0 W | `pack_char_cell` |
| 5 | `FUN_1000_7da8` | 7220  | 2B | 4 R / 5 W | `snapshot_viewport` |
| 6 | `FUN_1000_7c52` | 7125  | 2B | 9 R / 5 W | `push_viewport` |

---

## Global Address Map (Tier 2 footprint)

| Address | Width | Semantic name | Used by |
|---------|-------|---------------|---------|
| `0x86`  | int16 | `nav_col`  — horizontal camera/piece index [0-7] | `handle_nav_key` |
| `0x88`  | int16 | `nav_row`  — vertical camera/piece index [0-7]   | `handle_nav_key` |
| `0x44de`| byte  | `anim_flag` — animation gate byte                | `clear_anim_flag` |
| `0x4a02`| int16 | `text_cursor_pos` — current text output position | `set_text_cursor` |
| `0x4a04`| int16 | `text_cursor_col` — text column (cleared on set) | `set_text_cursor` |
| `0x4e2` | int16 | `viewport_src[0]` — source viewport register 0  | `snapshot/push` |
| `0x4e4` | int16 | `viewport_src[1]`                                | `snapshot/push` |
| `0x4e6` | int16 | `viewport_src[2]`                                | `snapshot/push` |
| `0x4e8` | int16 | `viewport_src[3]`                                | `snapshot/push` |
| `0x53a` | byte  | `char_attr`  — character value for next cell     | `pack_char_cell` |
| `0x53c` | byte  | `fg_color`   — foreground color nibble [0-3]     | `pack_char_cell` |
| `0x53e` | byte  | `bg_color`   — background color nibble [0-3]     | `pack_char_cell` |
| `0x85a4`| int16 | `viewport_dst_a[0]` — push destination a        | `push_viewport` |
| `0x85a6`| int16 | `viewport_dst_a[1]`                              | `push_viewport` |
| `0x85a8`| int16 | `viewport_dst_a[2]`                              | `push_viewport` |
| `0x85aa`| int16 | `viewport_dst_a[3]`                              | `push_viewport` |
| `0x8176`| char  | `text_bold`   — bold flag (0 or 1)              | `pack_char_cell` |
| `0x8188`| char  | `text_underline` — underline flag (0 or 1)      | `pack_char_cell` |
| `0x88dc`| int16 | `viewport_snap[0]` — snapshot destination 0     | `snapshot_viewport` |
| `0x88de`| int16 | `viewport_snap[1]`                              | `snapshot_viewport` |
| `0x88e0`| int16 | `viewport_snap[2]`                              | `snapshot_viewport` |
| `0x88e2`| int16 | `viewport_snap[3]`                              | `snapshot_viewport` |
| `0x9880`| int16 | `stack_depth` — viewport stack depth counter    | `snapshot/push` |
| `0xef6` | char  | `text_blink`  — blink flag (0 or 1)             | `pack_char_cell` |

---

## Function Descriptions

### FUN_1000_e45c — `clear_anim_flag`
```c
void FUN_1000_e45c(void) {
    *(uint8_t *)0x44de = 0;
}
```
Resets the animation gate byte to 0.  Single-write, no reads, no params.  
**Oracle**: output state must have `seg[0x44de] == 0` regardless of prior value.

---

### FUN_1000_f2de — `set_text_cursor`
```c
void FUN_1000_f2de(uint16_t param_1) {
    *(uint16_t *)0x4a02 = param_1;
    *(uint16_t *)0x4a04 = 0;
}
```
Sets the text output position to `param_1` and resets the column counter to 0.  
**Oracle**: `seg[0x4a02] == param_1`, `seg[0x4a04] == 0`.

---

### FUN_1000_fd6a — `handle_nav_key`
```c
// 'H'=up  'K'=left  'M'=right  'P'=down  (DOS scan codes for arrow keys)
// Wraps indices modulo 8.  Returns 1 if key was handled, 0 otherwise.
uint16_t FUN_1000_fd6a(char key) {
    if      (key=='H') { seg[0x88] = (seg[0x88] < 1) ? 7 : seg[0x88]-1; return 1; }
    else if (key=='K') { seg[0x86] = (seg[0x86] < 1) ? 7 : seg[0x86]-1; return 1; }
    else if (key=='M') { seg[0x86] = (seg[0x86] < 7) ? seg[0x86]+1 : 0; return 1; }
    else if (key=='P') { seg[0x88] = (seg[0x88] < 7) ? seg[0x88]+1 : 0; return 1; }
    return 0;
}
```
**Oracle**: nav indices must stay in [0,7]; return value 0 or 1; handled keys produce
correct +1/-1 mod-8 transition; unhandled keys leave state unchanged.

---

### FUN_1000_931c — `pack_char_cell`
```c
// Writes a CGA-style 2-byte text cell to output buffer at position (base + col*2).
// byte[0] = character value (from seg[0x53a])
// byte[1] = (bg_color & 3) | ((fg_color & 3) << 2) | (bold*0x40) | (underline*0x20) | (blink*0x10)
void FUN_1000_931c(int base, uint8_t col) { ... }
```
**Oracle**: output matches independently computed CGA attribute byte for all
combinations of the 6 flag globals; total packed byte is in [0,0xFF].

---

### FUN_1000_7da8 — `snapshot_viewport`
```c
// Sets stack_depth sentinel to 0xFFFF, then copies viewport_src[0-3] to viewport_snap[0-3].
void FUN_1000_7da8(void) {
    seg[0x9880] = 0xFFFF;
    seg[0x88dc] = seg[0x4e2];  seg[0x88de] = seg[0x4e4];
    seg[0x88e0] = seg[0x4e6];  seg[0x88e2] = seg[0x4e8];
}
```
**Oracle**: snap registers equal source registers; `seg[0x9880] == 0xFFFF`.

---

### FUN_1000_7c52 — `push_viewport`
Decrements `stack_depth`, shifts a table of viewport entries down by one slot,
then copies `viewport_src[0-3]` into the new top slot at the push destination.  
Most complex Tier 2 target — exercises loop with computed offsets and a sentinel check.  
**Oracle**: dst registers equal src registers post-call; `stack_depth` decreased by 1.

---

## Fuzzing Approach

All Tier 2 harnesses share a common pattern:

```c
// 1. Zero the segment mock
memset(g_chess_seg, 0, sizeof(g_chess_seg));

// 2. Populate relevant addresses from fuzz input
//    (only the addresses this function reads — writes are captured as output)

// 3. Extract function parameters from remaining fuzz bytes

// 4. Call function

// 5. Assert invariants on return value + mutated segment addresses
```

The segment mock (`g_chess_seg[65536]`) is declared in `tier2_seg.h` and shared across
all Tier 2 harnesses via the `GSEG(addr, type)` accessor macro.

---

## Success Criteria (Tier 2)

- All Tier 2 harnesses pass `make check-tier2` with the seed corpus
- Invariant assertions hold across the full fuzz domain
- State delta captured in oracle NDJSON (addresses + before/after values)
- Tier classification accuracy: all 6 confirmed as Tier 2 (not re-classified Tier 1)
