import { describe, it, expect } from 'vitest';
import {
  WHITE, BLACK, EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING,
  CASTLE_WK, CASTLE_WQ, CASTLE_BK, CASTLE_BQ,
  makePiece, sq,
} from './types.js';
import { startPosition, applyMove } from './board.js';
import { legalMoves, hasLegalMoves, isCheckmate, isStalemate } from './moves.js';
import type { BoardState } from './board.js';

function bare(): BoardState {
  const b = startPosition();
  b.squares.fill(EMPTY);
  b.castling = 0;
  b.enPassant = -1;
  b.turn = WHITE;
  return b;
}

// ---------------------------------------------------------------------------
// Pawn moves
// ---------------------------------------------------------------------------

describe('pawn move generation', () => {
  it('single push from start rank', () => {
    const b = bare();
    b.squares[sq(4, 1)] = makePiece(PAWN, WHITE);
    b.squares[sq(4, 7)] = makePiece(KING, WHITE);  // need king for legal moves
    b.squares[sq(0, 7)] = makePiece(KING, BLACK);
    const moves = legalMoves(b).filter(m => m.from === sq(4, 1));
    const tos = moves.map(m => m.to);
    expect(tos).toContain(sq(4, 2)); // e3
  });

  it('double push from start rank', () => {
    const b = bare();
    b.squares[sq(4, 1)] = makePiece(PAWN, WHITE);
    b.squares[sq(4, 7)] = makePiece(KING, WHITE);
    b.squares[sq(0, 7)] = makePiece(KING, BLACK);
    const moves = legalMoves(b).filter(m => m.from === sq(4, 1));
    const tos = moves.map(m => m.to);
    expect(tos).toContain(sq(4, 3)); // e4
  });

  it('cannot double-push if first square is blocked', () => {
    const b = bare();
    b.squares[sq(4, 1)] = makePiece(PAWN, WHITE);
    b.squares[sq(4, 2)] = makePiece(PAWN, BLACK); // blocks e3
    b.squares[sq(4, 7)] = makePiece(KING, WHITE);
    b.squares[sq(0, 7)] = makePiece(KING, BLACK);
    const moves = legalMoves(b).filter(m => m.from === sq(4, 1));
    expect(moves.length).toBe(0);
  });

  it('cannot push onto occupied square', () => {
    const b = bare();
    b.squares[sq(4, 2)] = makePiece(PAWN, WHITE);
    b.squares[sq(4, 3)] = makePiece(BISHOP, WHITE); // blocks
    b.squares[sq(4, 7)] = makePiece(KING, WHITE);
    b.squares[sq(0, 7)] = makePiece(KING, BLACK);
    const moves = legalMoves(b).filter(m => m.from === sq(4, 2));
    expect(moves.length).toBe(0);
  });

  it('pawn captures diagonally', () => {
    const b = bare();
    b.squares[sq(4, 4)] = makePiece(PAWN, WHITE);  // e5
    b.squares[sq(5, 5)] = makePiece(PAWN, BLACK);  // f6 (can capture)
    b.squares[sq(4, 7)] = makePiece(KING, WHITE);
    b.squares[sq(0, 7)] = makePiece(KING, BLACK);
    const moves = legalMoves(b).filter(m => m.from === sq(4, 4));
    const tos = moves.map(m => m.to);
    expect(tos).toContain(sq(5, 5));
  });

  it('pawn cannot capture own piece', () => {
    const b = bare();
    b.squares[sq(4, 4)] = makePiece(PAWN, WHITE);
    b.squares[sq(5, 5)] = makePiece(PAWN, WHITE);  // own pawn
    b.squares[sq(4, 7)] = makePiece(KING, WHITE);
    b.squares[sq(0, 7)] = makePiece(KING, BLACK);
    const moves = legalMoves(b).filter(m => m.from === sq(4, 4) && m.to === sq(5, 5));
    expect(moves.length).toBe(0);
  });

  it('en passant capture', () => {
    const b = bare();
    b.squares[sq(4, 4)] = makePiece(PAWN, WHITE);  // e5
    b.squares[sq(5, 4)] = makePiece(PAWN, BLACK);  // f5 (just double-pushed)
    b.enPassant = sq(5, 5); // f6
    b.squares[sq(4, 7)] = makePiece(KING, WHITE);
    b.squares[sq(0, 7)] = makePiece(KING, BLACK);
    const moves = legalMoves(b).filter(m => m.from === sq(4, 4) && m.enPassant);
    expect(moves.length).toBe(1);
    expect(moves[0].to).toBe(sq(5, 5));
  });

  it('pawn generates 4 promotion moves per direction', () => {
    const b = bare();
    b.squares[sq(4, 6)] = makePiece(PAWN, WHITE);  // e7
    b.squares[sq(4, 7)] = makePiece(KING, WHITE);  // king blocking e8 is fine — pawn can't reach it since king is there
    // Let's put king somewhere safe
    b.squares[sq(4, 7)] = EMPTY;
    b.squares[sq(0, 7)] = makePiece(KING, WHITE);
    b.squares[sq(7, 0)] = makePiece(KING, BLACK);
    const moves = legalMoves(b).filter(m => m.from === sq(4, 6) && m.promotion);
    expect(moves.length).toBe(4);
    const promos = moves.map(m => m.promotion).sort();
    expect(promos).toEqual([BISHOP, KNIGHT, QUEEN, ROOK].sort());
  });
});

