/*
 * oracle_driver.c — Ground-truth input/output oracle for Tier 1 & Tier 2/3.
 *
 * Tier 1 (pure functions): exhaustive sweeps over interesting input domains.
 * Tier 2/3 (segment state): state-delta traces capturing relevant g_chess_seg
 *   addresses before and after each call.
 *
 * Output: NDJSON to stdout, one record per call.
 *
 * Tier 1 format:
 *   {"fn":"FUN_1000_8fa5","tier":1,"in":[3,7],"out":7}
 *
 * Tier 2/3 format (state delta, address keys are hex strings):
 *   {"fn":"FUN_1000_fd6a","tier":2,"args":[72],"seg_in":{"86":0,"88":5},"seg_out":{"86":0,"88":4},"ret":1}
 *
 * Build:
 *   clang -O2 -std=c11 -o oracle_driver oracle_driver.c \
 *         ../harnesses/tier1_impl.c ../harnesses/tier2_impl.c ../harnesses/tier3_impl.c
 *
 * Run:
 *   ./oracle_driver > corpus/oracle.ndjson
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "../harnesses/tier1_impl.h"
#include "../harnesses/tier2_impl.h"
#include "../harnesses/tier3_impl.h"

/* tier3_impl.c defines its own g_chess_seg; we re-use tier2's definition
 * by declaring the tier3 one as a compatible alias via the shared header. */

/* =========================================================================
 * Tier 1 input domains
 * ========================================================================= */

static const int32_t INT_VALS[] = {
    0, 1, -1, 2, -2, 3, -3,
    0x7F, -0x7F, 0x80, -0x80,
    0x7FFF, -0x7FFF, 0x8000, -0x8000,
    0x7FFFFFFF, -0x7FFFFFFF,
    100, -100, 255, -255, 1000, -1000,
    0x3c, 0x3d, 0x8a, 0x8b, 0xbb, 0xba,
    0x6d, 0x6e, 0x78, 0x79,
    0x81, 0x82, 0x8c, 0x8d,
    0xc8, 0xc9, 0xfc, 0xfd,
    -0x7234, -0x7235, -0x7248,
    -0x72d4, 0x14, -0x72d3,
};
#define N_INT_VALS (int)(sizeof(INT_VALS)/sizeof(INT_VALS[0]))

static const uint32_t UINT_VALS[] = {
    0u, 1u, 2u, 3u, 0xFFu, 0x100u,
    0xFFFFu, 0x10000u, 0xFFFFFFFEu, 0xFFFFFFFFu,
    0x12345678u, 0x87654321u,
};
#define N_UINT_VALS (int)(sizeof(UINT_VALS)/sizeof(UINT_VALS[0]))

static const uint16_t U16_VALS[] = {
    0, 1, 2, 0xF, 0x10, 0xFF, 0x100,
    0x7FFF, 0x8000, 0xFFFE, 0xFFFF,
    0x1234, 0x5678, 0x9ABC, 0xDEF0,
};
#define N_U16_VALS (int)(sizeof(U16_VALS)/sizeof(U16_VALS[0]))

/* =========================================================================
 * Tier 1 emit helpers
 * ========================================================================= */

static void emit1i(const char *fn, int32_t a, int32_t out)
{ printf("{\"fn\":\"%s\",\"tier\":1,\"in\":[%d],\"out\":%d}\n", fn, a, out); }

static void emit2i(const char *fn, int32_t a, int32_t b, int32_t out)
{ printf("{\"fn\":\"%s\",\"tier\":1,\"in\":[%d,%d],\"out\":%d}\n", fn, a, b, out); }

static void emit3i(const char *fn, int32_t a, int32_t b, int32_t c, int32_t out)
{ printf("{\"fn\":\"%s\",\"tier\":1,\"in\":[%d,%d,%d],\"out\":%d}\n", fn, a, b, c, out); }

static void emit1u(const char *fn, uint32_t a, uint32_t out)
{ printf("{\"fn\":\"%s\",\"tier\":1,\"in\":[%u],\"out\":%u}\n", fn, a, out); }

static void emit4u16(const char *fn,
                     uint16_t p1, uint16_t p2, uint16_t p3, uint16_t p4,
                     uint32_t out)
{ printf("{\"fn\":\"%s\",\"tier\":1,\"in\":[%u,%u,%u,%u],\"out\":%u}\n",
         fn, p1, p2, p3, p4, out); }

/* =========================================================================
 * Tier 1 sweeps
 * ========================================================================= */

