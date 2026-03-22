import {
  Color, PieceType, Move,
  WHITE, EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING,
  CASTLE_WK, CASTLE_WQ, CASTLE_BK, CASTLE_BQ,
  pieceType, pieceColor, sq, sqFile, sqRank,
} from './types.js';
import { BoardState, applyMove, inCheck, isAttacked } from './board.js';

/** Generate all pseudo-legal moves for the current side. */
function pseudoLegal(b: BoardState): Move[] {
  const moves: Move[] = [];
  const color = b.turn;
  const opp   = (1 - color) as Color;

  for (let from = 0; from < 64; from++) {
    const piece = b.squares[from];
    if (piece === EMPTY || pieceColor(piece) !== color) continue;
    const pt = pieceType(piece);
    const file = sqFile(from);
    const rank = sqRank(from);

    switch (pt) {
      case PAWN: {
        const dir = color === WHITE ? 1 : -1;
        const startRank = color === WHITE ? 1 : 6;
        const promoRank = color === WHITE ? 7 : 0;

        // Forward one
        const oneStep = sq(file, rank + dir);
        if (rank + dir >= 0 && rank + dir < 8 && b.squares[oneStep] === EMPTY) {
          if (rank + dir === promoRank) {
            for (const promo of [QUEEN, ROOK, BISHOP, KNIGHT] as PieceType[]) {
              moves.push({ from, to: oneStep, promotion: promo });
            }
          } else {
            moves.push({ from, to: oneStep });
          }
          // Forward two from start rank
          if (rank === startRank) {
            const twoStep = sq(file, rank + dir * 2);
            if (b.squares[twoStep] === EMPTY) moves.push({ from, to: twoStep });
          }
        }

        // Captures
        for (const df of [-1, 1]) {
          const cf = file + df;
          if (cf < 0 || cf > 7) continue;
          const to = sq(cf, rank + dir);
          if (rank + dir < 0 || rank + dir > 7) continue;
          const target = b.squares[to];
          if (target !== EMPTY && pieceColor(target) === opp) {
            if (rank + dir === promoRank) {
              for (const promo of [QUEEN, ROOK, BISHOP, KNIGHT] as PieceType[]) {
                moves.push({ from, to, promotion: promo });
              }
            } else {
              moves.push({ from, to });
            }
          }
          // En passant
          if (to === b.enPassant) {
            moves.push({ from, to, enPassant: true });
          }
        }
        break;
      }

      case KNIGHT: {
        const offsets = [[-2,-1],[-2,1],[-1,-2],[-1,2],[1,-2],[1,2],[2,-1],[2,1]];
        for (const [df, dr] of offsets) {
          const tf = file + df, tr = rank + dr;
          if (tf < 0 || tf > 7 || tr < 0 || tr > 7) continue;
          const to = sq(tf, tr);
          const target = b.squares[to];
          if (target === EMPTY || pieceColor(target) === opp) moves.push({ from, to });
        }
        break;
      }

      case BISHOP:
      case ROOK:
      case QUEEN: {
        const dirs: [number,number][] = [];
        if (pt === BISHOP || pt === QUEEN) dirs.push([-1,-1],[-1,1],[1,-1],[1,1]);
        if (pt === ROOK   || pt === QUEEN) dirs.push([-1,0],[1,0],[0,-1],[0,1]);
        for (const [df, dr] of dirs) {
          let tf = file + df, tr = rank + dr;
          while (tf >= 0 && tf < 8 && tr >= 0 && tr < 8) {
            const to = sq(tf, tr);
            const target = b.squares[to];
            if (target !== EMPTY) {
              if (pieceColor(target) === opp) moves.push({ from, to });
              break;
            }
            moves.push({ from, to });
            tf += df; tr += dr;
          }
        }
        break;
      }

      case KING: {
        for (const [df, dr] of [[-1,-1],[-1,0],[-1,1],[0,-1],[0,1],[1,-1],[1,0],[1,1]]) {
          const tf = file + df, tr = rank + dr;
          if (tf < 0 || tf > 7 || tr < 0 || tr > 7) continue;
          const to = sq(tf, tr);
          const target = b.squares[to];
          if (target === EMPTY || pieceColor(target) === opp) moves.push({ from, to });
        }

        // Castling
        if (!inCheck(b, color)) {
          const backRank = color === WHITE ? 0 : 7;
          const kingFrom = sq(4, backRank);
          if (from !== kingFrom) break;

          const kMask = color === WHITE ? CASTLE_WK : CASTLE_BK;
          const qMask = color === WHITE ? CASTLE_WQ : CASTLE_BQ;

          if ((b.castling & kMask) &&
              b.squares[sq(5, backRank)] === EMPTY &&
              b.squares[sq(6, backRank)] === EMPTY &&
              !isAttacked(b, sq(5, backRank), opp) &&
              !isAttacked(b, sq(6, backRank), opp)) {
            moves.push({ from, to: sq(6, backRank), castle: 'K' });
          }

          if ((b.castling & qMask) &&
              b.squares[sq(3, backRank)] === EMPTY &&
              b.squares[sq(2, backRank)] === EMPTY &&
              b.squares[sq(1, backRank)] === EMPTY &&
              !isAttacked(b, sq(3, backRank), opp) &&
              !isAttacked(b, sq(2, backRank), opp)) {
            moves.push({ from, to: sq(2, backRank), castle: 'Q' });
          }
        }
        break;
      }
    }
  }
  return moves;
}

/** Generate all legal moves (pseudo-legal filtered for leaving king in check). */
export function legalMoves(b: BoardState): Move[] {
  return pseudoLegal(b).filter(m => {
    const nb = applyMove(b, m);
    return !inCheck(nb, b.turn);
  });
}

/** Does the current side have any legal moves? */
export function hasLegalMoves(b: BoardState): boolean {
  return pseudoLegal(b).some(m => {
    const nb = applyMove(b, m);
    return !inCheck(nb, b.turn);
  });
}

/** Is the current position checkmate? */
export function isCheckmate(b: BoardState): boolean {
  return inCheck(b, b.turn) && !hasLegalMoves(b);
}

/** Is the current position stalemate? */
export function isStalemate(b: BoardState): boolean {
  return !inCheck(b, b.turn) && !hasLegalMoves(b);
}
