import { describe, it, expect } from 'vitest';
import {
  WHITE, BLACK, EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING,
  makePiece, sq,
} from './types.js';
import { startPosition, applyMove } from './board.js';
import { findBestMove } from './ai.js';
import { isCheckmate } from './moves.js';
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
// findBestMove — basic sanity checks
// ---------------------------------------------------------------------------

describe('findBestMove', () => {
  it('returns null when no legal moves exist', () => {
    // Stalemate position
    const b = bare();
    b.squares[sq(0, 7)] = makePiece(KING, WHITE);
    b.squares[sq(1, 5)] = makePiece(QUEEN, BLACK);
    b.squares[sq(7, 0)] = makePiece(KING, BLACK);
    b.turn = WHITE;
    expect(findBestMove(b, 1)).toBeNull();
  });

  it('returns a move at start position', () => {
    const move = findBestMove(startPosition(), 1);
    expect(move).not.toBeNull();
    expect(move!.from).toBeGreaterThanOrEqual(0);
    expect(move!.to).toBeGreaterThanOrEqual(0);
  });

  it('takes a free queen (depth 1)', () => {
    // White rook on a1, black queen on a8 (undefended)
    const b = bare();
    b.squares[sq(0, 0)] = makePiece(KING, WHITE);
    b.squares[sq(7, 0)] = makePiece(ROOK, WHITE);
    b.squares[sq(7, 7)] = makePiece(QUEEN, BLACK); // undefended
    b.squares[sq(0, 7)] = makePiece(KING, BLACK);
    b.turn = WHITE;
    const move = findBestMove(b, 1);
    expect(move).not.toBeNull();
    expect(move!.to).toBe(sq(7, 7)); // captures the queen
  });

  it('avoids taking a defended piece (depth 2)', () => {
    // White rook on h1, black pawn on h7 defended by black rook on h8
    const b = bare();
    b.squares[sq(0, 0)] = makePiece(KING, WHITE);
    b.squares[sq(7, 0)] = makePiece(ROOK, WHITE);  // h1
    b.squares[sq(7, 6)] = makePiece(PAWN, BLACK);   // h7 (defended by rook below)
    b.squares[sq(7, 7)] = makePiece(ROOK, BLACK);   // h8 defends h7
    b.squares[sq(0, 7)] = makePiece(KING, BLACK);
    b.turn = WHITE;
    // At depth 2 the AI should see that Rxh7 Rxh7 loses the rook for a pawn
    const move = findBestMove(b, 2);
    expect(move).not.toBeNull();
    expect(move!.to).not.toBe(sq(7, 6)); // should NOT take defended pawn
  });

  it('delivers checkmate in 1', () => {
    // White king on g6 defends h7; white queen on d7 can deliver Qh7#
    // Black king on h8 has no escape: g8/g7 attacked by queen on h7, h7 occupied+defended
    const b = bare();
    b.squares[sq(6, 5)] = makePiece(KING, WHITE);   // g6 — defends h7 diagonally
    b.squares[sq(3, 6)] = makePiece(QUEEN, WHITE);  // d7
    b.squares[sq(7, 7)] = makePiece(KING, BLACK);   // h8 — trapped
    b.turn = WHITE;
    // depth=2 required: engine must look one ply ahead to see black has no legal moves
    const move = findBestMove(b, 2);
    expect(move).not.toBeNull();
    // Verify the chosen move is actually checkmate (Qh7# or Qc8# both work)
    const after = applyMove(b, move!);
    expect(isCheckmate(after)).toBe(true);
  });

  it('move from start position is a valid pawn or knight move', () => {
    const b = startPosition();
    const move = findBestMove(b, 2);
    expect(move).not.toBeNull();
    // At depth 2 from start, AI should play a reasonable first move
    // First moves are always pawn pushes or knight developments
    const validFirstSquares = [
      sq(0, 2), sq(1, 2), sq(2, 2), sq(3, 2), sq(4, 2), sq(5, 2), sq(6, 2), sq(7, 2), // pawn single push
      sq(0, 3), sq(1, 3), sq(2, 3), sq(3, 3), sq(4, 3), sq(5, 3), sq(6, 3), sq(7, 3), // pawn double push
      sq(2, 2), sq(5, 2), // knight moves (Nc3, Nf3)
    ];
    expect(validFirstSquares).toContain(move!.to);
  });
});

// ---------------------------------------------------------------------------
// AI plays the game — integration
// ---------------------------------------------------------------------------

describe('AI plays a full minimax game (depth 2)', () => {
  it('can play 10 moves without crashing', () => {
    let b = startPosition();
    for (let i = 0; i < 10; i++) {
      const move = findBestMove(b, 2);
      if (!move) break; // game over
      b = applyMove(b, move);
    }
    // Should reach at least move 5 without errors
    expect(b.fullmove).toBeGreaterThanOrEqual(5);
  });
});

// ---------------------------------------------------------------------------
// Position evaluation via move selection
// ---------------------------------------------------------------------------

describe('AI prefers material advantage', () => {
  it('captures an undefended piece when one is available', () => {
    // Black queen on b5 can slide down to capture the undefended white rook on b1
    const b = bare();
    b.squares[sq(0, 7)] = makePiece(KING, BLACK);   // a8
    b.squares[sq(1, 4)] = makePiece(QUEEN, BLACK);  // b5 — same file as rook
    b.squares[sq(1, 0)] = makePiece(ROOK, WHITE);   // b1 — undefended
    b.squares[sq(7, 0)] = makePiece(KING, WHITE);   // h1 — far from b1
    b.turn = BLACK;
    const move = findBestMove(b, 1);
    expect(move).not.toBeNull();
    // Queen should capture rook on b1
    expect(move!.to).toBe(sq(1, 0));
  });
});