static void sweep_min_int(void)
{
    for (int i = 0; i < N_INT_VALS; i++)
        for (int j = 0; j < N_INT_VALS; j++) {
            int a = INT_VALS[i], b = INT_VALS[j];
            emit2i("FUN_1000_8f95", a, b, FUN_1000_8f95(a, b));
            emit2i("FUN_1000_fe2b", a, b, FUN_1000_fe2b(a, b));
        }
}

static void sweep_max_int(void)
{
    for (int i = 0; i < N_INT_VALS; i++)
        for (int j = 0; j < N_INT_VALS; j++) {
            int a = INT_VALS[i], b = INT_VALS[j];
            emit2i("FUN_1000_8fa5", a, b, FUN_1000_8fa5(a, b));
            emit2i("FUN_1000_fe0c", a, b, FUN_1000_fe0c(a, b));
        }
}

static void sweep_abs_int(void)
{
    for (int i = 0; i < N_INT_VALS; i++) {
        int a = INT_VALS[i];
        if (a == (int32_t)0x80000000) continue;
        emit1i("FUN_1000_8fb5", a, FUN_1000_8fb5(a));
        emit1i("FUN_1000_fdf2", a, FUN_1000_fdf2(a));
    }
}

static void sweep_is_odd(void)
{
    for (int i = 0; i < N_UINT_VALS; i++) {
        uint32_t a = UINT_VALS[i];
        emit1u("FUN_1000_fe4a", a, FUN_1000_fe4a(a));
    }
}

static void sweep_is_printable(void)
{
    for (int a = -5; a < 300; a++)
        emit1i("FUN_1000_d8f6", a, FUN_1000_d8f6(a));
    for (int i = 0; i < N_INT_VALS; i++)
        emit1i("FUN_1000_d8f6", INT_VALS[i], FUN_1000_d8f6(INT_VALS[i]));
}

static void sweep_coord_to_zone(void)
{
    static const int XS[] = {
        0, 0x3b, 0x3c, 0x3d, 0x50, 0x70, 0xba, 0xbb, 0xbc,
        199, 200, 201, 0xc8, 0xc9, 0xca, 0xfc, 0xfd, 0xfe, 0xff, 300
    };
    static const int YS[] = {
        0, 0x3b, 0x3c, 0x3d, 0x50, 0x6d, 0x6e, 0x70, 0x78, 0x79,
        0x7a, 0x81, 0x82, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0xff, 300
    };
    int nx = (int)(sizeof(XS)/sizeof(XS[0]));
    int ny = (int)(sizeof(YS)/sizeof(YS[0]));
    for (int fi = 0; fi < 2; fi++)
        for (int xi = 0; xi < nx; xi++)
            for (int yi = 0; yi < ny; yi++)
                emit3i("FUN_1000_d840", XS[xi], YS[yi], fi,
                       FUN_1000_d840(XS[xi], YS[yi], fi));
}

static void sweep_offset_sentinel(void)
{
    for (int a = -0x7260; a <= -0x7220; a++) {
        if (a > (int32_t)0x7FFFFFEB) continue;
        emit1i("FUN_1000_fd4e", a, FUN_1000_fd4e(a));
    }
    for (int i = 0; i < N_INT_VALS; i++) {
        int a = INT_VALS[i];
        if (a > (int32_t)0x7FFFFFEB) continue;
        emit1i("FUN_1000_fd4e", a, FUN_1000_fd4e(a));
    }
}

static void sweep_div32(void)
{
    for (int i = 0; i < N_U16_VALS; i++)
        for (int j = 0; j < N_U16_VALS; j++)
            for (int k = 0; k < N_U16_VALS; k++)
                for (int l = 0; l < N_U16_VALS; l++) {
                    uint16_t p1 = U16_VALS[i], p2 = U16_VALS[j];
                    uint16_t p3 = U16_VALS[k], p4 = U16_VALS[l];
                    uint32_t out = FUN_1000_f1d6(p1, p2, p3, p4);
                    emit4u16("FUN_1000_f1d6", p1, p2, p3, p4, out);
                }
}

/* =========================================================================
 * Tier 2/3 state-delta helpers
 * ========================================================================= */

/* Snapshot a list of (addr, width) pairs before/after a call and emit JSON. */
typedef struct { uint16_t addr; int is16; } AddrSpec;