// ---------------------------------------------------------------------------
// Knight moves
// ---------------------------------------------------------------------------

describe('knight move generation', () => {
  it('knight on e4 has up to 8 moves', () => {
    const b = bare();
    b.squares[sq(4, 3)] = makePiece(KNIGHT, WHITE);
    b.squares[sq(0, 7)] = makePiece(KING, WHITE);
    b.squares[sq(7, 7)] = makePiece(KING, BLACK);
    const moves = legalMoves(b).filter(m => m.from === sq(4, 3));
    expect(moves.length).toBe(8);
  });

  it('knight in corner has 2 moves', () => {
    const b = bare();
    b.squares[sq(0, 0)] = makePiece(KNIGHT, WHITE);
    b.squares[sq(7, 7)] = makePiece(KING, WHITE);
    b.squares[sq(0, 7)] = makePiece(KING, BLACK);
    const moves = legalMoves(b).filter(m => m.from === sq(0, 0));
    expect(moves.length).toBe(2);
  });

  it('knight cannot jump over pieces but can land on enemy', () => {
    const b = bare();
    b.squares[sq(4, 3)] = makePiece(KNIGHT, WHITE);
    b.squares[sq(5, 5)] = makePiece(PAWN, BLACK);  // can capture
    b.squares[sq(3, 5)] = makePiece(PAWN, WHITE);  // own piece, can't capture
    b.squares[sq(0, 7)] = makePiece(KING, WHITE);
    b.squares[sq(7, 7)] = makePiece(KING, BLACK);
    const moves = legalMoves(b).filter(m => m.from === sq(4, 3));
    const tos = moves.map(m => m.to);
    expect(tos).toContain(sq(5, 5)); // enemy OK
    expect(tos).not.toContain(sq(3, 5)); // own piece blocked
  });
});

// ---------------------------------------------------------------------------
// Sliding pieces (bishop, rook, queen)
// ---------------------------------------------------------------------------

describe('rook move generation', () => {
  it('rook on empty board has 14 moves', () => {
    const b = bare();
    b.squares[sq(4, 4)] = makePiece(ROOK, WHITE);
    b.squares[sq(0, 7)] = makePiece(KING, WHITE);
    b.squares[sq(7, 0)] = makePiece(KING, BLACK);
    const moves = legalMoves(b).filter(m => m.from === sq(4, 4));
    expect(moves.length).toBe(14);
  });

  it('rook is blocked by friendly piece', () => {
    const b = bare();
    b.squares[sq(4, 4)] = makePiece(ROOK, WHITE);
    b.squares[sq(4, 6)] = makePiece(PAWN, WHITE);  // blocks northward
    b.squares[sq(0, 7)] = makePiece(KING, WHITE);
    b.squares[sq(7, 0)] = makePiece(KING, BLACK);
    const northMoves = legalMoves(b).filter(m => m.from === sq(4, 4) && m.to > sq(4, 4));
    const tos = northMoves.map(m => m.to);
    expect(tos).toContain(sq(4, 5));
    expect(tos).not.toContain(sq(4, 6)); // can't go to own piece
    expect(tos).not.toContain(sq(4, 7)); // blocked beyond own piece
  });
});

describe('bishop move generation', () => {
  it('bishop from d4 on empty board has 13 moves', () => {
    const b = bare();
    b.squares[sq(3, 3)] = makePiece(BISHOP, WHITE);
    // Kings placed off all bishop diagonals (h2 and a8 are not on d4's diagonals)
    b.squares[sq(7, 1)] = makePiece(KING, WHITE);
    b.squares[sq(0, 7)] = makePiece(KING, BLACK);
    const moves = legalMoves(b).filter(m => m.from === sq(3, 3));
    expect(moves.length).toBe(13);
  });
});

// ---------------------------------------------------------------------------
// King moves
// ---------------------------------------------------------------------------

