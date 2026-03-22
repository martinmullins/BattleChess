import { Color, Move, WHITE, BLACK, EMPTY, QUEEN, ROOK, BISHOP, KNIGHT, PieceType, pieceColor, moveToAlgebraic } from './chess/types.js';
import { BoardState, startPosition, applyMove, inCheck, findKing } from './chess/board.js';
import { legalMoves, isCheckmate, isStalemate } from './chess/moves.js';
import { findBestMove } from './chess/ai.js';
import { Renderer } from './render/renderer.js';

type GameStatus = 'playing' | 'checkmate' | 'stalemate' | 'draw';

export class Game {
  private board: BoardState;
  private renderer: Renderer;
  private canvas: HTMLCanvasElement;

  private selected: number = -1;
  private legalTargets: number[] = [];
  private lastMove: Move | null = null;
  private moveHistory: Move[] = [];
  private boardHistory: BoardState[] = [];

  private playerColor: Color = WHITE;
  private aiDepth: number = 3;
  private aiThinking: boolean = false;
  private status: GameStatus = 'playing';

  // Promotion
  private pendingPromotion: { from: number; to: number } | null = null;

  // DOM refs
  private turnEl: HTMLElement;
  private checkEl: HTMLElement;
  private moveListEl: HTMLElement;

  constructor(canvas: HTMLCanvasElement) {
    this.canvas = canvas;
    this.renderer = new Renderer(canvas);
    this.board = startPosition();
    this.boardHistory = [this.board];

    this.turnEl     = document.getElementById('turn-indicator')!;
    this.checkEl    = document.getElementById('check-indicator')!;
    this.moveListEl = document.getElementById('move-list-entries')!;

    canvas.addEventListener('click', this.onCanvasClick.bind(this));
    document.getElementById('btn-new-game')!.addEventListener('click', () => this.newGame());
    document.getElementById('btn-flip')!.addEventListener('click', () => {
      this.renderer.setFlipped(!this.isFlipped);
      this.isFlipped = !this.isFlipped;
      this.render();
    });
    document.getElementById('btn-play-white')!.addEventListener('click', () => {
      this.playerColor = WHITE;
      this.newGame();
    });
    document.getElementById('btn-play-black')!.addEventListener('click', () => {
      this.playerColor = BLACK;
      this.renderer.setFlipped(true);
      this.isFlipped = true;
      this.newGame();
    });

    // Promotion dialog
    document.querySelectorAll('.promo-btn').forEach(btn => {
      btn.addEventListener('click', () => {
        const piece = (btn as HTMLElement).dataset['piece'];
        if (piece && this.pendingPromotion) {
          const promoMap: Record<string, PieceType> = { Q: QUEEN, R: ROOK, B: BISHOP, N: KNIGHT };
          this.finishPromotion(promoMap[piece] ?? QUEEN);
        }
      });
    });

    this.render();
    this.updateStatus();

    // If player is black, AI moves first
    if (this.playerColor === BLACK) {
      setTimeout(() => this.doAIMove(), 300);
    }
  }

  private isFlipped: boolean = false;

  newGame(): void {
    this.board = startPosition();
    this.boardHistory = [this.board];
    this.moveHistory = [];
    this.selected = -1;
    this.legalTargets = [];
    this.lastMove = null;
    this.status = 'playing';
    this.aiThinking = false;
    this.pendingPromotion = null;
    this.moveListEl.innerHTML = '';
    this.render();
    this.updateStatus();

    if (this.playerColor === BLACK) {
      setTimeout(() => this.doAIMove(), 300);
    }
  }

  private onCanvasClick(e: MouseEvent): void {
    if (this.status !== 'playing') return;
    if (this.aiThinking) return;
    if (this.board.turn !== this.playerColor) return;
    if (this.pendingPromotion) return;

    const rect = this.canvas.getBoundingClientRect();
    const px = (e.clientX - rect.left) * (this.canvas.width / rect.width);
    const py = (e.clientY - rect.top)  * (this.canvas.height / rect.height);
    const s = this.renderer.pixelToSquare(px, py);
    if (s < 0) return;

    if (this.selected === -1) {
      // Select a piece
      const piece = this.board.squares[s];
      if (piece !== EMPTY && pieceColor(piece) === this.playerColor) {
        this.selected = s;
        const moves = legalMoves(this.board);
        this.legalTargets = moves.filter(m => m.from === s).map(m => m.to);
      }
    } else {
      // Try to move
      const moves = legalMoves(this.board).filter(m => m.from === this.selected && m.to === s);
      if (moves.length > 0) {
        const move = moves[0];
        // Check for pawn promotion
        if (moves.some(m => m.promotion)) {
          this.pendingPromotion = { from: this.selected, to: s };
          this.showPromotionDialog();
          this.selected = -1;
          this.legalTargets = [];
          this.render();
          return;
        }
        this.executeMove(move);
      } else {
        // Click on another own piece — reselect
        const piece = this.board.squares[s];
        if (piece !== EMPTY && pieceColor(piece) === this.playerColor) {
          this.selected = s;
          const allMoves = legalMoves(this.board);
          this.legalTargets = allMoves.filter(m => m.from === s).map(m => m.to);
        } else {
          this.selected = -1;
          this.legalTargets = [];
        }
      }
    }
    this.render();
  }