static void emit_seg_delta(const char *fn, int tier,
                           const char *args_json,        /* pre-formatted or NULL */
                           long long   ret,              /* INT64_MIN = no ret    */
                           const AddrSpec *specs, int n,
                           const uint16_t *before, const uint16_t *after)
{
    printf("{\"fn\":\"%s\",\"tier\":%d", fn, tier);
    if (args_json)
        printf(",\"args\":%s", args_json);

    printf(",\"seg_in\":{");
    for (int i = 0; i < n; i++) {
        if (i) printf(",");
        printf("\"%x\":%u", specs[i].addr, before[i]);
    }
    printf("},\"seg_out\":{");
    for (int i = 0; i < n; i++) {
        if (i) printf(",");
        printf("\"%x\":%u", specs[i].addr, after[i]);
    }
    printf("}");
    if (ret != (long long)-0x8000000000000000LL)
        printf(",\"ret\":%lld", ret);
    printf("}\n");
}

static void snap(const AddrSpec *specs, int n, uint16_t *out)
{
    for (int i = 0; i < n; i++)
        out[i] = GSEG(specs[i].addr, uint16_t);
}

/* =========================================================================
 * Tier 2 sweeps
 * ========================================================================= */

static void sweep_clear_anim_flag(void)
{
    static const AddrSpec specs[] = { {SEG_ANIM_FLAG, 1} };
    int n = 1;
    uint16_t before[1], after[1];
    /* Two inputs: flag already 0 and flag = 1 */
    uint8_t inputs[] = {0, 1, 0xFF};
    for (int i = 0; i < 3; i++) {
        memset(g_chess_seg, 0, sizeof(g_chess_seg));
        GSEG(SEG_ANIM_FLAG, uint8_t) = inputs[i];
        snap(specs, n, before);
        FUN_1000_e45c();
        snap(specs, n, after);
        emit_seg_delta("FUN_1000_e45c", 2, NULL, (long long)-0x8000000000000000LL,
                       specs, n, before, after);
    }
}

static void sweep_set_text_cursor(void)
{
    static const AddrSpec specs[] = {
        {SEG_TEXT_POS, 1}, {SEG_TEXT_COL, 1}
    };
    int n = 2;
    uint16_t before[2], after[2];
    static const uint16_t params[] = {0, 1, 0xFF, 0x1000, 0x4a00, 0xFFFF};
    for (int i = 0; i < 6; i++) {
        memset(g_chess_seg, 0, sizeof(g_chess_seg));
        /* Seed text_col with non-zero to confirm it gets cleared. */
        GSEG(SEG_TEXT_COL, uint16_t) = 0xDEAD;
        snap(specs, n, before);
        FUN_1000_f2de(params[i]);
        snap(specs, n, after);
        char args[32];
        snprintf(args, sizeof(args), "[%u]", params[i]);
        emit_seg_delta("FUN_1000_f2de", 2, args, (long long)-0x8000000000000000LL,
                       specs, n, before, after);
    }
}

static void sweep_handle_nav_key(void)
{
    static const AddrSpec specs[] = {
        {SEG_NAV_COL, 1}, {SEG_NAV_ROW, 1}
    };
    int n = 2;
    uint16_t before[2], after[2];
    static const char keys[] = {'H', 'K', 'M', 'P', 'A', '\0', ' '};
    for (int row = 0; row <= 7; row++) {
        for (int col = 0; col <= 7; col++) {
            for (int ki = 0; ki < 7; ki++) {
                char key = keys[ki];
                memset(g_chess_seg, 0, sizeof(g_chess_seg));
                GSEG(SEG_NAV_COL, int16_t) = (int16_t)col;
                GSEG(SEG_NAV_ROW, int16_t) = (int16_t)row;
                snap(specs, n, before);
                uint16_t ret = FUN_1000_fd6a(key);
                snap(specs, n, after);
                char args[16];
                snprintf(args, sizeof(args), "[%d]", (int)(unsigned char)key);
                emit_seg_delta("FUN_1000_fd6a", 2, args, (long long)ret,
                               specs, n, before, after);
            }
        }
    }
}