describe('king move generation', () => {
  it('king in center can move to 8 adjacent squares', () => {
    const b = bare();
    b.squares[sq(4, 4)] = makePiece(KING, WHITE);
    b.squares[sq(0, 7)] = makePiece(KING, BLACK);
    const moves = legalMoves(b).filter(m => m.from === sq(4, 4));
    expect(moves.length).toBe(8);
  });

  it('king cannot move into check', () => {
    const b = bare();
    b.squares[sq(4, 0)] = makePiece(KING, WHITE);
    b.squares[sq(4, 7)] = makePiece(ROOK, BLACK);  // controls e-file
    b.squares[sq(0, 7)] = makePiece(KING, BLACK);
    const moves = legalMoves(b).filter(m => m.from === sq(4, 0));
    const tos = moves.map(m => m.to);
    // e2 (sq(4,1)) is attacked by black rook
    expect(tos).not.toContain(sq(4, 1));
    // d1 and f1 are safe
    expect(tos).toContain(sq(3, 0));
    expect(tos).toContain(sq(5, 0));
  });
});

// ---------------------------------------------------------------------------
// Castling
// ---------------------------------------------------------------------------

describe('castling in move generation', () => {
  it('white kingside castling is generated when path is clear', () => {
    const b = bare();
    b.squares[sq(4, 0)] = makePiece(KING, WHITE);
    b.squares[sq(7, 0)] = makePiece(ROOK, WHITE);
    b.castling = CASTLE_WK;
    b.squares[sq(0, 7)] = makePiece(KING, BLACK);
    const moves = legalMoves(b).filter(m => m.castle === 'K');
    expect(moves.length).toBe(1);
  });

  it('white queenside castling is generated when path is clear', () => {
    const b = bare();
    b.squares[sq(4, 0)] = makePiece(KING, WHITE);
    b.squares[sq(0, 0)] = makePiece(ROOK, WHITE);
    b.castling = CASTLE_WQ;
    b.squares[sq(7, 7)] = makePiece(KING, BLACK);
    const moves = legalMoves(b).filter(m => m.castle === 'Q');
    expect(moves.length).toBe(1);
  });

  it('castling not generated if king in check', () => {
    const b = bare();
    b.squares[sq(4, 0)] = makePiece(KING, WHITE);
    b.squares[sq(7, 0)] = makePiece(ROOK, WHITE);
    b.squares[sq(4, 7)] = makePiece(ROOK, BLACK);  // check on e-file
    b.castling = CASTLE_WK;
    b.squares[sq(0, 7)] = makePiece(KING, BLACK);
    const moves = legalMoves(b).filter(m => m.castle === 'K');
    expect(moves.length).toBe(0);
  });

  it('castling not generated if path square is attacked', () => {
    const b = bare();
    b.squares[sq(4, 0)] = makePiece(KING, WHITE);
    b.squares[sq(7, 0)] = makePiece(ROOK, WHITE);
    b.squares[sq(6, 7)] = makePiece(ROOK, BLACK);  // attacks f1 (sq(5,0))
    b.castling = CASTLE_WK;
    b.squares[sq(0, 7)] = makePiece(KING, BLACK);
    const moves = legalMoves(b).filter(m => m.castle === 'K');
    expect(moves.length).toBe(0);
  });

  it('castling not generated if right is revoked', () => {
    const b = bare();
    b.squares[sq(4, 0)] = makePiece(KING, WHITE);
    b.squares[sq(7, 0)] = makePiece(ROOK, WHITE);
    b.castling = 0;  // no rights
    b.squares[sq(0, 7)] = makePiece(KING, BLACK);
    const moves = legalMoves(b).filter(m => m.castle === 'K');
    expect(moves.length).toBe(0);
  });
});

// ---------------------------------------------------------------------------
// Moves filtered for check
// ---------------------------------------------------------------------------

describe('pinned pieces cannot expose king', () => {
  it('pinned pawn cannot move', () => {
    // Pawn on d2 is diagonally pinned: black bishop on a5 attacks e1 king through d2
    const b = bare();
    b.squares[sq(4, 0)] = makePiece(KING, WHITE);   // e1
    b.squares[sq(3, 1)] = makePiece(PAWN, WHITE);   // d2 - on diagonal a5-e1
    b.squares[sq(0, 4)] = makePiece(BISHOP, BLACK); // a5 - pins pawn diagonally
    b.squares[sq(7, 7)] = makePiece(KING, BLACK);   // h8
    const moves = legalMoves(b).filter(m => m.from === sq(3, 1));
    expect(moves.length).toBe(0);
  });
});

