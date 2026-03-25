#!/usr/bin/env python3
"""
Battle Chess ALLCANM1/ALLCANM2 sprite extractor v2.

Key findings:
  - File header: 4-byte records (width, height, offset_lo, offset_hi)
    until sentinel (0, 0, 0, 0)
  - Pixel data section is RLE-compressed (byte >= 0x80 → run of (byte-0x80)
    repetitions of next byte; byte < 0x80 → literal)
  - Sprite offsets point into the RLE-DECODED data, not the raw file
  - Index 255 = background / transparent
  - ALLCANM1 sprites: white pieces (dominant palette ~199-242) and
    black pieces (dominant palette ~24-108)

Usage:
    python3 decode_anm_v2.py [--output-dir DIR] [--verbose]
"""

import struct, os, sys, argparse, zlib

BASEDIR = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
ANM1 = os.path.join(BASEDIR, 'ALLCANM1')
ANM2 = os.path.join(BASEDIR, 'ALLCANM2')

# ---------------------------------------------------------------------------
# VGA-style chess palette
# Built from analysis of pixel-value distributions across white/black sprites.
# Lower indices (0-127)  → dark / shadow tones
# Higher indices (128-254) → light / highlight tones
# Index 255              → transparent (rendered as magenta for visual check)
# ---------------------------------------------------------------------------

def build_chess_palette() -> list[tuple[int,int,int]]:
    """
    Return a 256-entry RGB palette tuned for Battle Chess sprites.

    Key colour mappings derived from per-sprite dominant-index analysis:
      White-piece sprites use indices ~199, 227, 242 (cream/ivory range)
      Black-piece sprites use indices ~24, 48, 108   (dark mahogany range)
    """
    pal = [(0, 0, 0)] * 256

    # Specific known indices → hand-crafted chess colours
    specific = {
        # --- transparent / background ---
        255: (0,   0,   0),    # background black (or use 255,0,255 for debug)

        # --- very dark (shadow / outline) ---
          4: (18,  10,   5),
         24: (30,  16,   8),
         31: (40,  22,  10),
         48: (55,  33,  18),
         53: (62,  38,  20),
         54: (68,  42,  22),
         58: (78,  50,  25),
         59: (84,  54,  28),

        # --- mid-dark (black piece body colours — dark mahogany family) ---
         69: ( 90,  55,  25),
         83: ( 75,  46,  22),
         86: ( 82,  52,  24),
         95: (100,  62,  28),
         97: (106,  66,  30),
        108: ( 90,  56,  26),  # black piece primary colour
        110: ( 95,  60,  28),
        111: ( 98,  62,  29),
        123: (110,  68,  32),
        127: (116,  72,  34),

        # --- mid-tone ---
        143: (185, 148, 102),  # transparent key for black piece sprites
        175: (200, 165, 118),
        185: (208, 175, 128),
        191: (130,  84,  40),  # black piece highlight (dark mahogany, not tan)

        # --- mid-light ---
        198: (220, 188, 140),
        199: (225, 195, 148),
        203: (228, 200, 155),
        223: (235, 215, 175),

        # --- light / cream ---
        227: (240, 222, 185),
        231: (244, 228, 195),
        242: (252, 242, 220),

        # --- near white ---
        251: (254, 250, 240),
        254: (255, 253, 248),
    }
    for idx, rgb in specific.items():
        pal[idx] = rgb

    # Fill the rest with a warm-grey linear ramp
    for i in range(256):
        if pal[i] == (0, 0, 0) and i != 0 and i not in specific:
            t = i / 255
            r = int(t * 240)
            g = int(t * 220)
            b = int(t * 190)
            pal[i] = (r, g, b)

    return pal


# ---------------------------------------------------------------------------
# PNG writer (no PIL) — writes true RGBA (32-bit) PNGs
# ---------------------------------------------------------------------------

