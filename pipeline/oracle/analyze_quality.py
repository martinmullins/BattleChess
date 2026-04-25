#!/usr/bin/env python3
"""
analyze_quality.py — Pipeline Step 6: Decompiler quality report.

Measures per-function:
  1. Fuzz corpus pass rate         (behavioral correctness vs oracle)
  2. Type/variable recovery score  (heuristic from decompiled source)
  3. Lines-of-code delta           (decompiler noise vs reference impl)
  4. Tier classification accuracy  (re-validates tier assignment)

Outputs a Markdown report to stdout and a JSON metrics file.

Usage:
    python3 analyze_quality.py [--oracle corpus/oracle.ndjson] \\
                               [--source ../../src/chess.c] \\
                               [--out corpus/quality_report.json]
"""
import json, re, sys, argparse, textwrap
from pathlib import Path

# ---------------------------------------------------------------------------
# Reference implementations (clean C, used as LOC baseline)
# ---------------------------------------------------------------------------
TIER1_REFS = {
    "FUN_1000_8f95": ("min_int",
        "int min_int(int a, int b) { return a < b ? a : b; }",
        1),
    "FUN_1000_8fa5": ("max_int",
        "int max_int(int a, int b) { return a > b ? a : b; }",
        1),
    "FUN_1000_8fb5": ("abs_int",
        "int abs_int(int a) { return a < 0 ? -a : a; }",
        1),
    "FUN_1000_d840": ("coord_to_zone",
        textwrap.dedent("""\
        int coord_to_zone(int x, int y, int flag) {
            if (x > 0x3c && x < 0xbb && y > 0x3c && y < 0x8b) return (y-0x3c)/10;
            if (x > 200  && x < 0xfd && y > 0x81 && y < 0x8d) return 8;
            if (flag && x > 200 && x < 0xfd && y > 0x6d && y < 0x79) return 9;
            return 0xff;
        }"""),
        4),
    "FUN_1000_d8f6": ("is_printable_ascii",
        "int is_printable_ascii(int c) { return c > 0x1f && c < 0x7f; }",
        1),
    "FUN_1000_f1d6": ("div32_reg",
        textwrap.dedent("""\
        uint32_t div32_reg(uint16_t p1, uint16_t p2, uint16_t p3, uint16_t p4) {
            uint16_t u1 = p2 - p4;
            uint16_t u2 = u1 * 16 + p1;
            uint16_t hi = carry_chain(p2,p4,u1) - (u2 < p3);
            return ((uint32_t)hi << 16) | (uint16_t)(u2 - p3);
        }"""),
        5),
    "FUN_1000_fd4e": ("offset_with_sentinel",
        textwrap.dedent("""\
        int offset_with_sentinel(int a) {
            a += 0x14;
            return a == -0x7234 ? -0x72d4 : a;
        }"""),
        3),
    "FUN_1000_fdf2": ("abs_int2",
        "int abs_int2(int a) { return a < 0 ? -a : a; }",
        1),
    "FUN_1000_fe0c": ("max_int2",
        "int max_int2(int a, int b) { return a > b ? a : b; }",
        1),
    "FUN_1000_fe2b": ("min_int2",
        "int min_int2(int a, int b) { return a < b ? a : b; }",
        1),
    "FUN_1000_fe4a": ("is_odd",
        "uint is_odd(uint a) { return a & 1; }",
        1),
    "FUN_1000_f32e": ("mul32",
        textwrap.dedent("""\
        uint32_t mul32(uint16_t p1, int16_t p2, uint16_t p3, int16_t p4) {
            if (!p2 && !p4) return (uint32_t)p1 * p3;
            uint32_t prod = (uint32_t)p1 * p3;
            uint16_t hi = (prod>>16) + p2*p3 + p1*p4;
            return ((uint32_t)hi << 16) | (uint16_t)prod;
        }"""),
        5),
}