static void sweep_snapshot_viewport(void)
{
    static const AddrSpec specs[] = {
        {SEG_VP_SRC_0,1},{SEG_VP_SRC_1,1},{SEG_VP_SRC_2,1},{SEG_VP_SRC_3,1},
        {SEG_VP_SNAP_0,1},{SEG_VP_SNAP_1,1},{SEG_VP_SNAP_2,1},{SEG_VP_SNAP_3,1},
        {SEG_STACK_DEPTH,1},
    };
    int n = 9;
    uint16_t before[9], after[9];
    static const uint16_t SRC_SETS[][4] = {
        {0,0,0,0}, {1,2,3,4}, {0xFFFF,0x8000,0x1234,0xABCD}
    };
    for (int s = 0; s < 3; s++) {
        memset(g_chess_seg, 0, sizeof(g_chess_seg));
        GSEG(SEG_VP_SRC_0, uint16_t) = SRC_SETS[s][0];
        GSEG(SEG_VP_SRC_1, uint16_t) = SRC_SETS[s][1];
        GSEG(SEG_VP_SRC_2, uint16_t) = SRC_SETS[s][2];
        GSEG(SEG_VP_SRC_3, uint16_t) = SRC_SETS[s][3];
        GSEG(SEG_VP_SNAP_0, uint16_t) = 0xDEAD;
        snap(specs, n, before);
        FUN_1000_7da8();
        snap(specs, n, after);
        emit_seg_delta("FUN_1000_7da8", 2, NULL, (long long)-0x8000000000000000LL,
                       specs, n, before, after);
    }
}

/* =========================================================================
 * Tier 1 extra sweep — mul32
 * ========================================================================= */

static void sweep_mul32(void)
{
    static const uint16_t LO[] = {
        0, 1, 2, 0xFF, 0x100, 0x7FFF, 0x8000, 0xFFFF,
        0x1234, 0x5678, 0xABCD,
    };
    static const int16_t HI[] = {
        0, 1, -1, 0x7FFF, (int16_t)0x8000,
    };
    int nlo = (int)(sizeof(LO)/sizeof(LO[0]));
    int nhi = (int)(sizeof(HI)/sizeof(HI[0]));

    for (int i = 0; i < nlo; i++)
      for (int j = 0; j < nhi; j++)
        for (int k = 0; k < nlo; k++)
          for (int l = 0; l < nhi; l++) {
              uint16_t p1 = LO[i]; int16_t p2 = HI[j];
              uint16_t p3 = LO[k]; int16_t p4 = HI[l];
              uint32_t out = FUN_1000_f32e(p1, p2, p3, p4);
              printf("{\"fn\":\"FUN_1000_f32e\",\"tier\":1,"
                     "\"in\":[%u,%d,%u,%d],\"out\":%u}\n",
                     p1, p2, p3, p4, out);
          }
}

/* =========================================================================
 * Tier 3 sweeps
 * ========================================================================= */

static const uint16_t T3_SRC_ADDRS[8] = {
    SEG_GR_SRC_0, SEG_GR_SRC_1, SEG_GR_SRC_2, SEG_GR_SRC_3,
    SEG_GR_SRC_4, SEG_GR_SRC_5, SEG_GR_SRC_6, SEG_GR_SRC_7,
};
static const uint16_t T3_DST_ADDRS[8] = {
    SEG_GR_DST_0, SEG_GR_DST_1, SEG_GR_DST_2, SEG_GR_DST_3,
    SEG_GR_DST_4, SEG_GR_DST_5, SEG_GR_DST_6, SEG_GR_DST_7,
};

static void sweep_save_game_regs(void)
{
    /* AddrSpec array: 8 src + 8 dst = 16 slots */
    AddrSpec specs[16];
    for (int i = 0; i < 8; i++) specs[i]   = (AddrSpec){T3_SRC_ADDRS[i], 1};
    for (int i = 0; i < 8; i++) specs[8+i] = (AddrSpec){T3_DST_ADDRS[i], 1};
    uint16_t before[16], after[16];

    static const uint16_t SETS[][8] = {
        {0,0,0,0,0,0,0,0},
        {1,2,3,4,5,6,7,8},
        {0xFFFF,0x0001,0x8000,0x7FFF,0xAAAA,0x5555,0xFF00,0x00FF},
        {0x1234,0x5678,0x9ABC,0xDEF0,0x0F0F,0xF0F0,0xA5A5,0x5A5A},
    };
    for (int s = 0; s < 4; s++) {
        memset(g_chess_seg, 0, sizeof(g_chess_seg));
        for (int i = 0; i < 8; i++)
            GSEG(T3_SRC_ADDRS[i], uint16_t) = SETS[s][i];
        snap(specs, 16, before);
        FUN_1000_2c46();
        snap(specs, 16, after);
        emit_seg_delta("FUN_1000_2c46", 3, NULL, (long long)-0x8000000000000000LL,
                       specs, 16, before, after);
    }
}