def write_png(path: str, pixels: bytes, width: int, height: int,
              palette: list[tuple[int,int,int]],
              transparent_index: int = 255) -> None:
    """Write an RGBA PNG.  Pixels at transparent_index get alpha=0; all others
    get alpha=255 with the RGB from palette."""
    def chunk(name: bytes, data: bytes) -> bytes:
        c = name + data
        return struct.pack('>I', len(data)) + c + struct.pack('>I', zlib.crc32(c) & 0xffffffff)

    # Color type 6 = RGBA (8 bits per channel)
    ihdr = struct.pack('>IIBBBBB', width, height, 8, 6, 0, 0, 0)

    raw = bytearray()
    for y in range(height):
        raw += b'\x00'  # filter: None
        for x in range(width):
            idx = pixels[y * width + x]
            r, g, b = palette[idx]
            a = 0 if idx == transparent_index else 255
            raw += bytes([r, g, b, a])
    idat_data = zlib.compress(bytes(raw), 6)

    with open(path, 'wb') as f:
        f.write(b'\x89PNG\r\n\x1a\n')
        f.write(chunk(b'IHDR', ihdr))
        f.write(chunk(b'IDAT', idat_data))
        f.write(chunk(b'IEND', b''))


# ---------------------------------------------------------------------------
# RLE decoder
# ---------------------------------------------------------------------------

def rle_decode(data: bytes) -> bytes:
    out = bytearray()
    i = 0
    while i < len(data):
        b = data[i]
        if b >= 0x80:
            count = b - 0x80
            if i + 1 < len(data):
                out.extend([data[i+1]] * count)
            i += 2
        else:
            out.append(b)
            i += 1
    return bytes(out)


# ---------------------------------------------------------------------------
# Parse file
# ---------------------------------------------------------------------------

def parse_anm(path: str, verbose: bool) -> tuple[list, bytes]:
    """Return (records, decoded_pixel_data)."""
    with open(path, 'rb') as f:
        data = f.read()

    records = []
    i = 0
    while i + 4 <= len(data):
        r, g, b, x = data[i], data[i+1], data[i+2], data[i+3]
        if r == 0 and g == 0 and b == 0 and x == 0:
            pixel_start = i + 4
            break
        records.append((r, g, b, x))
        i += 4
    else:
        pixel_start = len(data)

    if verbose:
        print(f'  {len(records)} header records, pixel data @ {pixel_start}')

    raw_pixels = data[pixel_start:]
    decoded = rle_decode(raw_pixels)

    if verbose:
        print(f'  RLE: {len(raw_pixels):,} → {len(decoded):,} bytes')

    return records, decoded


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def extract(outdir: str, verbose: bool) -> None:
    os.makedirs(outdir, exist_ok=True)
    palette = build_chess_palette()

    for fname, path in [('ALLCANM1', ANM1), ('ALLCANM2', ANM2)]:
        if not os.path.exists(path):
            print(f'  {fname} not found, skipping')
            continue

        print(f'\n=== {fname} ===')
        records, decoded = parse_anm(path, verbose)

        sdir = os.path.join(outdir, fname, 'sprites')
        os.makedirs(sdir, exist_ok=True)

        extracted = 0
        for idx, (w, h, ol, oh) in enumerate(records):
            if w == 0 or h == 0:
                continue
            offset = (oh << 8) | ol
            px = decoded[offset:offset + w * h]
            if len(px) < w * h:
                if verbose:
                    print(f'  sprite {idx}: only {len(px)}/{w*h} bytes available')
                continue

            # ALLCANM1: white piece sprites (0-11) use index 255 as transparent;
            # black piece sprites (12-31) use index 143 (the board background
            # colour embedded in their bounding boxes) as transparent.
            if fname == 'ALLCANM1' and 12 <= idx <= 31:
                trans = 143
            else:
                trans = 255
            out_path = os.path.join(sdir, f'sprite_{idx:02d}_{w}x{h}.png')
            write_png(out_path, bytes(px), w, h, palette, transparent_index=trans)
            extracted += 1
            if verbose:
                from collections import Counter
                cnt = Counter(px)
                top3 = [v for v, _ in cnt.most_common(3)]
                print(f'  sprite {idx:2d} ({w:2d}x{h:2d}) @ {offset}: top indices {top3}')

        print(f'  {extracted} sprites written to {sdir}/')


if __name__ == '__main__':
    ap = argparse.ArgumentParser()
    ap.add_argument('--output-dir', default='extracted_assets_v2',
                    help='directory to write PNG output (relative to repo root)')
    ap.add_argument('--verbose', '-v', action='store_true')
    args = ap.parse_args()

    outdir = os.path.join(BASEDIR, args.output_dir)
    print(f'Output directory: {outdir}')
    extract(outdir, args.verbose)
    print('\nDone.')