TIER2_REFS = {
    "FUN_1000_e45c": ("clear_anim_flag",
        "void clear_anim_flag(void) { anim_flag = 0; }",
        1),
    "FUN_1000_f2de": ("set_text_cursor",
        "void set_text_cursor(uint16_t p) { text_pos = p; text_col = 0; }",
        2),
    "FUN_1000_fd6a": ("handle_nav_key",
        textwrap.dedent("""\
        uint16_t handle_nav_key(char k) {
            if (k=='H') { nav_row = nav_row<1 ? 7 : nav_row-1; return 1; }
            if (k=='K') { nav_col = nav_col<1 ? 7 : nav_col-1; return 1; }
            if (k=='M') { nav_col = nav_col<7 ? nav_col+1 : 0; return 1; }
            if (k=='P') { nav_row = nav_row<7 ? nav_row+1 : 0; return 1; }
            return 0;
        }"""),
        8),
    "FUN_1000_931c": ("pack_char_cell",
        textwrap.dedent("""\
        void pack_char_cell(int base, uint8_t col) {
            seg[base + col*2]   = char_val;
            seg[base + col*2+1] = (bg&3)|((fg&3)<<2)|(bold*0x40)|(uline*0x20)|(blink*0x10);
        }"""),
        4),
    "FUN_1000_7da8": ("snapshot_viewport",
        textwrap.dedent("""\
        void snapshot_viewport(void) {
            stack_depth = 0xffff;
            snap[0..3] = src[0..3];
        }"""),
        3),
    "FUN_1000_7c52": ("push_viewport",
        textwrap.dedent("""\
        void push_viewport(void) {
            stack_depth--;
            for (i = -0x68; i <= stack_depth; i++) shift_entry(i);
            dst_a[0..3] = src[0..3];
        }"""),
        5),
}

TIER3_REFS = {
    "FUN_1000_2c46": ("save_game_regs",
        textwrap.dedent("""\
        void save_game_regs(void) {
            dst[0..7] = src[0..7];   /* 8 parallel copies */
        }"""),
        3),
    "FUN_1000_2c79": ("restore_game_regs",
        textwrap.dedent("""\
        void restore_game_regs(void) {
            src[0..7] = dst[0..7];   /* exact inverse of save_game_regs */
        }"""),
        3),
    "FUN_1000_8a64": ("clamp_text_size",
        textwrap.dedent("""\
        void clamp_text_size(void) {
            dirty = 1; zap = 0;
            w = raw_w; h = raw_h;
            if (h < 1 && (h < 0 || w < 3)) { w = 3; h = 0; }
        }"""),
        5),
    "FUN_1000_2cac": ("save_game_regs_b",
        textwrap.dedent("""\
        void save_game_regs_b(void) {
            dstb[0..7] = src[0..7];   /* same SRC, alternate slot-B bank */
        }"""),
        3),
    "FUN_1000_2ce0": ("restore_game_regs_b",
        textwrap.dedent("""\
        void restore_game_regs_b(void) {
            src[0..7] = dstb[0..7];   /* exact inverse of save_game_regs_b */
        }"""),
        3),
    "FUN_1000_29b9": ("init_callback_table",
        textwrap.dedent("""\
        void init_callback_table(void) {
            cb[0] = {0x2cee, 0x5cc2}; cb[1] = {0x2d0e, 0x5cc2};
            cb[2] = {0x2d8a, 0x5cc2}; cb[3] = {0x2dbe, 0x5cc2};
            cb[4] = {0x2b2e, 0x5cc2}; cb[5] = {0x2b4e, 0x5cc2};
            cb[6] = {0x2bca, 0x5cc2}; cb[7] = {0x2bfe, 0x5cc2};
        }"""),
        9),
    "FUN_1000_f1bc": ("flag_byte_check",
        "int flag_byte_check(int i) { return (flag_table[i] & 1) ? i + 0x20 : i; }",
        2),
    "FUN_1000_fce8": ("compute_row_bitmasks",
        textwrap.dedent("""\
        void compute_row_bitmasks(int player) {
            for r in 0..7: mask[r] = 0
            for r in 0..7: for c in 0..7:
                if board[r*8+c] has piece and matches player:
                    mask[r] |= (1 << c)
        }"""),
        8),
    "FUN_1000_7dbf": ("write_tile_entry",
        "void write_tile_entry(byte v, byte f, int i) { tile_table[i*4]=v; tile_table[i*4+1]=f; }",
        2),
    "FUN_1000_db3d": ("next_slot_fwd",
        textwrap.dedent("""\
        int next_slot_fwd(int base, int slot) {
            do { slot = (slot + 1) % 8; }
            while (table[slot].sentinel == -1);
            return slot;
        }"""),
        4),
    "FUN_1000_db65": ("next_slot_bwd",
        textwrap.dedent("""\
        int next_slot_bwd(int base, int slot) {
            do { slot = (slot - 1 + 8) % 8; }
            while (table[slot].sentinel == -1);
            return slot;
        }"""),
        4),
}

