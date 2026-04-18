/*
 * oracle_driver.c — Ground-truth input/output oracle for Tier 1 pure functions.
 *
 * Replaces the rr record/replay step for pure functions: since they have no
 * external state, exhaustive enumeration over interesting input domains is
 * equivalent to a full replay trace.
 *
 * Output: NDJSON to stdout, one record per call:
 *   {"fn":"FUN_1000_8fa5","in":[3,7],"out":7}
 *
 * Build:
 *   clang -O2 -std=c11 -o oracle_driver oracle_driver.c ../harnesses/tier1_impl.c
 *
 * Run:
 *   ./oracle_driver > corpus/oracle.ndjson
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "../harnesses/tier1_impl.h"

/* ---- Input domain generators ---- */

/* Representative int32 values: boundaries, small positives/negatives, randoms. */
static const int32_t INT_VALS[] = {
    0, 1, -1, 2, -2, 3, -3,
    0x7F, -0x7F, 0x80, -0x80,
    0x7FFF, -0x7FFF, 0x8000, -0x8000,
    0x7FFFFFFF, -0x7FFFFFFF, /* skip INT_MIN for abs */
    100, -100, 255, -255, 1000, -1000,
    0x3c, 0x3d, 0x8a, 0x8b, 0xbb, 0xba,  /* coord_to_zone boundaries */
    0x6d, 0x6e, 0x78, 0x79,
    0x81, 0x82, 0x8c, 0x8d,
    0xc8, 0xc9, 0xfc, 0xfd,              /* 200 = 0xc8, 253 = 0xfd */
    -0x7234, -0x7235, -0x7248,           /* offset_sentinel inputs */
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

/* ---- Emit helpers ---- */

static void emit1i(const char *fn, int32_t a, int32_t out)
{
    printf("{\"fn\":\"%s\",\"in\":[%d],\"out\":%d}\n", fn, a, out);
}
static void emit2i(const char *fn, int32_t a, int32_t b, int32_t out)
{
    printf("{\"fn\":\"%s\",\"in\":[%d,%d],\"out\":%d}\n", fn, a, b, out);
}
static void emit3i(const char *fn, int32_t a, int32_t b, int32_t c, int32_t out)
{
    printf("{\"fn\":\"%s\",\"in\":[%d,%d,%d],\"out\":%d}\n", fn, a, b, c, out);
}
static void emit1u(const char *fn, uint32_t a, uint32_t out)
{
    printf("{\"fn\":\"%s\",\"in\":[%u],\"out\":%u}\n", fn, a, out);
}
static void emit4u16(const char *fn,
                     uint16_t p1, uint16_t p2, uint16_t p3, uint16_t p4,
                     uint32_t out)
{
    printf("{\"fn\":\"%s\",\"in\":[%u,%u,%u,%u],\"out\":%u}\n",
           fn, p1, p2, p3, p4, out);
}

/* ---- Per-function exhaustive sweeps ---- */

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
        if (a == (int32_t)0x80000000) continue; /* INT_MIN: overflow UB */
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
    /* Full 8-bit sweep (meaningful range) + wider outliers. */
    for (int a = -5; a < 300; a++)
        emit1i("FUN_1000_d8f6", a, FUN_1000_d8f6(a));
    for (int i = 0; i < N_INT_VALS; i++)
        emit1i("FUN_1000_d8f6", INT_VALS[i], FUN_1000_d8f6(INT_VALS[i]));
}

static void sweep_coord_to_zone(void)
{
    /* Sweep over a grid near board boundaries, then spot-check wide inputs. */
    static const int XS[] = {
        0, 0x3b, 0x3c, 0x3d, 0x50, 0x70, 0xba, 0xbb, 0xbc,
        199, 200, 201, 0xc8, 0xc9, 0xca, 0xfc, 0xfd, 0xfe, 0xff, 300
    };
    static const int YS[] = {
        0, 0x3b, 0x3c, 0x3d, 0x50, 0x6d, 0x6e, 0x70, 0x78, 0x79,
        0x7a, 0x81, 0x82, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0xff, 300
    };
    static const int FLAGS[] = {0, 1};
    int nx = (int)(sizeof(XS)/sizeof(XS[0]));
    int ny = (int)(sizeof(YS)/sizeof(YS[0]));
    for (int fi = 0; fi < 2; fi++)
        for (int xi = 0; xi < nx; xi++)
            for (int yi = 0; yi < ny; yi++)
                emit3i("FUN_1000_d840", XS[xi], YS[yi], FLAGS[fi],
                       FUN_1000_d840(XS[xi], YS[yi], FLAGS[fi]));
}

static void sweep_offset_sentinel(void)
{
    /* Dense sweep in the interesting region plus INT_VAL spots. */
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

int main(void)
{
    sweep_min_int();
    sweep_max_int();
    sweep_abs_int();
    sweep_is_odd();
    sweep_is_printable();
    sweep_coord_to_zone();
    sweep_offset_sentinel();
    sweep_div32();
    return 0;
}
