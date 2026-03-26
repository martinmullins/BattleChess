import {
  WHITE, EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING,
  pieceType, pieceColor, sq, sqFile, sqRank,
} from '../chess/types.js';
import { BoardState } from '../chess/board.js';
import { Move } from '../chess/types.js';
import { PIECE_SPRITES, loadAllSprites } from '../sprites/pieceSprites.js';

// Unicode chess pieces fallback: [WHITE, BLACK] per piece type index
const PIECE_GLYPH: Record<number, [string, string]> = {
  [PAWN]:   ['♙', '♟'],
  [KNIGHT]: ['♘', '♞'],
  [BISHOP]: ['♗', '♝'],
  [ROOK]:   ['♖', '♜'],
  [QUEEN]:  ['♕', '♛'],
  [KING]:   ['♔', '♚'],
};

// Board colors — dark medieval palette
const COLOR_LIGHT  = '#c8a96e';
const COLOR_DARK   = '#7a4f2a';
const COLOR_SEL    = '#f0f040cc';
const COLOR_MOVE   = '#40f04088';
const COLOR_LAST   = '#40a0ff55';
const COLOR_CHECK  = '#ff202088';

export class Renderer {
  private ctx: CanvasRenderingContext2D;
  private size: number;
  private squareSize: number;
  private flipped: boolean = false;
  private sprites: Map<string, HTMLImageElement> = new Map();
  private spritesReady: boolean = false;

  constructor(canvas: HTMLCanvasElement, onSpritesReady?: () => void) {
    this.ctx = canvas.getContext('2d')!;
    this.size = canvas.width;
    this.squareSize = this.size / 8;
    // Load sprites asynchronously; renderer falls back to glyphs until ready
    loadAllSprites().then(map => {
      this.sprites = map;
      this.spritesReady = true;
      onSpritesReady?.();
    });
  }

  setFlipped(f: boolean): void { this.flipped = f; }

  /** Convert square index to canvas pixel top-left. */
  squareToPixel(s: number): { x: number; y: number } {
    const file = sqFile(s);
    const rank = sqRank(s);
    const drawFile = this.flipped ? 7 - file : file;
    const drawRank = this.flipped ? rank : 7 - rank;
    return { x: drawFile * this.squareSize, y: drawRank * this.squareSize };
  }

  /** Convert canvas coordinates to square index. */
  pixelToSquare(px: number, py: number): number {
    const df = Math.floor(px / this.squareSize);
    const dr = Math.floor(py / this.squareSize);
    const file = this.flipped ? 7 - df : df;
    const rank = this.flipped ? dr : 7 - dr;
    if (file < 0 || file > 7 || rank < 0 || rank > 7) return -1;
    return sq(file, rank);
  }

