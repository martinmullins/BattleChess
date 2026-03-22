/** Piece color */
export const WHITE = 0;
export const BLACK = 1;
export type Color = 0 | 1;

/** Piece types (0 = empty) */
export const EMPTY  = 0;
export const PAWN   = 1;
export const KNIGHT = 2;
export const BISHOP = 3;
export const ROOK   = 4;
export const QUEEN  = 5;
export const KING   = 6;
export type PieceType = 0 | 1 | 2 | 3 | 4 | 5 | 6;

/** Packed piece: bits[3:1] = type, bit[0] = color. 0 = empty. */
export type Piece = number;

export function makePiece(type: PieceType, color: Color): Piece {
  return (type << 1) | color;
}
export function pieceType(p: Piece): PieceType {
  return (p >> 1) as PieceType;
}
export function pieceColor(p: Piece): Color {
  return (p & 1) as Color;
}

/** Square index: 0-63, rank-major (a1=0, h1=7, a8=56, h8=63) */
export type Square = number;

export function sq(file: number, rank: number): Square { return rank * 8 + file; }
export function sqFile(s: Square): number { return s & 7; }
export function sqRank(s: Square): number { return s >> 3; }
export function sqValid(s: Square): boolean { return s >= 0 && s < 64; }
export function sqName(s: Square): string {
  return String.fromCharCode(97 + sqFile(s)) + (sqRank(s) + 1);
}

/** Castling rights bitmask */
export const CASTLE_WK = 1;  // white kingside
export const CASTLE_WQ = 2;  // white queenside
export const CASTLE_BK = 4;  // black kingside
export const CASTLE_BQ = 8;  // black queenside

export interface Move {
  from: Square;
  to: Square;
  promotion?: PieceType;  // QUEEN/ROOK/BISHOP/KNIGHT when pawn promotes
  castle?: 'K' | 'Q';    // kingside / queenside
  enPassant?: boolean;
}

export function moveToAlgebraic(m: Move, board: Piece[]): string {
  if (m.castle === 'K') return 'O-O';
  if (m.castle === 'Q') return 'O-O-O';
  const p = board[m.from];
  const names = ' PNBRQK';
  const pt = pieceType(p);
  const capture = board[m.to] !== EMPTY || m.enPassant;
  let s = pt === PAWN ? '' : names[pt];
  if (capture && pt === PAWN) s += sqName(m.from)[0];
  if (capture) s += 'x';
  s += sqName(m.to);
  if (m.promotion) s += '=' + names[m.promotion];
  return s;
}
