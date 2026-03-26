// @vitest-environment jsdom
import { describe, it, expect, vi, beforeEach } from 'vitest';
import { Renderer } from './renderer.js';
import { sq } from '../chess/types.js';

// Prevent real image loading during tests
vi.mock('../sprites/pieceSprites.js', () => ({
  PIECE_SPRITES: {},
  loadAllSprites: () => Promise.resolve(new Map()),
}));

/** Build a minimal CanvasRenderingContext2D mock */
function makeMockCtx(): CanvasRenderingContext2D {
  const noop = vi.fn();
  return {
    fillRect: noop, clearRect: noop, strokeRect: noop,
    fillText: noop, strokeText: noop,
    beginPath: noop, arc: noop, fill: noop, stroke: noop,
    save: noop, restore: noop, drawImage: noop,
    font: '', fillStyle: '', strokeStyle: '',
    lineWidth: 1, textAlign: 'left', textBaseline: 'top',
    globalAlpha: 1, filter: '', imageSmoothingEnabled: true,
  } as unknown as CanvasRenderingContext2D;
}

function makeRenderer(size = 512, flipped = false): Renderer {
  const canvas = document.createElement('canvas');
  canvas.width  = size;
  canvas.height = size;
  vi.spyOn(canvas, 'getContext').mockReturnValue(makeMockCtx());
  const r = new Renderer(canvas);
  if (flipped) r.setFlipped(true);
  return r;
}

// Each square is 64 px wide/tall on a 512 px canvas
const SS = 512 / 8;

// Center pixel of a given square in canvas coordinates (unflipped)
function centerOf(file: number, rank: number) {
  // drawFile=file, drawRank=7-rank  →  x=file*SS, y=(7-rank)*SS
  return { px: file * SS + SS / 2, py: (7 - rank) * SS + SS / 2 };
}

// ---------------------------------------------------------------------------
// pixelToSquare — unflipped board
// ---------------------------------------------------------------------------

describe('pixelToSquare (unflipped)', () => {
  let r: Renderer;
  beforeEach(() => { r = makeRenderer(); });

  it('maps center of a1 → sq(0,0)', () => {
    const { px, py } = centerOf(0, 0);
    expect(r.pixelToSquare(px, py)).toBe(sq(0, 0));
  });

  it('maps center of h8 → sq(7,7)', () => {
    const { px, py } = centerOf(7, 7);
    expect(r.pixelToSquare(px, py)).toBe(sq(7, 7));
  });

  it('maps center of a8 → sq(0,7)', () => {
    const { px, py } = centerOf(0, 7);
    expect(r.pixelToSquare(px, py)).toBe(sq(0, 7));
  });

  it('maps center of h1 → sq(7,0)', () => {
    const { px, py } = centerOf(7, 0);
    expect(r.pixelToSquare(px, py)).toBe(sq(7, 0));
  });

  it('maps center of e4 → sq(4,3)', () => {
    const { px, py } = centerOf(4, 3);
    expect(r.pixelToSquare(px, py)).toBe(sq(4, 3));
  });

  it('returns -1 for negative coordinates', () => {
    expect(r.pixelToSquare(-1, 100)).toBe(-1);
  });

  it('returns -1 for coordinates beyond canvas edge', () => {
    expect(r.pixelToSquare(513, 100)).toBe(-1);
    expect(r.pixelToSquare(100, 513)).toBe(-1);
  });

  it('all 64 squares: pixelToSquare(center) equals the square index', () => {
    for (let file = 0; file < 8; file++) {
      for (let rank = 0; rank < 8; rank++) {
        const { px, py } = centerOf(file, rank);
        expect(r.pixelToSquare(px, py)).toBe(sq(file, rank));
      }
    }
  });
});

// ---------------------------------------------------------------------------
// pixelToSquare — flipped board (black's perspective)
// ---------------------------------------------------------------------------

describe('pixelToSquare (flipped)', () => {
  let r: Renderer;
  beforeEach(() => { r = makeRenderer(512, true); });

  // When flipped: drawFile=7-file, drawRank=rank
  // So a1 (file=0,rank=0) → drawFile=7, drawRank=0 → top-right
  it('a1 is in the top-right corner when flipped', () => {
    const px = 7 * SS + SS / 2; // rightmost column
    const py = 0 * SS + SS / 2; // top row
    expect(r.pixelToSquare(px, py)).toBe(sq(0, 0));
  });

  it('h8 is in the bottom-left corner when flipped', () => {
    const px = 0 * SS + SS / 2; // leftmost column
    const py = 7 * SS + SS / 2; // bottom row
    expect(r.pixelToSquare(px, py)).toBe(sq(7, 7));
  });

  it('all 64 squares round-trip correctly when flipped', () => {
    for (let file = 0; file < 8; file++) {
      for (let rank = 0; rank < 8; rank++) {
        const s = sq(file, rank);
        const { x, y } = r.squareToPixel(s);
        // Center of that square
        expect(r.pixelToSquare(x + SS / 2, y + SS / 2)).toBe(s);
      }
    }
  });
});

// ---------------------------------------------------------------------------
// squareToPixel — unflipped board
// ---------------------------------------------------------------------------

describe('squareToPixel (unflipped)', () => {
  let r: Renderer;
  beforeEach(() => { r = makeRenderer(); });

  it('a1 is at the bottom-left (x=0, y=7*SS)', () => {
    expect(r.squareToPixel(sq(0, 0))).toEqual({ x: 0, y: 7 * SS });
  });

  it('h8 is at the top-right (x=7*SS, y=0)', () => {
    expect(r.squareToPixel(sq(7, 7))).toEqual({ x: 7 * SS, y: 0 });
  });

  it('all 64 squares: squareToPixel → center → pixelToSquare round-trips', () => {
    for (let s = 0; s < 64; s++) {
      const { x, y } = r.squareToPixel(s);
      expect(r.pixelToSquare(x + SS / 2, y + SS / 2)).toBe(s);
    }
  });
});

// ---------------------------------------------------------------------------
// squareToPixel — flipped board
// ---------------------------------------------------------------------------

describe('squareToPixel (flipped)', () => {
  let r: Renderer;
  beforeEach(() => { r = makeRenderer(512, true); });

  it('a1 is at the top-right when flipped (x=7*SS, y=0)', () => {
    expect(r.squareToPixel(sq(0, 0))).toEqual({ x: 7 * SS, y: 0 });
  });

  it('h8 is at the bottom-left when flipped (x=0, y=7*SS)', () => {
    expect(r.squareToPixel(sq(7, 7))).toEqual({ x: 0, y: 7 * SS });
  });
});

// ---------------------------------------------------------------------------
// Non-512 canvas size
// ---------------------------------------------------------------------------

describe('pixelToSquare on smaller canvas (360px)', () => {
  it('correctly maps center of a1 to sq(0,0)', () => {
    const r = makeRenderer(360);
    const ss = 360 / 8; // 45px
    expect(r.pixelToSquare(ss / 2, 7 * ss + ss / 2)).toBe(sq(0, 0));
  });
});
