import { Move, Color, WHITE, EMPTY, pieceType, pieceColor, sqFile, sqRank } from './types.js';
import { BoardState, applyMove } from './board.js';
import { legalMoves, isCheckmate } from './moves.js';

/** Material values (centipawns) */
const PIECE_VALUE = [0, 100, 320, 330, 500, 900, 20000];

/** Piece-square tables (from White's perspective; flip rank for Black).
 *  Encourages development and positional play. */
const PST_PAWN = [
   0,  0,  0,  0,  0,  0,  0,  0,
  50, 50, 50, 50, 50, 50, 50, 50,
  10, 10, 20, 30, 30, 20, 10, 10,
   5,  5, 10, 25, 25, 10,  5,  5,
   0,  0,  0, 20, 20,  0,  0,  0,
   5, -5,-10,  0,  0,-10, -5,  5,
   5, 10, 10,-20,-20, 10, 10,  5,
   0,  0,  0,  0,  0,  0,  0,  0,
];
const PST_KNIGHT = [
  -50,-40,-30,-30,-30,-30,-40,-50,
  -40,-20,  0,  0,  0,  0,-20,-40,
  -30,  0, 10, 15, 15, 10,  0,-30,
  -30,  5, 15, 20, 20, 15,  5,-30,
  -30,  0, 15, 20, 20, 15,  0,-30,
  -30,  5, 10, 15, 15, 10,  5,-30,
  -40,-20,  0,  5,  5,  0,-20,-40,
  -50,-40,-30,-30,-30,-30,-40,-50,
];
const PST_BISHOP = [
  -20,-10,-10,-10,-10,-10,-10,-20,
  -10,  0,  0,  0,  0,  0,  0,-10,
  -10,  0,  5, 10, 10,  5,  0,-10,
  -10,  5,  5, 10, 10,  5,  5,-10,
  -10,  0, 10, 10, 10, 10,  0,-10,
  -10, 10, 10, 10, 10, 10, 10,-10,
  -10,  5,  0,  0,  0,  0,  5,-10,
  -20,-10,-10,-10,-10,-10,-10,-20,
];
const PST_ROOK = [
   0,  0,  0,  0,  0,  0,  0,  0,
   5, 10, 10, 10, 10, 10, 10,  5,
  -5,  0,  0,  0,  0,  0,  0, -5,
  -5,  0,  0,  0,  0,  0,  0, -5,
  -5,  0,  0,  0,  0,  0,  0, -5,
  -5,  0,  0,  0,  0,  0,  0, -5,
  -5,  0,  0,  0,  0,  0,  0, -5,
   0,  0,  0,  5,  5,  0,  0,  0,
];
const PST_QUEEN = [
  -20,-10,-10, -5, -5,-10,-10,-20,
  -10,  0,  0,  0,  0,  0,  0,-10,
  -10,  0,  5,  5,  5,  5,  0,-10,
   -5,  0,  5,  5,  5,  5,  0, -5,
    0,  0,  5,  5,  5,  5,  0, -5,
  -10,  5,  5,  5,  5,  5,  0,-10,
  -10,  0,  5,  0,  0,  0,  0,-10,
  -20,-10,-10, -5, -5,-10,-10,-20,
];
const PST_KING_MG = [
  -30,-40,-40,-50,-50,-40,-40,-30,
  -30,-40,-40,-50,-50,-40,-40,-30,
  -30,-40,-40,-50,-50,-40,-40,-30,
  -30,-40,-40,-50,-50,-40,-40,-30,
  -20,-30,-30,-40,-40,-30,-30,-20,
  -10,-20,-20,-20,-20,-20,-20,-10,
   20, 20,  0,  0,  0,  0, 20, 20,
   20, 30, 10,  0,  0, 10, 30, 20,
];

const PST: Record<number, number[]> = {
  1: PST_PAWN, 2: PST_KNIGHT, 3: PST_BISHOP,
  4: PST_ROOK, 5: PST_QUEEN,  6: PST_KING_MG,
};

function pstScore(pt: number, file: number, rank: number, color: Color): number {
  const table = PST[pt];
  if (!table) return 0;
  // White: rank 0 is bottom; Black: flip rank
  const idx = color === WHITE ? (7 - rank) * 8 + file : rank * 8 + file;
  return table[idx] ?? 0;
}

/** Static evaluation from White's perspective (positive = White better). */
function evaluate(b: BoardState): number {
  let score = 0;
  for (let s = 0; s < 64; s++) {
    const p = b.squares[s];
    if (p === EMPTY) continue;
    const pt   = pieceType(p);
    const col  = pieceColor(p);
    const file = sqFile(s);
    const rank = sqRank(s);
    const mat  = PIECE_VALUE[pt] + pstScore(pt, file, rank, col);
    score += col === WHITE ? mat : -mat;
  }
  return score;
}

const INF = 1_000_000;

/** Alpha-beta minimax. Returns [score, bestMove]. */
function alphaBeta(
  b: BoardState,
  depth: number,
  alpha: number,
  beta: number,
  maximizing: boolean,
): number {
  if (depth === 0) return evaluate(b);

  const moves = legalMoves(b);

  if (moves.length === 0) {
    if (isCheckmate(b)) return maximizing ? -INF : INF;
    return 0; // stalemate
  }

  // Move ordering: captures first (MVV-LVA)
  moves.sort((a, _b2) => {
    const capture = b.squares[a.to] !== EMPTY ? 1 : 0;
    return -capture;
  });

  if (maximizing) {
    let best = -INF;
    for (const m of moves) {
      const nb = applyMove(b, m);
      best = Math.max(best, alphaBeta(nb, depth - 1, alpha, beta, false));
      alpha = Math.max(alpha, best);
      if (alpha >= beta) break;
    }
    return best;
  } else {
    let best = INF;
    for (const m of moves) {
      const nb = applyMove(b, m);
      best = Math.min(best, alphaBeta(nb, depth - 1, alpha, beta, true));
      beta = Math.min(beta, best);
      if (alpha >= beta) break;
    }
    return best;
  }
}

/** Find the best move for the current side. Depth controls strength. */
export function findBestMove(b: BoardState, depth: number = 3): Move | null {
  const moves = legalMoves(b);
  if (moves.length === 0) return null;

  const maximizing = b.turn === WHITE;
  let bestScore = maximizing ? -INF : INF;
  let bestMove: Move = moves[0];

  // Move ordering: captures first
  moves.sort((a, _b2) => {
    const capture = b.squares[a.to] !== EMPTY ? 1 : 0;
    return -capture;
  });

  for (const m of moves) {
    const nb = applyMove(b, m);
    const score = alphaBeta(nb, depth - 1, -INF, INF, !maximizing);
    if (maximizing ? score > bestScore : score < bestScore) {
      bestScore = score;
      bestMove  = m;
    }
  }

  return bestMove;
}
