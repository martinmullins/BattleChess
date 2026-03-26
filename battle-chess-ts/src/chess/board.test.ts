import { describe, it, expect } from 'vitest';
import {
  WHITE, BLACK, EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING,
  CASTLE_WK, CASTLE_WQ, CASTLE_BK, CASTLE_BQ,
  makePiece, pieceType, pieceColor, sq,
} from './types.js';
import {
  startPosition, cloneBoard, applyMove, findKing, isAttacked, inCheck,
} from './board.js';

// ---------------------------------------------------------------------------
// startPosition
// ---------------------------------------------------------------------------

describe('startPosition', () => {
  it('places white pawns on rank 2', () => {
    const b = startPosition();
    for (let f = 0; f < 8; f++) {
      const p = b.squares[sq(f, 1)];
      expect(pieceType(p)).toBe(PAWN);
      expect(pieceColor(p)).toBe(WHITE);
    }
  });

  it('places black pawns on rank 7', () => {
    const b = startPosition();
    for (let f = 0; f < 8; f++) {
      const p = b.squares[sq(f, 6)];
      expect(pieceType(p)).toBe(PAWN);
      expect(pieceColor(p)).toBe(BLACK);
    }
  });

  it('has correct white back rank', () => {
    const b = startPosition();
    const expected = [ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK];
    for (let f = 0; f < 8; f++) {
      const p = b.squares[sq(f, 0)];
      expect(pieceType(p)).toBe(expected[f]);
      expect(pieceColor(p)).toBe(WHITE);
    }
  });

  it('has correct black back rank', () => {
    const b = startPosition();
    const expected = [ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK];
    for (let f = 0; f < 8; f++) {
      const p = b.squares[sq(f, 7)];
      expect(pieceType(p)).toBe(expected[f]);
      expect(pieceColor(p)).toBe(BLACK);
    }
  });

  it('has empty squares in the middle', () => {
    const b = startPosition();
    for (let f = 0; f < 8; f++) {
      for (const rank of [2, 3, 4, 5]) {
        expect(b.squares[sq(f, rank)]).toBe(EMPTY);
      }
    }
  });

  it('has all castling rights', () => {
    const b = startPosition();
    expect(b.castling & CASTLE_WK).toBeTruthy();
    expect(b.castling & CASTLE_WQ).toBeTruthy();
    expect(b.castling & CASTLE_BK).toBeTruthy();
    expect(b.castling & CASTLE_BQ).toBeTruthy();
  });

  it('starts at White to move, move 1, halfmove 0', () => {
    const b = startPosition();
    expect(b.turn).toBe(WHITE);
    expect(b.fullmove).toBe(1);
    expect(b.halfmove).toBe(0);
    expect(b.enPassant).toBe(-1);
  });

  it('has 32 pieces total', () => {
    const b = startPosition();
    const count = b.squares.filter(p => p !== EMPTY).length;
    expect(count).toBe(32);
  });
});

// ---------------------------------------------------------------------------
// cloneBoard
// ---------------------------------------------------------------------------

describe('cloneBoard', () => {
  it('produces an independent copy', () => {
    const b = startPosition();
    const clone = cloneBoard(b);
    clone.squares[sq(4, 1)] = EMPTY;
    expect(b.squares[sq(4, 1)]).not.toBe(EMPTY);
  });

  it('copies all fields', () => {
    const b = startPosition();
    const clone = cloneBoard(b);
    expect(clone.turn).toBe(b.turn);
    expect(clone.castling).toBe(b.castling);
    expect(clone.enPassant).toBe(b.enPassant);
    expect(clone.halfmove).toBe(b.halfmove);
    expect(clone.fullmove).toBe(b.fullmove);
  });
});

// ---------------------------------------------------------------------------
// applyMove
// ---------------------------------------------------------------------------