  private executeMove(move: Move): void {
    this.board = applyMove(this.board, move);
    this.boardHistory.push(this.board);
    this.moveHistory.push(move);
    this.lastMove = move;
    this.selected = -1;
    this.legalTargets = [];

    this.addMoveToList(move);
    this.checkGameStatus();
    this.render();
    this.updateStatus();

    if (this.status === 'playing') {
      setTimeout(() => this.doAIMove(), 150);
    }
  }

  private showPromotionDialog(): void {
    const dlg = document.getElementById('promotion-dialog')!;
    dlg.style.display = 'block';
  }

  private hidePromotionDialog(): void {
    const dlg = document.getElementById('promotion-dialog')!;
    dlg.style.display = 'none';
  }

  private finishPromotion(promo: PieceType): void {
    this.hidePromotionDialog();
    if (!this.pendingPromotion) return;
    const { from, to } = this.pendingPromotion;
    this.pendingPromotion = null;

    const moves = legalMoves(this.board).filter(
      m => m.from === from && m.to === to && m.promotion === promo
    );
    if (moves.length > 0) this.executeMove(moves[0]);
  }

  private async doAIMove(): Promise<void> {
    if (this.status !== 'playing') return;
    if (this.board.turn === this.playerColor) return;

    this.aiThinking = true;
    this.updateStatus();

    // Run AI in a microtask to allow re-render
    await new Promise<void>(resolve => setTimeout(resolve, 10));

    const move = findBestMove(this.board, this.aiDepth);
    this.aiThinking = false;

    if (move) {
      // Handle AI promotion (always pick queen)
      const moves = legalMoves(this.board).filter(
        m => m.from === move.from && m.to === move.to
      );
      const finalMove = moves.find(m => m.promotion === QUEEN) ?? moves[0] ?? move;
      this.board = applyMove(this.board, finalMove);
      this.boardHistory.push(this.board);
      this.moveHistory.push(finalMove);
      this.lastMove = finalMove;
      this.addMoveToList(finalMove);
      this.checkGameStatus();
    }

    this.render();
    this.updateStatus();
  }

  private checkGameStatus(): void {
    if (isCheckmate(this.board)) {
      this.status = 'checkmate';
    } else if (isStalemate(this.board)) {
      this.status = 'stalemate';
    } else if (this.board.halfmove >= 100) {
      this.status = 'draw';
    }
  }

  private addMoveToList(move: Move): void {
    const moveNum = Math.ceil(this.moveHistory.length / 2);
    const isWhiteMove = this.moveHistory.length % 2 === 1;
    const algebraic = moveToAlgebraic(move, this.boardHistory[this.boardHistory.length - 2].squares);

    const entry = document.createElement('div');
    entry.className = 'move-entry';
    entry.textContent = isWhiteMove ? `${moveNum}. ${algebraic}` : `   ... ${algebraic}`;
    this.moveListEl.appendChild(entry);
    this.moveListEl.scrollTop = this.moveListEl.scrollHeight;
  }

  private updateStatus(): void {
    const color = this.board.turn;
    const colorName = color === WHITE ? 'White' : 'Black';

    if (this.status === 'checkmate') {
      const winner = color === WHITE ? 'Black' : 'White';
      this.turnEl.textContent = `Checkmate — ${winner} wins!`;
      this.checkEl.textContent = '';
    } else if (this.status === 'stalemate') {
      this.turnEl.textContent = 'Stalemate — Draw!';
      this.checkEl.textContent = '';
    } else if (this.status === 'draw') {
      this.turnEl.textContent = '50-move rule — Draw!';
      this.checkEl.textContent = '';
    } else if (this.aiThinking) {
      this.turnEl.textContent = 'AI is thinking...';
      this.checkEl.textContent = '';
    } else {
      this.turnEl.textContent = `${colorName} to move`;
      this.checkEl.textContent = inCheck(this.board, color) ? `${colorName} is in check!` : '';
    }
  }

  private render(): void {
    const checkedKing = inCheck(this.board, this.board.turn)
      ? findKing(this.board, this.board.turn)
      : -1;
    this.renderer.draw(
      this.board,
      this.selected,
      this.legalTargets,
      this.lastMove,
      checkedKing,
    );
  }
}