static void sweep_restore_game_regs(void)
{
    AddrSpec specs[16];
    for (int i = 0; i < 8; i++) specs[i]   = (AddrSpec){T3_DST_ADDRS[i], 1};
    for (int i = 0; i < 8; i++) specs[8+i] = (AddrSpec){T3_SRC_ADDRS[i], 1};
    uint16_t before[16], after[16];

    static const uint16_t SETS[][8] = {
        {0,0,0,0,0,0,0,0},
        {1,2,3,4,5,6,7,8},
        {0xFFFF,0x0001,0x8000,0x7FFF,0xAAAA,0x5555,0xFF00,0x00FF},
        {0x1234,0x5678,0x9ABC,0xDEF0,0x0F0F,0xF0F0,0xA5A5,0x5A5A},
    };
    for (int s = 0; s < 4; s++) {
        memset(g_chess_seg, 0, sizeof(g_chess_seg));
        for (int i = 0; i < 8; i++)
            GSEG(T3_DST_ADDRS[i], uint16_t) = SETS[s][i];
        snap(specs, 16, before);
        FUN_1000_2c79();
        snap(specs, 16, after);
        emit_seg_delta("FUN_1000_2c79", 3, NULL, (long long)-0x8000000000000000LL,
                       specs, 16, before, after);
    }
}

static void sweep_clamp_text_size(void)
{
    static const AddrSpec specs[] = {
        {SEG_TS_WIDTH,1},{SEG_TS_HEIGHT,1},
        {SEG_TS_DIRTY,1},{SEG_TS_ZAP,1},
        {SEG_TS_CLAMP_W,1},{SEG_TS_CLAMP_H,1},
    };
    int n = 6;
    uint16_t before[6], after[6];

    /* Interesting (width, height) pairs */
    static const int16_t WH[][2] = {
        {0,0},{1,0},{2,0},{3,0},{4,0},{100,0},
        {0,-1},{5,-1},{0,1},{1,1},{3,1},{100,10},
        {0x7FFF,0x7FFF},{0xFFFF,(int16_t)0x8001},
    };
    int np = (int)(sizeof(WH)/sizeof(WH[0]));
    for (int i = 0; i < np; i++) {
        memset(g_chess_seg, 0, sizeof(g_chess_seg));
        GSEG(SEG_TS_WIDTH,  uint16_t) = (uint16_t)WH[i][0];
        GSEG(SEG_TS_HEIGHT, int16_t)  = WH[i][1];
        snap(specs, n, before);
        FUN_1000_8a64();
        snap(specs, n, after);
        char args[32];
        snprintf(args, sizeof(args), "[%d,%d]", (int)(uint16_t)WH[i][0], (int)WH[i][1]);
        emit_seg_delta("FUN_1000_8a64", 3, args, (long long)-0x8000000000000000LL,
                       specs, n, before, after);
    }
}

static const uint16_t T3_DSTB_ADDRS[8] = {
    SEG_GR_DSTB_0, SEG_GR_DSTB_1, SEG_GR_DSTB_2, SEG_GR_DSTB_3,
    SEG_GR_DSTB_4, SEG_GR_DSTB_5, SEG_GR_DSTB_6, SEG_GR_DSTB_7,
};

static void sweep_save_game_regs_b(void)
{
    AddrSpec specs[16];
    for (int i = 0; i < 8; i++) specs[i]   = (AddrSpec){T3_SRC_ADDRS[i],  1};
    for (int i = 0; i < 8; i++) specs[8+i] = (AddrSpec){T3_DSTB_ADDRS[i], 1};
    uint16_t before[16], after[16];

    static const uint16_t SETS[][8] = {
        {0,0,0,0,0,0,0,0},
        {1,2,3,4,5,6,7,8},
        {0xFFFF,0x0001,0x8000,0x7FFF,0xAAAA,0x5555,0xFF00,0x00FF},
    };
    for (int s = 0; s < 3; s++) {
        memset(g_chess_seg, 0, sizeof(g_chess_seg));
        for (int i = 0; i < 8; i++)
            GSEG(T3_SRC_ADDRS[i], uint16_t) = SETS[s][i];
        snap(specs, 16, before);
        FUN_1000_2cac();
        snap(specs, 16, after);
        emit_seg_delta("FUN_1000_2cac", 3, NULL, (long long)-0x8000000000000000LL,
                       specs, 16, before, after);
    }
}