describe('applyMove — basic moves', () => {
  it('moves a pawn from e2 to e4', () => {
    const b = startPosition();
    const nb = applyMove(b, { from: sq(4, 1), to: sq(4, 3) });
    expect(nb.squares[sq(4, 1)]).toBe(EMPTY);
    expect(pieceType(nb.squares[sq(4, 3)])).toBe(PAWN);
    expect(pieceColor(nb.squares[sq(4, 3)])).toBe(WHITE);
  });

  it('switches turn after move', () => {
    const b = startPosition();
    const nb = applyMove(b, { from: sq(4, 1), to: sq(4, 3) });
    expect(nb.turn).toBe(BLACK);
  });

  it('increments fullmove after Black moves', () => {
    let b = startPosition();
    b = applyMove(b, { from: sq(4, 1), to: sq(4, 3) }); // White
    expect(b.fullmove).toBe(1);
    b = applyMove(b, { from: sq(4, 6), to: sq(4, 4) }); // Black
    expect(b.fullmove).toBe(2);
  });

  it('resets halfmove on pawn move', () => {
    const b = startPosition();
    const nb = applyMove(b, { from: sq(4, 1), to: sq(4, 3) });
    expect(nb.halfmove).toBe(0);
  });

  it('increments halfmove on non-pawn non-capture', () => {
    const b = startPosition();
    // Move knight first (non-pawn, non-capture)
    const nb = applyMove(b, { from: sq(6, 0), to: sq(5, 2) }); // Nf3
    expect(nb.halfmove).toBe(1);
  });
});

describe('applyMove — en passant', () => {
  it('sets en passant target after double pawn push', () => {
    const b = startPosition();
    const nb = applyMove(b, { from: sq(4, 1), to: sq(4, 3) });
    expect(nb.enPassant).toBe(sq(4, 2)); // e3
  });

  it('clears en passant after other moves', () => {
    let b = startPosition();
    b = applyMove(b, { from: sq(4, 1), to: sq(4, 3) }); // e2-e4, sets ep=e3
    b = applyMove(b, { from: sq(4, 6), to: sq(4, 5) }); // e7-e6, no ep
    expect(b.enPassant).toBe(-1);
  });

  it('removes captured pawn on en passant', () => {
    // White pawn e5, black pawn d5 just pushed from d7 → en passant target d6
    const b = startPosition();
    // Quick setup: place white pawn on e5, black pawn on d5, set ep=d6
    let board = startPosition();
    board.squares.fill(EMPTY);
    board.squares[sq(4, 4)] = makePiece(PAWN, WHITE); // e5
    board.squares[sq(3, 4)] = makePiece(PAWN, BLACK); // d5
    board.enPassant = sq(3, 5); // d6
    board.turn = WHITE;

    const nb = applyMove(board, { from: sq(4, 4), to: sq(3, 5), enPassant: true });
    expect(nb.squares[sq(3, 4)]).toBe(EMPTY);  // captured pawn gone
    expect(nb.squares[sq(3, 5)]).toBe(makePiece(PAWN, WHITE)); // white pawn on d6
  });
});

describe('applyMove — promotion', () => {
  it('promotes white pawn to queen on rank 8', () => {
    const b = startPosition();
    b.squares.fill(EMPTY);
    b.squares[sq(4, 6)] = makePiece(PAWN, WHITE);
    b.turn = WHITE;
    const nb = applyMove(b, { from: sq(4, 6), to: sq(4, 7), promotion: QUEEN });
    const promoted = nb.squares[sq(4, 7)];
    expect(pieceType(promoted)).toBe(QUEEN);
    expect(pieceColor(promoted)).toBe(WHITE);
  });

  it('promotes black pawn to rook on rank 1', () => {
    const b = startPosition();
    b.squares.fill(EMPTY);
    b.squares[sq(3, 1)] = makePiece(PAWN, BLACK);
    b.turn = BLACK;
    const nb = applyMove(b, { from: sq(3, 1), to: sq(3, 0), promotion: ROOK });
    const promoted = nb.squares[sq(3, 0)];
    expect(pieceType(promoted)).toBe(ROOK);
    expect(pieceColor(promoted)).toBe(BLACK);
  });
});