  draw(
    board: BoardState,
    selected: number,
    legalTargets: number[],
    lastMove: Move | null,
    checkedKing: number,
  ): void {
    const { ctx, squareSize } = this;
    const ss = squareSize;

    // Draw squares
    for (let r = 0; r < 8; r++) {
      for (let f = 0; f < 8; f++) {
        const s = sq(f, r);
        const { x, y } = this.squareToPixel(s);

        // Base color
        ctx.fillStyle = (f + r) % 2 === 0 ? COLOR_DARK : COLOR_LIGHT;
        ctx.fillRect(x, y, ss, ss);

        // Highlights
        if (lastMove && (s === lastMove.from || s === lastMove.to)) {
          ctx.fillStyle = COLOR_LAST;
          ctx.fillRect(x, y, ss, ss);
        }
        if (s === selected) {
          ctx.fillStyle = COLOR_SEL;
          ctx.fillRect(x, y, ss, ss);
        }
        if (s === checkedKing) {
          ctx.fillStyle = COLOR_CHECK;
          ctx.fillRect(x, y, ss, ss);
        }
        if (legalTargets.includes(s)) {
          // Dot for empty squares, ring for captures
          const piece = board.squares[s];
          if (piece === EMPTY) {
            ctx.fillStyle = COLOR_MOVE;
            ctx.beginPath();
            ctx.arc(x + ss / 2, y + ss / 2, ss * 0.15, 0, Math.PI * 2);
            ctx.fill();
          } else {
            ctx.strokeStyle = COLOR_MOVE;
            ctx.lineWidth = 4;
            ctx.beginPath();
            ctx.arc(x + ss / 2, y + ss / 2, ss * 0.42, 0, Math.PI * 2);
            ctx.stroke();
          }
        }

        // Draw piece
        const piece = board.squares[s];
        if (piece !== EMPTY) {
          const pt = pieceType(piece);
          const col = pieceColor(piece);
          this.drawPiece(ctx, piece, pt, col, x, y, ss);
        }
      }
    }

    // Rank/file labels
    ctx.font = `${ss * 0.18}px monospace`;
    ctx.textAlign = 'left';
    ctx.textBaseline = 'top';
    for (let r = 0; r < 8; r++) {
      const rank = this.flipped ? r + 1 : 8 - r;
      const { y } = this.squareToPixel(sq(0, this.flipped ? r : 7 - r));
      ctx.fillStyle = r % 2 === 0 ? COLOR_LIGHT : COLOR_DARK;
      ctx.fillText(String(rank), 2, y + 2);
    }
    ctx.textAlign = 'right';
    ctx.textBaseline = 'bottom';
    for (let f = 0; f < 8; f++) {
      const file = String.fromCharCode(97 + (this.flipped ? 7 - f : f));
      const { x } = this.squareToPixel(sq(this.flipped ? 7 - f : f, 0));
      ctx.fillStyle = f % 2 === 0 ? COLOR_DARK : COLOR_LIGHT;
      ctx.fillText(file, x + ss - 2, this.size - 2);
    }
  }

  /** Draw a single piece using a sprite if loaded, otherwise fall back to a glyph. */
  private drawPiece(
    ctx: CanvasRenderingContext2D,
    _piece: number,
    pt: number,
    col: number,
    x: number,
    y: number,
    ss: number,
  ): void {
    const info = PIECE_SPRITES[col]?.[pt];
    const img = info ? this.sprites.get(info.filename) : undefined;

    if (this.spritesReady && img && img.complete && img.naturalWidth > 0) {
      // Scale sprite to fit within the square, maintaining aspect ratio,
      // and centre it.
      const scale = Math.min((ss * 0.85) / info.w, (ss * 0.92) / info.h);
      const dw = info.w * scale;
      const dh = info.h * scale;
      const dx = x + (ss - dw) / 2;
      const dy = y + ss - dh - ss * 0.03; // bottom-align with small padding

      // Drop shadow
      ctx.save();
      ctx.globalAlpha = 0.35;
      ctx.filter = 'blur(2px)';
      ctx.drawImage(img, dx + 2, dy + 3, dw, dh);
      ctx.restore();

      // Sprite
      ctx.save();
      ctx.imageSmoothingEnabled = false;
      ctx.drawImage(img, dx, dy, dw, dh);
      ctx.restore();
    } else {
      // Glyph fallback
      const glyph = PIECE_GLYPH[pt]?.[col] ?? '?';
      ctx.font = `bold ${ss * 0.72}px serif`;
      ctx.textAlign = 'center';
      ctx.textBaseline = 'middle';
      ctx.fillStyle = 'rgba(0,0,0,0.5)';
      ctx.fillText(glyph, x + ss / 2 + 2, y + ss / 2 + 2);
      ctx.fillStyle = col === WHITE ? '#f8f0d8' : '#1a0a00';
      ctx.fillText(glyph, x + ss / 2, y + ss / 2);
      if (col === WHITE) {
        ctx.strokeStyle = '#5a3010';
        ctx.lineWidth = 0.5;
        ctx.strokeText(glyph, x + ss / 2, y + ss / 2);
      }
    }
  }
}