static void sweep_restore_game_regs_b(void)
{
    AddrSpec specs[16];
    for (int i = 0; i < 8; i++) specs[i]   = (AddrSpec){T3_DSTB_ADDRS[i], 1};
    for (int i = 0; i < 8; i++) specs[8+i] = (AddrSpec){T3_SRC_ADDRS[i],  1};
    uint16_t before[16], after[16];

    static const uint16_t SETS[][8] = {
        {0,0,0,0,0,0,0,0},
        {1,2,3,4,5,6,7,8},
        {0xFFFF,0x0001,0x8000,0x7FFF,0xAAAA,0x5555,0xFF00,0x00FF},
    };
    for (int s = 0; s < 3; s++) {
        memset(g_chess_seg, 0, sizeof(g_chess_seg));
        for (int i = 0; i < 8; i++)
            GSEG(T3_DSTB_ADDRS[i], uint16_t) = SETS[s][i];
        snap(specs, 16, before);
        FUN_1000_2ce0();
        snap(specs, 16, after);
        emit_seg_delta("FUN_1000_2ce0", 3, NULL, (long long)-0x8000000000000000LL,
                       specs, 16, before, after);
    }
}

static void sweep_init_callback_table(void)
{
    /* No variable inputs — one record confirming constant writes. */
    static const AddrSpec specs[] = {
        {SEG_CB0_OFF,1},{SEG_CB0_SEG,1},{SEG_CB1_OFF,1},{SEG_CB1_SEG,1},
        {SEG_CB2_OFF,1},{SEG_CB2_SEG,1},{SEG_CB3_OFF,1},{SEG_CB3_SEG,1},
        {SEG_CB4_OFF,1},{SEG_CB4_SEG,1},{SEG_CB5_OFF,1},{SEG_CB5_SEG,1},
        {SEG_CB6_OFF,1},{SEG_CB6_SEG,1},{SEG_CB7_OFF,1},{SEG_CB7_SEG,1},
    };
    int n = 16;
    uint16_t before[16], after[16];

    memset(g_chess_seg, 0, sizeof(g_chess_seg));
    snap(specs, n, before);
    FUN_1000_29b9();
    snap(specs, n, after);
    emit_seg_delta("FUN_1000_29b9", 3, NULL, (long long)-0x8000000000000000LL,
                   specs, n, before, after);
}

static void sweep_pack_char_cell(void)
{
    /* Output addresses: use a safe base 0x6000; vary col 0–3. */
    static const uint16_t BASE = 0x6000;
    static const uint8_t  COLS[] = {0, 1, 2, 3};
    static const uint8_t  CHARS[] = {' ', 'A', 0x00, 0xFF};
    static const uint8_t  FG[] = {0, 1, 2, 3};
    static const uint8_t  BG[] = {0, 1, 2, 3};
    static const int8_t   FLAGS[] = {0, 1};  /* bold/uline/blink */

    AddrSpec specs[4];
    specs[0] = (AddrSpec){SEG_CHAR_VAL,    1};
    specs[1] = (AddrSpec){SEG_FG_COLOR,    1};
    specs[2] = (AddrSpec){SEG_BG_COLOR,    1};
    specs[3] = (AddrSpec){SEG_TEXT_BOLD,   1};
    /* We snapshot outputs separately since they're at computed addresses. */

    for (int ci = 0; ci < 4; ci++) {
        for (int fi = 0; fi < 4; fi++) {
            for (int bi = 0; bi < 4; bi++) {
                for (int col = 0; col < 4; col++) {
                    for (int bold = 0; bold < 2; bold++) {
                        memset(g_chess_seg, 0, sizeof(g_chess_seg));
                        GSEG(SEG_CHAR_VAL,    uint8_t) = CHARS[ci];
                        GSEG(SEG_FG_COLOR,    uint8_t) = FG[fi];
                        GSEG(SEG_BG_COLOR,    uint8_t) = BG[bi];
                        GSEG(SEG_TEXT_BOLD,   int8_t)  = FLAGS[bold];
                        GSEG(SEG_TEXT_ULINE,  int8_t)  = FLAGS[bold];
                        GSEG(SEG_TEXT_BLINK,  int8_t)  = 0;

                        uint16_t off = (uint16_t)(BASE + (unsigned)COLS[col] * 2);
                        FUN_1000_931c(BASE, COLS[col]);

                        uint8_t out_char = GSEG(off,     uint8_t);
                        uint8_t out_attr = GSEG(off + 1, uint8_t);

                        printf("{\"fn\":\"FUN_1000_931c\",\"tier\":2,"
                               "\"args\":[%u,%u],"
                               "\"seg_in\":{"
                               "\"%x\":%u,\"%x\":%u,\"%x\":%u,"
                               "\"%x\":%u,\"%x\":%u},"
                               "\"seg_out\":{\"%x\":%u,\"%x\":%u}}\n",
                               (unsigned)BASE, (unsigned)COLS[col],
                               SEG_CHAR_VAL, CHARS[ci],
                               SEG_FG_COLOR, FG[fi],
                               SEG_BG_COLOR, BG[bi],
                               SEG_TEXT_BOLD,  (unsigned)(uint8_t)FLAGS[bold],
                               SEG_TEXT_ULINE, (unsigned)(uint8_t)FLAGS[bold],
                               (unsigned)off, out_char,
                               (unsigned)(off+1), out_attr);
                    }
                }
            }
        }
    }
}

