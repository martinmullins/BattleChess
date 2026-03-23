#!/usr/bin/env python3
"""
Battle Chess ALLCANM1/ALLCANM2 animation file decoder.

Analyses and extracts sprites from the two animation data files.
Outputs PNG images for visual inspection.

Usage:
    python3 decode_anm.py [--output-dir DIR] [--verbose]
"""

import struct
import os
import sys
import argparse
import zlib   # for CRC-based PNG writing

BASEDIR = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
ANM1 = os.path.join(BASEDIR, 'ALLCANM1')
ANM2 = os.path.join(BASEDIR, 'ALLCANM2')

# ---------------------------------------------------------------------------
# Minimal PNG writer (no PIL dependency)
# ---------------------------------------------------------------------------

def write_png(path: str, pixels: bytes, width: int, height: int, palette: list[tuple[int,int,int]]) -> None:
    """Write an 8-bit paletted PNG."""
    def chunk(name: bytes, data: bytes) -> bytes:
        c = name + data
        return struct.pack('>I', len(data)) + c + struct.pack('>I', zlib.crc32(c) & 0xffffffff)

    # IHDR
    ihdr = struct.pack('>IIBBBBB', width, height, 8, 3, 0, 0, 0)
    # PLTE — pad to 256 colours
    plte_data = bytearray()
    for r, g, b in palette:
        plte_data += bytes([r, g, b])
    while len(plte_data) < 768:
        plte_data += b'\x00\x00\x00'

    # IDAT — raw scanlines with filter byte 0
    raw = bytearray()
    for y in range(height):
        raw += b'\x00'
        raw += pixels[y*width:(y+1)*width]
    idat_data = zlib.compress(bytes(raw), 6)

    with open(path, 'wb') as f:
        f.write(b'\x89PNG\r\n\x1a\n')
        f.write(chunk(b'IHDR', ihdr))
        f.write(chunk(b'PLTE', bytes(plte_data)))
        f.write(chunk(b'IDAT', idat_data))
        f.write(chunk(b'IEND', b''))


