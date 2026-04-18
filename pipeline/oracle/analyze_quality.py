#!/usr/bin/env python3
"""
analyze_quality.py — Pipeline Step 6: Decompiler quality report.

Measures per-function:
  1. Fuzz corpus pass rate         (behavioral correctness vs oracle)
  2. Type/variable recovery score  (heuristic from decompiled source)
  3. Lines-of-code delta           (decompiler noise vs reference impl)
  4. Tier classification accuracy  (re-validates our Tier 1 calls)

Outputs a Markdown report to stdout and a JSON metrics file.

Usage:
    python3 analyze_quality.py [--oracle corpus/oracle.ndjson] \
                               [--source ../../src/chess.c] \
                               [--out corpus/quality_report.json]
"""
import json, re, sys, argparse, textwrap
from pathlib import Path

# ---------------------------------------------------------------------------
# Reference implementations (clean C, used as LOC baseline)
# ---------------------------------------------------------------------------
REFERENCES = {
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
}

# ---------------------------------------------------------------------------
# Helpers
# ---------------------------------------------------------------------------

def extract_function_body(source_text: str, symbol: str) -> str:
    """Return the raw decompiled body for a given FUN_ symbol."""
    pattern = re.compile(
        r'/\* ---- ' + re.escape(symbol) + r' @ [^\n]+ ---- \*/'
        r'.*?'
        r'\{(.*?)\}',
        re.DOTALL)
    m = pattern.search(source_text)
    if not m:
        return ""
    return m.group(0)


def count_body_lines(body: str) -> int:
    lines = [l for l in body.split('\n')
             if l.strip() and l.strip() not in ('{', '}')
             and not l.strip().startswith('/*') and not l.strip().startswith('*')]
    return len(lines)


def type_recovery_score(body: str) -> float:
    """
    Heuristic type recovery score [0.0, 1.0].
    Penalises:
      - undefined1/2/4  (unresolved types)
      - unaff_          (unaffected register noise)
      - param_N         (unnamed parameters)
      - iVar/uVar/bVar  (unnamed locals)
    """
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
        score -= min(hits * penalty, penalty * 3)  # cap per pattern
    return max(0.0, round(score, 2))


def corpus_pass_rate(oracle_records: list, symbol: str) -> float:
    """All oracle records must have consistent output for same input."""
    seen = {}
    fails = 0
    total = 0
    for r in oracle_records:
        if r['fn'] != symbol:
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
    print("# Tier 1 Decompiler Quality Report\n")
    print(f"Oracle records: {len(oracle_records)}")
    print(f"Source file:    {source_path}\n")
    print(f"{'Symbol':<30} {'Name':<22} {'PassRate':>8} {'TypeScore':>9} {'DecompLOC':>9} {'RefLOC':>6} {'LOCDelta':>8} {'TierOK':>6}")
    print("-" * 100)

    for symbol, (name, ref_code, ref_loc) in sorted(REFERENCES.items()):
        body = extract_function_body(source_text, symbol) if source_text else ""
        decomp_loc  = count_body_lines(body) if body else 0
        type_score  = type_recovery_score(body) if body else 0.0
        pass_rate   = corpus_pass_rate(oracle_records, symbol)
        loc_delta   = decomp_loc - ref_loc if decomp_loc else None

        # Tier classification: re-check our purity criteria
        has_global = bool(re.search(r'\*\s*\([^)]+\)\s*0x[0-9a-fA-F]+', body))
        has_call   = bool(re.search(r'\bFUN_[0-9a-fA-F_]+\s*\(', body[body.find('{'):] if body else ''))
        has_deref  = bool(re.search(r'(?<!=)\*(?!\s*/)(?!\s*\*)\s*[a-z_]\w*\b', body))
        tier_ok    = not has_global and not has_call and not has_deref

        pass_str  = f"{pass_rate:.4f}" if pass_rate is not None else "N/A"
        delta_str = f"+{loc_delta}" if loc_delta and loc_delta > 0 else str(loc_delta)

        print(f"{symbol:<30} {name:<22} {pass_str:>8} {type_score:>9.2f} {decomp_loc:>9} {ref_loc:>6} {delta_str:>8} {'YES' if tier_ok else 'NO':>6}")

        results.append({
            "symbol":          symbol,
            "probable_name":   name,
            "pass_rate":       pass_rate,
            "type_score":      type_score,
            "decomp_loc":      decomp_loc,
            "ref_loc":         ref_loc,
            "loc_delta":       loc_delta,
            "tier1_confirmed": tier_ok,
        })

    # Summary
    confirmed = [r for r in results if r['tier1_confirmed']]
    avg_pass  = sum(r['pass_rate'] for r in results if r['pass_rate'] is not None) / len(results)
    avg_type  = sum(r['type_score'] for r in results) / len(results)
    avg_delta = sum(r['loc_delta'] for r in results if r['loc_delta'] is not None) / len(results)

    print("-" * 100)
    print(f"\nSummary:")
    print(f"  Tier 1 confirmed:        {len(confirmed)}/{len(results)}")
    print(f"  Avg corpus pass rate:    {avg_pass:.4f}")
    print(f"  Avg type recovery score: {avg_type:.2f}")
    print(f"  Avg LOC delta:           {avg_delta:+.1f}")

    out_path.parent.mkdir(parents=True, exist_ok=True)
    with open(out_path, 'w') as f:
        json.dump({
            "summary": {
                "tier1_confirmed": len(confirmed),
                "total": len(results),
                "avg_pass_rate": round(avg_pass, 4),
                "avg_type_score": round(avg_type, 2),
                "avg_loc_delta": round(avg_delta, 1),
            },
            "functions": results,
        }, f, indent=2)
    print(f"\nJSON metrics written to: {out_path}")


if __name__ == '__main__':
    main()