static void sweep_flag_byte_check(void)
{
    /* Sweep param_1 over [0, 255] with flag byte 0 and 1. */
    static const AddrSpec specs_dummy[] = {{SEG_FLAG_TABLE, 1}};
    (void)specs_dummy;
    for (int p = 0; p <= 255; p++) {
        for (int flag = 0; flag <= 1; flag++) {
            memset(g_chess_seg, 0, sizeof(g_chess_seg));
            GSEG((uint16_t)(p + SEG_FLAG_TABLE), uint8_t) = (uint8_t)flag;
            int result = FUN_1000_f1bc(p);
            printf("{\"fn\":\"FUN_1000_f1bc\",\"tier\":3,"
                   "\"args\":[%d],"
                   "\"seg_in\":{\"%x\":%d},"
                   "\"seg_out\":{\"%x\":%d},"
                   "\"ret\":%d}\n",
                   p,
                   (unsigned)(p + SEG_FLAG_TABLE), flag,
                   (unsigned)(p + SEG_FLAG_TABLE), flag,
                   result);
        }
    }
}

static void sweep_write_tile_entry(void)
{
    /* Sweep param_3 over [0, 127] with a few (param_1, param_2) pairs. */
    static const uint8_t VALS[][2] = {
        {0x00, 0x00}, {0x06, 0x00}, {0x06, 0x01}, {0x01, 0x01},
        {0xFF, 0x00}, {0xFF, 0x01}, {0x03, 0x01},
    };
    int nv = (int)(sizeof(VALS)/sizeof(VALS[0]));

    for (int v = 0; v < nv; v++) {
        for (int idx = 0; idx <= 127; idx++) {
            memset(g_chess_seg, 0, sizeof(g_chess_seg));
            FUN_1000_7dbf(VALS[v][0], VALS[v][1], idx);
            uint16_t a0 = (uint16_t)(SEG_TILE_TABLE + (unsigned)idx * 4);
            uint16_t a1 = (uint16_t)(SEG_TILE_TABLE + (unsigned)idx * 4 + 1);
            printf("{\"fn\":\"FUN_1000_7dbf\",\"tier\":3,"
                   "\"args\":[%u,%u,%d],"
                   "\"seg_in\":{},"
                   "\"seg_out\":{\"%x\":%u,\"%x\":%u}}\n",
                   VALS[v][0], VALS[v][1], idx,
                   a0, (unsigned)GSEG(a0, uint8_t),
                   a1, (unsigned)GSEG(a1, uint8_t));
        }
    }
}