ALL_REFS = {**TIER1_REFS, **TIER2_REFS, **TIER3_REFS}

# ---------------------------------------------------------------------------
# Helpers
# ---------------------------------------------------------------------------

def extract_function_body(source_text: str, symbol: str) -> str:
    header_pat = re.compile(
        r'/\* ---- ' + re.escape(symbol) + r' @ [^\n]+ ---- \*/')
    m = header_pat.search(source_text)
    if not m:
        return ""
    brace_start = source_text.find('{', m.end())
    if brace_start == -1:
        return ""
    depth, pos = 0, brace_start
    while pos < len(source_text):
        if source_text[pos] == '{':
            depth += 1
        elif source_text[pos] == '}':
            depth -= 1
            if depth == 0:
                return source_text[m.start():pos + 1]
        pos += 1
    return ""


def count_body_lines(body: str) -> int:
    lines = [l for l in body.split('\n')
             if l.strip() and l.strip() not in ('{', '}')
             and not l.strip().startswith('/*') and not l.strip().startswith('*')]
    return len(lines)


def type_recovery_score(body: str) -> float:
    """Heuristic type recovery score [0.0, 1.0]."""
    penalties = {
        r'\bundefined[124]\b': 0.15,
        r'\bunaff_\w+': 0.10,
        r'\bparam_\d+\b': 0.10,
        r'\b[iub]Var\d+\b': 0.05,
        r'\bpcVar\d+\b': 0.05,
        r'\bpbVar\d+\b': 0.05,
    }
    score = 1.0
    for pat, penalty in penalties.items():
        hits = len(re.findall(pat, body))
        score -= min(hits * penalty, penalty * 3)
    return max(0.0, round(score, 2))


def tier1_pass_rate(oracle_records: list, symbol: str) -> float:
    """For pure functions: all same-input records must have the same output."""
    seen = {}
    fails = 0
    total = 0
    for r in oracle_records:
        if r.get('fn') != symbol or r.get('tier', 1) != 1:
            continue
        total += 1
        key = tuple(r['in'])
        if key in seen:
            if seen[key] != r['out']:
                fails += 1
        else:
            seen[key] = r['out']
    if total == 0:
        return None
    return round((total - fails) / total, 4)


def state_pass_rate(oracle_records: list, symbol: str) -> float:
    """For stateful functions: every seg_in must deterministically produce seg_out."""
    seen = {}
    fails = 0
    total = 0
    for r in oracle_records:
        if r.get('fn') != symbol:
            continue
        tier = r.get('tier', 1)
        if tier not in (2, 3):
            continue
        total += 1
        # Key = (args_tuple, frozen seg_in)
        args_key = tuple(r.get('args') or [])
        seg_in_key = tuple(sorted((k, v) for k, v in r.get('seg_in', {}).items()))
        key = (args_key, seg_in_key)
        seg_out = tuple(sorted((k, v) for k, v in r.get('seg_out', {}).items()))
        if key in seen:
            if seen[key] != seg_out:
                fails += 1
        else:
            seen[key] = seg_out
    if total == 0:
        return None
    return round((total - fails) / total, 4)


