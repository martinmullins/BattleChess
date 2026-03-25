import { describe, it, expect } from 'vitest';
import {
  WHITE, BLACK, EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING,
  CASTLE_WK, CASTLE_WQ, CASTLE_BK, CASTLE_BQ,
  makePiece, pieceType, pieceColor,
  sq, sqFile, sqRank, sqValid, sqName,
  moveToAlgebraic,
} from './types.js';

// ---------------------------------------------------------------------------
// Piece encoding
// ---------------------------------------------------------------------------

describe('makePiece / pieceType / pieceColor', () => {
  it('encodes a white pawn', () => {
    const p = makePiece(PAWN, WHITE);
    expect(pieceType(p)).toBe(PAWN);
    expect(pieceColor(p)).toBe(WHITE);
  });

  it('encodes a black pawn', () => {
    const p = makePiece(PAWN, BLACK);
    expect(pieceType(p)).toBe(PAWN);
    expect(pieceColor(p)).toBe(BLACK);
  });

  it('encodes all piece types for both colors', () => {
    for (const type of [PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING]) {
      for (const color of [WHITE, BLACK]) {
        const p = makePiece(type, color);
        expect(pieceType(p)).toBe(type);
        expect(pieceColor(p)).toBe(color);
      }
    }
  });

  it('EMPTY (0) has pieceType 0', () => {
    expect(pieceType(EMPTY)).toBe(EMPTY);
  });

  it('white king has value 12, black king has value 13', () => {
    expect(makePiece(KING, WHITE)).toBe(12);
    expect(makePiece(KING, BLACK)).toBe(13);
  });
});

// ---------------------------------------------------------------------------
// Square utilities
// ---------------------------------------------------------------------------

describe('sq / sqFile / sqRank', () => {
  it('a1 is square 0', () => {
    expect(sq(0, 0)).toBe(0);
    expect(sqFile(0)).toBe(0);
    expect(sqRank(0)).toBe(0);
  });

  it('h1 is square 7', () => {
    expect(sq(7, 0)).toBe(7);
    expect(sqFile(7)).toBe(7);
    expect(sqRank(7)).toBe(0);
  });

  it('a8 is square 56', () => {
    expect(sq(0, 7)).toBe(56);
    expect(sqFile(56)).toBe(0);
    expect(sqRank(56)).toBe(7);
  });

  it('h8 is square 63', () => {
    expect(sq(7, 7)).toBe(63);
    expect(sqFile(63)).toBe(7);
    expect(sqRank(63)).toBe(7);
  });

  it('e4 is sq(4,3) = 28', () => {
    expect(sq(4, 3)).toBe(28);
    expect(sqFile(28)).toBe(4);
    expect(sqRank(28)).toBe(3);
  });

  it('round-trips all 64 squares', () => {
    for (let f = 0; f < 8; f++) {
      for (let r = 0; r < 8; r++) {
        const s = sq(f, r);
        expect(sqFile(s)).toBe(f);
        expect(sqRank(s)).toBe(r);
      }
    }
  });
});

describe('sqValid', () => {
  it('accepts all squares 0-63', () => {
    for (let s = 0; s < 64; s++) expect(sqValid(s)).toBe(true);
  });

  it('rejects -1 and 64', () => {
    expect(sqValid(-1)).toBe(false);
    expect(sqValid(64)).toBe(false);
  });
});

describe('sqName', () => {
  it('names corner squares correctly', () => {
    expect(sqName(sq(0, 0))).toBe('a1');
    expect(sqName(sq(7, 0))).toBe('h1');
    expect(sqName(sq(0, 7))).toBe('a8');
    expect(sqName(sq(7, 7))).toBe('h8');
  });

  it('names e4 correctly', () => {
    expect(sqName(sq(4, 3))).toBe('e4');
  });

  it('names d5 correctly', () => {
    expect(sqName(sq(3, 4))).toBe('d5');
  });
});

// ---------------------------------------------------------------------------
// Castling constants
// ---------------------------------------------------------------------------

describe('castling constants', () => {
  it('are distinct bitmask bits', () => {
    expect(CASTLE_WK & CASTLE_WQ).toBe(0);
    expect(CASTLE_WK & CASTLE_BK).toBe(0);
    expect(CASTLE_WK & CASTLE_BQ).toBe(0);
    expect(CASTLE_WQ & CASTLE_BK).toBe(0);
    expect(CASTLE_WQ & CASTLE_BQ).toBe(0);
    expect(CASTLE_BK & CASTLE_BQ).toBe(0);
  });

  it('all four rights OR together to 15', () => {
    expect(CASTLE_WK | CASTLE_WQ | CASTLE_BK | CASTLE_BQ).toBe(15);
  });
});

// ---------------------------------------------------------------------------
// moveToAlgebraic
// ---------------------------------------------------------------------------

describe('moveToAlgebraic', () => {
  const emptyBoard = new Array(64).fill(EMPTY);

  it('kingside castling', () => {
    expect(moveToAlgebraic({ from: sq(4, 0), to: sq(6, 0), castle: 'K' }, emptyBoard)).toBe('O-O');
  });

  it('queenside castling', () => {
    expect(moveToAlgebraic({ from: sq(4, 0), to: sq(2, 0), castle: 'Q' }, emptyBoard)).toBe('O-O-O');
  });

  it('pawn move e2-e4', () => {
    const board = emptyBoard.slice();
    board[sq(4, 1)] = makePiece(PAWN, WHITE);
    expect(moveToAlgebraic({ from: sq(4, 1), to: sq(4, 3) }, board)).toBe('e4');
  });

  it('knight move Nf3', () => {
    const board = emptyBoard.slice();
    board[sq(6, 0)] = makePiece(KNIGHT, WHITE);
    expect(moveToAlgebraic({ from: sq(6, 0), to: sq(5, 2) }, board)).toBe('Nf3');
  });

  it('pawn capture exd5', () => {
    const board = emptyBoard.slice();
    board[sq(4, 4)] = makePiece(PAWN, WHITE);
    board[sq(3, 4)] = makePiece(PAWN, BLACK); // black pawn on d5
    expect(moveToAlgebraic({ from: sq(4, 4), to: sq(3, 4) }, board)).toBe('exd5');
  });

  it('piece capture Bxf7', () => {
    const board = emptyBoard.slice();
    board[sq(2, 3)] = makePiece(BISHOP, WHITE);
    board[sq(5, 6)] = makePiece(PAWN, BLACK);
    expect(moveToAlgebraic({ from: sq(2, 3), to: sq(5, 6) }, board)).toBe('Bxf7');
  });

  it('pawn promotion e8=Q', () => {
    const board = emptyBoard.slice();
    board[sq(4, 6)] = makePiece(PAWN, WHITE);
    expect(moveToAlgebraic({ from: sq(4, 6), to: sq(4, 7), promotion: QUEEN }, board)).toBe('e8=Q');
  });

  it('en passant capture is marked as capture', () => {
    const board = emptyBoard.slice();
    board[sq(4, 4)] = makePiece(PAWN, WHITE);
    expect(moveToAlgebraic({ from: sq(4, 4), to: sq(3, 5), enPassant: true }, board)).toBe('exd6');
  });
});
