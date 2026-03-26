import {
  Piece, Color, PieceType, Square, Move,
  WHITE, BLACK, EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING,
  CASTLE_WK, CASTLE_WQ, CASTLE_BK, CASTLE_BQ,
  makePiece, pieceType, pieceColor, sq, sqFile, sqRank,
} from './types.js';

export interface BoardState {
  squares: Piece[];          // 64 squares
  turn: Color;
  castling: number;          // bitmask of CASTLE_* flags
  enPassant: Square | -1;    // target square behind double-pushed pawn, or -1
  halfmove: number;          // for 50-move rule
  fullmove: number;
}

/** Create the standard starting position. */
export function startPosition(): BoardState {
  const s = new Array<Piece>(64).fill(EMPTY);

  const backRank: PieceType[] = [ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK];
  for (let f = 0; f < 8; f++) {
    s[sq(f, 0)] = makePiece(backRank[f], WHITE);
    s[sq(f, 1)] = makePiece(PAWN, WHITE);
    s[sq(f, 6)] = makePiece(PAWN, BLACK);
    s[sq(f, 7)] = makePiece(backRank[f], BLACK);
  }

  return {
    squares: s,
    turn: WHITE,
    castling: CASTLE_WK | CASTLE_WQ | CASTLE_BK | CASTLE_BQ,
    enPassant: -1,
    halfmove: 0,
    fullmove: 1,
  };
}

/** Deep clone a board state. */
export function cloneBoard(b: BoardState): BoardState {
  return {
    squares: b.squares.slice(),
    turn: b.turn,
    castling: b.castling,
    enPassant: b.enPassant,
    halfmove: b.halfmove,
    fullmove: b.fullmove,
  };
}

/** Apply a move and return the new board state. Does NOT validate legality. */
export function applyMove(b: BoardState, m: Move): BoardState {
  const nb = cloneBoard(b);
  const piece = nb.squares[m.from];
  const pt = pieceType(piece);
  const color = pieceColor(piece);

  nb.squares[m.to] = piece;
  nb.squares[m.from] = EMPTY;

  // En passant capture
  if (m.enPassant) {
    const capturedPawnSq = sq(sqFile(m.to), sqRank(m.from));
    nb.squares[capturedPawnSq] = EMPTY;
  }

  // Promotion
  if (m.promotion) {
    nb.squares[m.to] = makePiece(m.promotion, color);
  }

  // Castling: move the rook
  if (m.castle === 'K') {
    const rank = color === WHITE ? 0 : 7;
    nb.squares[sq(5, rank)] = makePiece(ROOK, color);
    nb.squares[sq(7, rank)] = EMPTY;
  } else if (m.castle === 'Q') {
    const rank = color === WHITE ? 0 : 7;
    nb.squares[sq(3, rank)] = makePiece(ROOK, color);
    nb.squares[sq(0, rank)] = EMPTY;
  }

  // Update castling rights
  if (pt === KING) {
    nb.castling &= color === WHITE ? ~(CASTLE_WK | CASTLE_WQ) : ~(CASTLE_BK | CASTLE_BQ);
  }
  if (pt === ROOK) {
    if (m.from === sq(0, 0)) nb.castling &= ~CASTLE_WQ;
    if (m.from === sq(7, 0)) nb.castling &= ~CASTLE_WK;
    if (m.from === sq(0, 7)) nb.castling &= ~CASTLE_BQ;
    if (m.from === sq(7, 7)) nb.castling &= ~CASTLE_BK;
  }
  // If a rook is captured, revoke rights too
  if (m.to === sq(0, 0)) nb.castling &= ~CASTLE_WQ;
  if (m.to === sq(7, 0)) nb.castling &= ~CASTLE_WK;
  if (m.to === sq(0, 7)) nb.castling &= ~CASTLE_BQ;
  if (m.to === sq(7, 7)) nb.castling &= ~CASTLE_BK;

  // En passant target
  nb.enPassant = -1;
  if (pt === PAWN && Math.abs(sqRank(m.to) - sqRank(m.from)) === 2) {
    nb.enPassant = sq(sqFile(m.from), (sqRank(m.from) + sqRank(m.to)) >> 1);
  }

  // Halfmove clock
  nb.halfmove = (pt === PAWN || b.squares[m.to] !== EMPTY) ? 0 : nb.halfmove + 1;
  if (color === BLACK) nb.fullmove++;
  nb.turn = (color === WHITE ? BLACK : WHITE) as Color;

  return nb;
}