def vga_to_rgb(entries: list[tuple[int,int,int]]) -> list[tuple[int,int,int]]:
    """Convert VGA DAC (0–63) values to 8-bit RGB."""
    return [(r*255//63, g*255//63, b*255//63) for r,g,b in entries]


# ---------------------------------------------------------------------------
# Parse the header block (palette + optional index)
# ---------------------------------------------------------------------------

def parse_header(data: bytes, verbose: bool = False) -> tuple[list, int]:
    """
    Read 4-byte records from the start of an ALLCANM file until a (0,0,0,0)
    sentinel is reached.  Returns (records, sentinel_offset+4).
    Records that have all values <= 63 look like VGA DAC palette entries.
    """
    records = []
    i = 0
    while i + 4 <= len(data):
        r, g, b, x = data[i], data[i+1], data[i+2], data[i+3]
        if r == 0 and g == 0 and b == 0 and x == 0:
            if verbose:
                print(f'  Sentinel at offset {i} after {len(records)} records')
            return records, i + 4
        records.append((r, g, b, x))
        i += 4
    return records, i


# ---------------------------------------------------------------------------
# Interpretation 1: records = VGA palette (R,G,B,pad)
# ---------------------------------------------------------------------------

def interpret_as_palette(records: list) -> list[tuple[int,int,int]]:
    """Return RGB 8-bit colours from records treated as VGA DAC entries."""
    return [(r*255//63, g*255//63, b*255//63) for r,g,b,_ in records]


# ---------------------------------------------------------------------------
# Interpretation 2: records = sprite index (w, h, offset_lo, offset_hi)
# ---------------------------------------------------------------------------

def interpret_as_sprite_index(records: list, data_base: int) -> list[dict]:
    """
    Treat each record as (width, height, pixel_offset_lo, pixel_offset_hi).
    pixel_offset is relative to data_base (the start of pixel data in the file).
    """
    sprites = []
    for i, (w, h, ol, oh) in enumerate(records):
        offset = (oh << 8) | ol   # 16-bit offset
        sprites.append({'index': i, 'w': w, 'h': h, 'offset': data_base + offset})
    return sprites


# ---------------------------------------------------------------------------
# RLE decoder (high-bit = run marker)
# ---------------------------------------------------------------------------

def rle_decode(data: bytes, expected_size: int = 0) -> bytes:
    """
    Decode simple RLE where:
      byte >= 0x80  =>  (byte - 0x80) repetitions of next byte
      byte  < 0x80  =>  literal byte
    """
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
        if expected_size and len(out) >= expected_size:
            break
    return bytes(out)


# ---------------------------------------------------------------------------
# Render a raw byte block as a sprite at a given width
# ---------------------------------------------------------------------------

def render_raw(outdir: str, name: str, pixels: bytes, width: int,
               palette: list[tuple[int,int,int]]) -> None:
    height = len(pixels) // width
    if height == 0:
        return
    os.makedirs(outdir, exist_ok=True)
    path = os.path.join(outdir, f'{name}.png')
    write_png(path, pixels[:width*height], width, height, palette)


# ---------------------------------------------------------------------------
# Main analysis
# ---------------------------------------------------------------------------

def analyse(outdir: str, verbose: bool) -> None:
    os.makedirs(outdir, exist_ok=True)

    for fname, path in [('ALLCANM1', ANM1), ('ALLCANM2', ANM2)]:
        if not os.path.exists(path):
            print(f'  {fname} not found, skipping')
            continue

        with open(path, 'rb') as f:
            data = f.read()

        print(f'\n=== {fname} ({len(data):,} bytes) ===')

        # 1. Parse header
        records, pixel_start = parse_header(data, verbose)
        print(f'  Header: {len(records)} records, pixel data starts at offset {pixel_start}')

        # 2. Determine if records look like VGA palette (all values <= 63)
        all_dac = all(max(r,g,b,x) <= 63 for r,g,b,x in records)
        print(f'  All header values <= 63 (VGA DAC range): {all_dac}')

        if all_dac:
            palette = interpret_as_palette(records)
            print(f'  Palette: {len(palette)} colours')
            # Show first few colours
            for i, (r,g,b) in enumerate(palette[:8]):
                print(f'    colour {i:2d}: #{r:02x}{g:02x}{b:02x}')
        else:
            # Fall back to a grayscale palette for inspection
            palette = [(i, i, i) for i in range(256)]
            print(f'  Non-DAC records — using grayscale palette for output')

        pixel_data = data[pixel_start:]
        print(f'  Pixel data: {len(pixel_data):,} bytes')

        # 3. Try rendering raw pixel data as strips at various widths
        subdir = os.path.join(outdir, fname)
        os.makedirs(subdir, exist_ok=True)

        for width in [320, 160, 128, 64, 32]:
            render_raw(subdir, f'raw_w{width}', pixel_data, width, palette)

        print(f'  Raw renders written to {subdir}/')

        # 4. Try sprite index interpretation
        sprites = interpret_as_sprite_index(records, pixel_start)
        valid = [s for s in sprites if s['w'] > 0 and s['h'] > 0
                 and s['offset'] + s['w']*s['h'] <= len(data)]
        print(f'  Sprite index interpretation: {len(valid)}/{len(sprites)} valid entries')
        if valid:
            sdir = os.path.join(subdir, 'sprites_raw')
            os.makedirs(sdir, exist_ok=True)
            for s in valid[:20]:  # first 20
                px = data[s['offset']:s['offset']+s['w']*s['h']]
                if len(px) == s['w']*s['h']:
                    path_out = os.path.join(sdir, f'sprite_{s["index"]:02d}_{s["w"]}x{s["h"]}.png')
                    write_png(path_out, px, s['w'], s['h'], palette)
            print(f'  Sprites written to {sdir}/')

        # 5. Try RLE decode and render
        print(f'  Trying RLE decode of pixel data...')
        rle_out = rle_decode(pixel_data, expected_size=1024*1024)
        print(f'  RLE decoded: {len(pixel_data):,} -> {len(rle_out):,} bytes ({len(rle_out)/len(pixel_data):.1f}x)')
        if len(rle_out) > 1000:
            for width in [320, 128, 64]:
                render_raw(subdir, f'rle_w{width}', rle_out, width, palette)
            print(f'  RLE renders written to {subdir}/')


if __name__ == '__main__':
    ap = argparse.ArgumentParser()
    ap.add_argument('--output-dir', default='extracted_assets',
                    help='directory to write PNG output')
    ap.add_argument('--verbose', '-v', action='store_true')
    args = ap.parse_args()

    outdir = os.path.join(BASEDIR, args.output_dir)
    print(f'Output directory: {outdir}')
    analyse(outdir, args.verbose)
    print('\nDone.')