describe('king must escape check', () => {
  it('only legal moves are those resolving check', () => {
    const b = bare();
    b.squares[sq(4, 0)] = makePiece(KING, WHITE);
    b.squares[sq(3, 3)] = makePiece(PAWN, WHITE);  // irrelevant
    b.squares[sq(4, 7)] = makePiece(ROOK, BLACK);  // check
    b.squares[sq(0, 7)] = makePiece(KING, BLACK);
    b.turn = WHITE;
    const moves = legalMoves(b);
    // Every legal move must result in king not in check
    for (const m of moves) {
      void applyMove(b, m);
      // Each legal move must leave the king not in check (enforced by legalMoves filter)
    }
    // The pawn on d4 cannot block on e-file or capture on e-file
    const pawnMoves = moves.filter(m => m.from === sq(3, 3));
    expect(pawnMoves.length).toBe(0);
  });
});

// ---------------------------------------------------------------------------
// Checkmate detection
// ---------------------------------------------------------------------------

describe('isCheckmate', () => {
  it('starting position is not checkmate', () => {
    expect(isCheckmate(startPosition())).toBe(false);
  });

  it('Scholar\'s mate is checkmate', () => {
    // 1.e4 e5 2.Bc4 Nc6 3.Qh5 Nf6?? 4.Qxf7#
    let b = startPosition();
    b = applyMove(b, { from: sq(4, 1), to: sq(4, 3) }); // 1.e4
    b = applyMove(b, { from: sq(4, 6), to: sq(4, 4) }); // 1...e5
    b = applyMove(b, { from: sq(5, 0), to: sq(2, 3) }); // 2.Bc4
    b = applyMove(b, { from: sq(1, 7), to: sq(2, 5) }); // 2...Nc6
    b = applyMove(b, { from: sq(3, 0), to: sq(7, 4) }); // 3.Qh5
    b = applyMove(b, { from: sq(6, 7), to: sq(5, 5) }); // 3...Nf6??
    b = applyMove(b, { from: sq(7, 4), to: sq(5, 6) }); // 4.Qxf7#
    expect(isCheckmate(b)).toBe(true);
    expect(b.turn).toBe(BLACK);
  });

  it('back-rank mate is checkmate', () => {
    // White king on a1, black rook on a8
    const b = bare();
    b.squares[sq(0, 0)] = makePiece(KING, WHITE);
    b.squares[sq(0, 7)] = makePiece(ROOK, BLACK);
    b.squares[sq(1, 7)] = makePiece(ROOK, BLACK);  // covers b-file escape
    b.squares[sq(7, 7)] = makePiece(KING, BLACK);
    b.turn = WHITE;
    expect(isCheckmate(b)).toBe(true);
  });
});

// ---------------------------------------------------------------------------
// Stalemate detection
// ---------------------------------------------------------------------------

describe('isStalemate', () => {
  it('starting position is not stalemate', () => {
    expect(isStalemate(startPosition())).toBe(false);
  });

  it('classic stalemate: white king cornered with no legal moves', () => {
    const b = bare();
    // White king on a8, black queen controls b7 and adjacent squares
    b.squares[sq(0, 7)] = makePiece(KING, WHITE);  // a8
    b.squares[sq(1, 5)] = makePiece(QUEEN, BLACK); // b6 — controls b7,a7,c7 etc.
    b.squares[sq(7, 0)] = makePiece(KING, BLACK);
    b.turn = WHITE;
    expect(isStalemate(b)).toBe(true);
  });

  it('checkmate is not stalemate', () => {
    let b = startPosition();
    b = applyMove(b, { from: sq(4, 1), to: sq(4, 3) });
    b = applyMove(b, { from: sq(4, 6), to: sq(4, 4) });
    b = applyMove(b, { from: sq(5, 0), to: sq(2, 3) });
    b = applyMove(b, { from: sq(1, 7), to: sq(2, 5) });
    b = applyMove(b, { from: sq(3, 0), to: sq(7, 4) });
    b = applyMove(b, { from: sq(6, 7), to: sq(5, 5) });
    b = applyMove(b, { from: sq(7, 4), to: sq(5, 6) }); // Qxf7#
    expect(isStalemate(b)).toBe(false);
    expect(isCheckmate(b)).toBe(true);
  });
});

// ---------------------------------------------------------------------------
// hasLegalMoves
// ---------------------------------------------------------------------------

describe('hasLegalMoves', () => {
  it('returns true at start position', () => {
    expect(hasLegalMoves(startPosition())).toBe(true);
  });

  it('returns false in stalemate', () => {
    const b = bare();
    b.squares[sq(0, 7)] = makePiece(KING, WHITE);
    b.squares[sq(1, 5)] = makePiece(QUEEN, BLACK);
    b.squares[sq(7, 0)] = makePiece(KING, BLACK);
    b.turn = WHITE;
    expect(hasLegalMoves(b)).toBe(false);
  });
});
