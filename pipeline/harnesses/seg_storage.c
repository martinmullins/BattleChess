/*
 * seg_storage.c — Sole definition of the 64 KB DOS segment overlay.
 *
 * Tier 3 harnesses link against this file instead of tier2_impl.c so that
 * g_chess_seg is defined exactly once regardless of which impl files are
 * combined (e.g. the oracle links tier2_impl + tier3_impl + this is NOT
 * needed because tier2_impl already provides the definition; this file is
 * only for standalone tier3 harness builds).
 */
#include "tier2_seg.h"

uint8_t g_chess_seg[65536];