/** Find the square of the king for the given color. Returns -1 if not found (shouldn't happen). */
export function findKing(b: BoardState, color: Color): Square {
  const kingPiece = makePiece(KING, color);
  return b.squares.indexOf(kingPiece);
}

/** Is the given square attacked by the given color? */
export function isAttacked(b: BoardState, target: Square, byColor: Color): boolean {
  const opp = byColor;

  // Knight attacks
  const knightOffsets = [-17, -15, -10, -6, 6, 10, 15, 17];
  for (const off of knightOffsets) {
    const s = target + off;
    if (s < 0 || s > 63) continue;
    // Verify no wrap-around
    if (Math.abs(sqFile(s) - sqFile(target)) > 2) continue;
    const p = b.squares[s];
    if (p !== EMPTY && pieceColor(p) === opp && pieceType(p) === KNIGHT) return true;
  }

  // Sliding pieces (rook/queen and bishop/queen) + king
  const rookDirs   = [1, -1, 8, -8];
  const bishopDirs = [9, -9, 7, -7];

  for (const dir of rookDirs) {
    for (let s = target + dir; ; s += dir) {
      if (s < 0 || s > 63) break;
      if (dir === 1  && sqFile(s) === 0) { /* wrapped */ break; }
      if (dir === -1 && sqFile(s) === 7) { /* wrapped */ break; }
      const p = b.squares[s];
      if (p !== EMPTY) {
        if (pieceColor(p) === opp && (pieceType(p) === ROOK || pieceType(p) === QUEEN)) return true;
        // Adjacent king
        if (pieceColor(p) === opp && pieceType(p) === KING &&
            Math.abs(sqFile(s) - sqFile(target)) <= 1 &&
            Math.abs(sqRank(s) - sqRank(target)) <= 1) return true;
        break;
      }
    }
  }

  for (const dir of bishopDirs) {
    for (let s = target + dir; ; s += dir) {
      if (s < 0 || s > 63) break;
      // Prevent file wrap
      const prevFile = sqFile(s - dir);
      const curFile  = sqFile(s);
      if (Math.abs(curFile - prevFile) !== 1) break;
      const p = b.squares[s];
      if (p !== EMPTY) {
        if (pieceColor(p) === opp && (pieceType(p) === BISHOP || pieceType(p) === QUEEN)) return true;
        if (pieceColor(p) === opp && pieceType(p) === KING &&
            Math.abs(curFile - sqFile(target)) <= 1 &&
            Math.abs(sqRank(s) - sqRank(target)) <= 1) return true;
        break;
      }
    }
  }

  // Pawn attacks
  const pawnDir = opp === WHITE ? -1 : 1;
  const pawnRank = sqRank(target) + pawnDir;
  if (pawnRank >= 0 && pawnRank < 8) {
    for (const df of [-1, 1]) {
      const pFile = sqFile(target) + df;
      if (pFile >= 0 && pFile < 8) {
        const p = b.squares[sq(pFile, pawnRank)];
        if (p !== EMPTY && pieceColor(p) === opp && pieceType(p) === PAWN) return true;
      }
    }
  }

  return false;
}

/** Is the given color in check? */
export function inCheck(b: BoardState, color: Color): boolean {
  const kingSq = findKing(b, color);
  if (kingSq < 0) return false;
  return isAttacked(b, kingSq, (1 - color) as Color);
}