describe('applyMove — castling', () => {
  it('white kingside castling moves king and rook', () => {
    const b = startPosition();
    b.squares.fill(EMPTY);
    b.squares[sq(4, 0)] = makePiece(KING, WHITE);
    b.squares[sq(7, 0)] = makePiece(ROOK, WHITE);
    b.castling = CASTLE_WK;
    b.turn = WHITE;

    const nb = applyMove(b, { from: sq(4, 0), to: sq(6, 0), castle: 'K' });
    expect(pieceType(nb.squares[sq(6, 0)])).toBe(KING);
    expect(pieceType(nb.squares[sq(5, 0)])).toBe(ROOK);
    expect(nb.squares[sq(4, 0)]).toBe(EMPTY);
    expect(nb.squares[sq(7, 0)]).toBe(EMPTY);
  });

  it('white queenside castling moves king and rook', () => {
    const b = startPosition();
    b.squares.fill(EMPTY);
    b.squares[sq(4, 0)] = makePiece(KING, WHITE);
    b.squares[sq(0, 0)] = makePiece(ROOK, WHITE);
    b.castling = CASTLE_WQ;
    b.turn = WHITE;

    const nb = applyMove(b, { from: sq(4, 0), to: sq(2, 0), castle: 'Q' });
    expect(pieceType(nb.squares[sq(2, 0)])).toBe(KING);
    expect(pieceType(nb.squares[sq(3, 0)])).toBe(ROOK);
    expect(nb.squares[sq(4, 0)]).toBe(EMPTY);
    expect(nb.squares[sq(0, 0)]).toBe(EMPTY);
  });

  it('moving white king removes all white castling rights', () => {
    const b = startPosition();
    b.squares.fill(EMPTY);
    b.squares[sq(4, 0)] = makePiece(KING, WHITE);
    b.castling = CASTLE_WK | CASTLE_WQ | CASTLE_BK | CASTLE_BQ;
    b.turn = WHITE;

    const nb = applyMove(b, { from: sq(4, 0), to: sq(4, 1) });
    expect(nb.castling & CASTLE_WK).toBe(0);
    expect(nb.castling & CASTLE_WQ).toBe(0);
    expect(nb.castling & CASTLE_BK).toBeTruthy();
    expect(nb.castling & CASTLE_BQ).toBeTruthy();
  });

  it('moving a1 rook removes queenside castling right', () => {
    const b = startPosition();
    b.squares.fill(EMPTY);
    b.squares[sq(0, 0)] = makePiece(ROOK, WHITE);
    b.castling = CASTLE_WK | CASTLE_WQ;
    b.turn = WHITE;

    const nb = applyMove(b, { from: sq(0, 0), to: sq(0, 4) });
    expect(nb.castling & CASTLE_WQ).toBe(0);
    expect(nb.castling & CASTLE_WK).toBeTruthy();
  });

  it('capturing a1 rook removes queenside castling right', () => {
    const b = startPosition();
    b.squares.fill(EMPTY);
    b.squares[sq(0, 0)] = makePiece(ROOK, WHITE);
    b.squares[sq(1, 1)] = makePiece(BISHOP, BLACK); // attacker
    b.castling = CASTLE_WK | CASTLE_WQ;
    b.turn = BLACK;

    const nb = applyMove(b, { from: sq(1, 1), to: sq(0, 0) });
    expect(nb.castling & CASTLE_WQ).toBe(0);
  });
});

// ---------------------------------------------------------------------------
// findKing
// ---------------------------------------------------------------------------

describe('findKing', () => {
  it('finds white king in start position at e1', () => {
    const b = startPosition();
    expect(findKing(b, WHITE)).toBe(sq(4, 0));
  });

  it('finds black king in start position at e8', () => {
    const b = startPosition();
    expect(findKing(b, BLACK)).toBe(sq(4, 7));
  });

  it('returns -1 if king is missing', () => {
    const b = startPosition();
    b.squares.fill(EMPTY);
    expect(findKing(b, WHITE)).toBe(-1);
  });
});

// ---------------------------------------------------------------------------
// isAttacked / inCheck
// ---------------------------------------------------------------------------