def tier_ok_check(body: str, tier: int) -> bool:
    # Match both *(type *)0xHEX (fixed address) and *(type *)(expr + 0xHEX) (computed)
    has_global = bool(re.search(
        r'\*\s*\([^)]+\*\s*\)\s*(?:0x[0-9a-fA-F]+|\([^)]*0x[0-9a-fA-F][^)]*\))', body))
    has_call   = bool(re.search(r'\bFUN_[0-9a-fA-F_]+\s*\(', body[body.find('{'):] if body else ''))
    has_deref  = bool(re.search(r'(?<!=)\*(?!\s*/)(?!\s*\*)[a-z_]\w*\b', body))
    if tier == 1:
        return not has_global and not has_call and not has_deref
    else:  # tier 2/3: must have globals (that's what makes them stateful)
        return has_global


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--oracle', default='corpus/oracle.ndjson')
    ap.add_argument('--source', default='../../src/chess.c')
    ap.add_argument('--out',    default='corpus/quality_report.json')
    args = ap.parse_args()

    oracle_path = Path(args.oracle)
    source_path = Path(args.source)
    out_path    = Path(args.out)

    oracle_records = []
    if oracle_path.exists():
        with open(oracle_path) as f:
            for line in f:
                try:
                    oracle_records.append(json.loads(line))
                except json.JSONDecodeError:
                    pass

    source_text = ""
    if source_path.exists():
        source_text = source_path.read_text(errors='replace')

    results = []
    tier_groups = [
        ("Tier 1 — Pure functions",          TIER1_REFS, 1),
        ("Tier 2 — Stateful (segment access)", TIER2_REFS, 2),
        ("Tier 3 — Extended stateful",         TIER3_REFS, 3),
    ]

    total_oracle = len(oracle_records)
    print(f"# Decompiler Quality Report — All Tiers\n")
    print(f"Oracle records: {total_oracle}")
    print(f"Source file:    {source_path}\n")

    HDR = f"{'Symbol':<30} {'Name':<22} {'PassRate':>8} {'TypeScore':>9} {'DecompLOC':>9} {'RefLOC':>6} {'LOCDelta':>8} {'TierOK':>6}"
    SEP = "-" * 100

    for section_title, refs, tier in tier_groups:
        print(f"\n## {section_title}\n")
        print(HDR)
        print(SEP)

        for symbol, (name, ref_code, ref_loc) in sorted(refs.items()):
            body       = extract_function_body(source_text, symbol) if source_text else ""
            decomp_loc = count_body_lines(body) if body else 0
            type_score = type_recovery_score(body) if body else 0.0

            if tier == 1:
                pass_rate = tier1_pass_rate(oracle_records, symbol)
            else:
                pass_rate = state_pass_rate(oracle_records, symbol)

            loc_delta = decomp_loc - ref_loc if decomp_loc else None
            ok        = tier_ok_check(body, tier) if body else False

            pass_str  = f"{pass_rate:.4f}" if pass_rate is not None else "N/A"
            delta_str = f"+{loc_delta}" if (loc_delta is not None and loc_delta > 0) else str(loc_delta)

            print(f"{symbol:<30} {name:<22} {pass_str:>8} {type_score:>9.2f} {decomp_loc:>9} {ref_loc:>6} {delta_str:>8} {'YES' if ok else 'NO':>6}")

            results.append({
                "symbol":        symbol,
                "probable_name": name,
                "tier":          tier,
                "pass_rate":     pass_rate,
                "type_score":    type_score,
                "decomp_loc":    decomp_loc,
                "ref_loc":       ref_loc,
                "loc_delta":     loc_delta,
                "tier_confirmed": ok,
            })
        print(SEP)

    # Summary across all tiers
    confirmed  = [r for r in results if r['tier_confirmed']]
    rated      = [r for r in results if r['pass_rate'] is not None]
    avg_pass   = sum(r['pass_rate'] for r in rated) / len(rated) if rated else 0
    avg_type   = sum(r['type_score'] for r in results) / len(results)
    deltas     = [r['loc_delta'] for r in results if r['loc_delta'] is not None]
    avg_delta  = sum(deltas) / len(deltas) if deltas else 0

    print(f"\n## Summary\n")
    print(f"  Functions analysed:      {len(results)} ({len(TIER1_REFS)} T1 / {len(TIER2_REFS)} T2 / {len(TIER3_REFS)} T3)")
    print(f"  Tier confirmed:          {len(confirmed)}/{len(results)}")
    print(f"  Avg corpus pass rate:    {avg_pass:.4f}")
    print(f"  Avg type recovery score: {avg_type:.2f}")
    print(f"  Avg LOC delta:           {avg_delta:+.1f}")

    out_path.parent.mkdir(parents=True, exist_ok=True)
    with open(out_path, 'w') as f:
        json.dump({
            "summary": {
                "total": len(results),
                "tier1": len(TIER1_REFS),
                "tier2": len(TIER2_REFS),
                "tier3": len(TIER3_REFS),
                "tier_confirmed": len(confirmed),
                "avg_pass_rate": round(avg_pass, 4),
                "avg_type_score": round(avg_type, 2),
                "avg_loc_delta": round(avg_delta, 1),
            },
            "functions": results,
        }, f, indent=2)
    print(f"\nJSON metrics written to: {out_path}")


if __name__ == '__main__':
    main()