static void sweep_next_slot(void)
{
    /* Sweep all 256 occupancy patterns × 8 start slots × fwd/bwd. */
    static const uint16_t BASE = 0x2000;

    for (int pat = 0; pat < 256; pat++) {
        int any_occ = 0;
        for (int i = 0; i < 8; i++)
            if (!((pat >> i) & 1)) { any_occ = 1; break; }
        if (!any_occ) continue;  /* all-empty: would loop forever */

        /* Set occupancy: bit i=0 → occupied (0x00), bit i=1 → empty (0xff) */
        for (int start = 0; start < 8; start++) {
            memset(g_chess_seg, 0, sizeof(g_chess_seg));
            for (int i = 0; i < 8; i++) {
                uint8_t v = ((pat >> i) & 1) ? 0xff : 0x00;
                GSEG((uint16_t)(BASE + i * 0x10 + 0x0f), uint8_t) = v;
            }

            /* Snapshot the 8 occupancy bytes. */
            AddrSpec specs[8];
            for (int i = 0; i < 8; i++)
                specs[i] = (AddrSpec){(uint16_t)(BASE + i * 0x10 + 0x0f), 0};
            uint16_t before[8], after_f[8], after_b[8];
            snap(specs, 8, before);

            int ret_f = FUN_1000_db3d(BASE, start);
            snap(specs, 8, after_f);

            /* Restore and run backward. */
            for (int i = 0; i < 8; i++) {
                uint8_t v = ((pat >> i) & 1) ? 0xff : 0x00;
                GSEG((uint16_t)(BASE + i * 0x10 + 0x0f), uint8_t) = v;
            }
            int ret_b = FUN_1000_db65(BASE, start);
            snap(specs, 8, after_b);

            char args[32];
            snprintf(args, sizeof(args), "[%d,%d]", (int)BASE, start);
            emit_seg_delta("FUN_1000_db3d", 3, args, (long long)ret_f,
                           specs, 8, before, after_f);
            /* Restore before[] for backward emit. */
            snap(specs, 8, before);  /* after backward run: no seg change */
            emit_seg_delta("FUN_1000_db65", 3, args, (long long)ret_b,
                           specs, 8, before, after_b);
        }
    }
}

static void sweep_compute_row_bitmasks(void)
{
    /* A few representative board configurations. */
    struct { uint8_t board[64]; int param; } cases[] = {
        /* All empty */
        {{ 0 }, 0},
        {{ 0 }, 1},
        /* Single player-A piece at (0,0) */
        {{ 0x01 }, 1},
        {{ 0x01 }, 0},
        /* Single player-B piece at (0,0) */
        {{ 0x41 }, 0},
        {{ 0x41 }, 1},
        /* Full board: alternating A/B */
        {{ 0 }, 0},  /* will be overridden below */
    };
    /* Fill alternating case */
    for (int i = 0; i < 64; i++) cases[6].board[i] = (i % 2 == 0) ? 0x01 : 0x41;
    cases[6].param = 1;

    int ncases = 7;
    /* Include 32 uint16_t words covering the 64 board bytes (input) +
     * 4 uint16_t words covering the 8 row bitmask bytes (output) so that
     * different board configurations produce distinct seg_in keys. */
    AddrSpec specs[36];
    for (int i = 0; i < 32; i++)
        specs[i] = (AddrSpec){(uint16_t)(SEG_BOARD_STATE + i * 2), 1};
    for (int r = 0; r < 4; r++)
        specs[32 + r] = (AddrSpec){(uint16_t)(SEG_ROW_BMASK_0 + r * 2), 1};
    uint16_t before[36], after[36];

    for (int c = 0; c < ncases; c++) {
        memset(g_chess_seg, 0, sizeof(g_chess_seg));
        for (int i = 0; i < 64; i++)
            GSEG((uint16_t)(SEG_BOARD_STATE + i), uint8_t) = cases[c].board[i];
        snap(specs, 36, before);
        FUN_1000_fce8(cases[c].param);
        snap(specs, 36, after);
        char args[16];
        snprintf(args, sizeof(args), "[%d]", cases[c].param);
        emit_seg_delta("FUN_1000_fce8", 3, args, (long long)-0x8000000000000000LL,
                       specs, 36, before, after);
    }
}

/* =========================================================================
 * main
 * ========================================================================= */

int main(void)
{
    /* Tier 1 */
    sweep_min_int();
    sweep_max_int();
    sweep_abs_int();
    sweep_is_odd();
    sweep_is_printable();
    sweep_coord_to_zone();
    sweep_offset_sentinel();
    sweep_div32();
    sweep_mul32();
    /* Tier 2 */
    sweep_clear_anim_flag();
    sweep_set_text_cursor();
    sweep_pack_char_cell();
    sweep_handle_nav_key();
    sweep_snapshot_viewport();
    /* Tier 3 — slot A */
    sweep_save_game_regs();
    sweep_restore_game_regs();
    sweep_clamp_text_size();
    /* Tier 3 — slot B + callback table */
    sweep_save_game_regs_b();
    sweep_restore_game_regs_b();
    sweep_init_callback_table();
    /* Tier 3 — flag_byte_check + compute_row_bitmasks */
    sweep_flag_byte_check();
    sweep_compute_row_bitmasks();
    /* Tier 3 — write_tile_entry + next_slot_fwd/bwd */
    sweep_write_tile_entry();
    sweep_next_slot();
    return 0;
}