describe('isAttacked', () => {
  function emptyBoard() {
    const b = startPosition();
    b.squares.fill(EMPTY);
    return b;
  }

  it('rook attacks along rank', () => {
    const b = emptyBoard();
    b.squares[sq(0, 4)] = makePiece(ROOK, WHITE);
    expect(isAttacked(b, sq(7, 4), WHITE)).toBe(true);
    expect(isAttacked(b, sq(7, 5), WHITE)).toBe(false);
  });

  it('rook is blocked by intervening piece', () => {
    const b = emptyBoard();
    b.squares[sq(0, 4)] = makePiece(ROOK, WHITE);
    b.squares[sq(3, 4)] = makePiece(PAWN, BLACK);
    expect(isAttacked(b, sq(7, 4), WHITE)).toBe(false);
  });

  it('bishop attacks diagonally', () => {
    const b = emptyBoard();
    b.squares[sq(0, 0)] = makePiece(BISHOP, WHITE);
    expect(isAttacked(b, sq(3, 3), WHITE)).toBe(true);
    expect(isAttacked(b, sq(4, 3), WHITE)).toBe(false);
  });

  it('knight attacks in L-shape', () => {
    const b = emptyBoard();
    b.squares[sq(4, 4)] = makePiece(KNIGHT, WHITE);
    // All 8 knight moves from e5
    expect(isAttacked(b, sq(3, 6), WHITE)).toBe(true); // d7
    expect(isAttacked(b, sq(5, 6), WHITE)).toBe(true); // f7
    expect(isAttacked(b, sq(6, 5), WHITE)).toBe(true); // g6
    expect(isAttacked(b, sq(6, 3), WHITE)).toBe(true); // g4
    expect(isAttacked(b, sq(5, 2), WHITE)).toBe(true); // f3
    expect(isAttacked(b, sq(3, 2), WHITE)).toBe(true); // d3
    expect(isAttacked(b, sq(2, 3), WHITE)).toBe(true); // c4
    expect(isAttacked(b, sq(2, 5), WHITE)).toBe(true); // c6
    // Not attacked
    expect(isAttacked(b, sq(4, 6), WHITE)).toBe(false);
  });

  it('pawn attacks diagonally forward', () => {
    const b = emptyBoard();
    b.squares[sq(4, 4)] = makePiece(PAWN, WHITE); // e5
    // White pawn attacks f6 and d6 (ranks above)
    expect(isAttacked(b, sq(5, 5), WHITE)).toBe(true);  // f6
    expect(isAttacked(b, sq(3, 5), WHITE)).toBe(true);  // d6
    // Not straight forward
    expect(isAttacked(b, sq(4, 5), WHITE)).toBe(false); // e6
  });

  it('black pawn attacks diagonally downward', () => {
    const b = emptyBoard();
    b.squares[sq(4, 4)] = makePiece(PAWN, BLACK); // e5
    expect(isAttacked(b, sq(5, 3), BLACK)).toBe(true);  // f4
    expect(isAttacked(b, sq(3, 3), BLACK)).toBe(true);  // d4
    expect(isAttacked(b, sq(4, 3), BLACK)).toBe(false); // e4
  });

  it('king attacks adjacent squares', () => {
    const b = emptyBoard();
    b.squares[sq(4, 4)] = makePiece(KING, WHITE); // e5
    for (const [df, dr] of [[-1,-1],[-1,0],[-1,1],[0,-1],[0,1],[1,-1],[1,0],[1,1]]) {
      expect(isAttacked(b, sq(4 + df, 4 + dr), WHITE)).toBe(true);
    }
    expect(isAttacked(b, sq(4, 6), WHITE)).toBe(false); // two squares away
  });

  it('queen attacks as rook+bishop', () => {
    const b = emptyBoard();
    b.squares[sq(3, 3)] = makePiece(QUEEN, WHITE); // d4
    expect(isAttacked(b, sq(3, 7), WHITE)).toBe(true);  // same file (rook)
    expect(isAttacked(b, sq(7, 3), WHITE)).toBe(true);  // same rank (rook)
    expect(isAttacked(b, sq(6, 6), WHITE)).toBe(true);  // diagonal (bishop)
    expect(isAttacked(b, sq(0, 6), WHITE)).toBe(true);  // anti-diagonal (bishop)
    expect(isAttacked(b, sq(5, 6), WHITE)).toBe(false); // not aligned
  });
});

describe('inCheck', () => {
  it('is not in check at start position', () => {
    const b = startPosition();
    expect(inCheck(b, WHITE)).toBe(false);
    expect(inCheck(b, BLACK)).toBe(false);
  });

  it('detects white king in check from black rook', () => {
    const b = startPosition();
    b.squares.fill(EMPTY);
    b.squares[sq(4, 0)] = makePiece(KING, WHITE);
    b.squares[sq(4, 7)] = makePiece(ROOK, BLACK);
    expect(inCheck(b, WHITE)).toBe(true);
  });

  it('detects white king in check from black pawn', () => {
    const b = startPosition();
    b.squares.fill(EMPTY);
    b.squares[sq(4, 3)] = makePiece(KING, WHITE);  // e4
    b.squares[sq(5, 4)] = makePiece(PAWN, BLACK);  // f5 (attacks e4? No: black pawn at f5 attacks e4 and g4)
    expect(inCheck(b, WHITE)).toBe(true);
  });

  it('is not in check when king is shielded', () => {
    const b = startPosition();
    b.squares.fill(EMPTY);
    b.squares[sq(4, 0)] = makePiece(KING, WHITE);
    b.squares[sq(4, 3)] = makePiece(ROOK, WHITE);  // friendly rook blocks
    b.squares[sq(4, 7)] = makePiece(ROOK, BLACK);
    expect(inCheck(b, WHITE)).toBe(false);
  });
});
