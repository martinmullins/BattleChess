// @vitest-environment jsdom
import { describe, it, expect, vi, beforeAll, beforeEach, afterEach } from 'vitest';
import { sq } from './chess/types.js';
import { Game } from './game.js';
import { findBestMove } from './chess/ai.js';

// jsdom doesn't implement the Touch constructor — polyfill it
beforeAll(() => {
  if (typeof (globalThis as any).Touch === 'undefined') {
    (globalThis as any).Touch = class Touch {
      identifier: number; target: EventTarget;
      clientX: number; clientY: number;
      screenX: number; screenY: number;
      pageX: number; pageY: number;
      radiusX: number; radiusY: number; rotationAngle: number; force: number;
      constructor(init: any) {
        this.identifier  = init.identifier  ?? 0;
        this.target      = init.target;
        this.clientX     = init.clientX     ?? 0;
        this.clientY     = init.clientY     ?? 0;
        this.screenX     = init.screenX     ?? 0;
        this.screenY     = init.screenY     ?? 0;
        this.pageX       = init.pageX       ?? 0;
        this.pageY       = init.pageY       ?? 0;
        this.radiusX     = init.radiusX     ?? 0;
        this.radiusY     = init.radiusY     ?? 0;
        this.rotationAngle = init.rotationAngle ?? 0;
        this.force       = init.force       ?? 0;
      }
    };
  }
});

// ---------------------------------------------------------------------------
// Module mocks  (top-level — hoisted before imports by Vitest)
// ---------------------------------------------------------------------------

// Shared renderer instance returned by the mock constructor.
// Reset its spy fns between tests in beforeEach.
const mockRenderer = {
  pixelToSquare: vi.fn().mockReturnValue(-1),
  draw:          vi.fn(),
  setFlipped:    vi.fn(),
};

// The Renderer mock must use `function` (not an arrow) so `new Renderer()`
// works as a constructor.  A constructor that returns an object uses that
// object directly — the perfect pattern for a shared mock.
vi.mock('./render/renderer.js', () => ({
  Renderer: vi.fn(function () { return mockRenderer; }),
}));

// AI: return null by default so tests don't wait on real minimax
vi.mock('./chess/ai.js', () => ({
  findBestMove: vi.fn().mockReturnValue(null),
}));

// Sprites: no network requests in tests
vi.mock('./sprites/pieceSprites.js', () => ({
  PIECE_SPRITES: {},
  loadAllSprites: () => Promise.resolve(new Map()),
}));

// ---------------------------------------------------------------------------
// DOM helpers
// ---------------------------------------------------------------------------

function buildDOM(): void {
  document.body.innerHTML = `
    <canvas id="board-canvas" width="512" height="512"></canvas>
    <div id="turn-indicator"></div>
    <div id="check-indicator"></div>
    <div id="move-list-entries"></div>
    <button id="btn-new-game"></button>
    <button id="btn-flip"></button>
    <button id="btn-play-white"></button>
    <button id="btn-play-black"></button>
    <div id="promotion-dialog" style="display:none">
      <button class="promo-btn" data-piece="Q">♛</button>
      <button class="promo-btn" data-piece="R">♜</button>
      <button class="promo-btn" data-piece="B">♝</button>
      <button class="promo-btn" data-piece="N">♞</button>
    </div>`;
}

const canvas = () => document.getElementById('board-canvas') as HTMLCanvasElement;
const turnText = () => (document.getElementById('turn-indicator')  as HTMLElement).textContent ?? '';
const checkText = () => (document.getElementById('check-indicator') as HTMLElement).textContent ?? '';
const moveEntries = () => (document.getElementById('move-list-entries') as HTMLElement).children.length;

/** Fire a mouse click at given client coords */
function click(cx = 0, cy = 0): void {
  canvas().dispatchEvent(new MouseEvent('click', { bubbles: true, clientX: cx, clientY: cy }));
}

/** Fire a touch tap (touchstart + touchend at same position) */
function tap(cx: number, cy: number): void {
  const t = () => new Touch({ identifier: 1, target: canvas(), clientX: cx, clientY: cy });
  canvas().dispatchEvent(new TouchEvent('touchstart', {
    bubbles: true, cancelable: true,
    touches: [t()], changedTouches: [t()],
  }));
  canvas().dispatchEvent(new TouchEvent('touchend', {
    bubbles: true, cancelable: true,
    touches: [], changedTouches: [t()],
  }));
}

/** Fire a touch swipe (start at x0,y0 and end at x1,y1) */
function swipe(x0: number, y0: number, x1: number, y1: number): void {
  const t0 = new Touch({ identifier: 1, target: canvas(), clientX: x0, clientY: y0 });
  const t1 = new Touch({ identifier: 1, target: canvas(), clientX: x1, clientY: y1 });
  canvas().dispatchEvent(new TouchEvent('touchstart', { bubbles: true, cancelable: true, touches: [t0], changedTouches: [t0] }));
  canvas().dispatchEvent(new TouchEvent('touchend',   { bubbles: true, cancelable: true, touches: [],   changedTouches: [t1] }));
}

function btnClick(id: string): void {
  (document.getElementById(id) as HTMLElement).click();
}

// ---------------------------------------------------------------------------
// Per-test setup
// ---------------------------------------------------------------------------

beforeEach(() => {
  buildDOM();
  vi.useFakeTimers();
  mockRenderer.pixelToSquare.mockReset().mockReturnValue(-1);
  mockRenderer.draw.mockReset();
  mockRenderer.setFlipped.mockReset();
  vi.mocked(findBestMove).mockReturnValue(null);
});

afterEach(() => {
  vi.useRealTimers();
  vi.clearAllMocks();
});

// ---------------------------------------------------------------------------
// Initial state
// ---------------------------------------------------------------------------

describe('initial state', () => {
  it('turn indicator shows "White to move"', () => {
    new Game(canvas());
    expect(turnText()).toBe('White to move');
  });

  it('check indicator is empty at start', () => {
    new Game(canvas());
    expect(checkText()).toBe('');
  });

  it('move list is empty at start', () => {
    new Game(canvas());
    expect(moveEntries()).toBe(0);
  });

  it('renders the board on construction', () => {
    new Game(canvas());
    expect(mockRenderer.draw).toHaveBeenCalled();
  });

  it('canvas gets touch-action:none for mobile scroll prevention', () => {
    new Game(canvas());
    expect(canvas().style.touchAction).toBe('none');
  });
});

// ---------------------------------------------------------------------------
// Mouse input — selection
// ---------------------------------------------------------------------------

describe('mouse input — selection', () => {
  it('off-board click (pixelToSquare=-1) triggers no extra render', () => {
    new Game(canvas());
    const before = mockRenderer.draw.mock.calls.length;
    mockRenderer.pixelToSquare.mockReturnValue(-1);
    click();
    expect(mockRenderer.draw.mock.calls.length).toBe(before);
  });

  it('clicking an empty square selects nothing', () => {
    new Game(canvas());
    mockRenderer.pixelToSquare.mockReturnValue(sq(4, 4)); // center of board, empty
    click();
    expect(mockRenderer.draw.mock.calls.at(-1)![1]).toBe(-1); // selected arg
  });

  it('clicking a white pawn selects it and produces legal targets', () => {
    new Game(canvas());
    mockRenderer.pixelToSquare.mockReturnValue(sq(4, 1)); // e2 pawn
    click();
    const lastArgs = mockRenderer.draw.mock.calls.at(-1)!;
    expect(lastArgs[1]).toBe(sq(4, 1));                   // selected
    expect((lastArgs[2] as number[]).length).toBeGreaterThan(0); // legal targets
  });

  it('clicking an opponent piece on white\'s turn does nothing', () => {
    new Game(canvas());
    mockRenderer.pixelToSquare.mockReturnValue(sq(4, 6)); // e7 black pawn
    click();
    expect(mockRenderer.draw.mock.calls.at(-1)![1]).toBe(-1);
  });

  it('clicking another own piece reselects', () => {
    new Game(canvas());
    mockRenderer.pixelToSquare.mockReturnValueOnce(sq(3, 1)); // d2
    click();
    mockRenderer.pixelToSquare.mockReturnValueOnce(sq(4, 1)); // e2
    click();
    expect(mockRenderer.draw.mock.calls.at(-1)![1]).toBe(sq(4, 1));
  });

  it('clicking a non-target empty square deselects', () => {
    new Game(canvas());
    mockRenderer.pixelToSquare.mockReturnValueOnce(sq(4, 1)); // select e2
    click();
    mockRenderer.pixelToSquare.mockReturnValueOnce(sq(3, 4)); // off-target empty
    click();
    expect(mockRenderer.draw.mock.calls.at(-1)![1]).toBe(-1);
  });
});

// ---------------------------------------------------------------------------
// Mouse input — move execution
// ---------------------------------------------------------------------------

describe('mouse input — move execution', () => {
  it('clicking a legal target executes the move and flips the turn', () => {
    new Game(canvas());
    mockRenderer.pixelToSquare.mockReturnValueOnce(sq(4, 1)); // select e2
    click();
    mockRenderer.pixelToSquare.mockReturnValueOnce(sq(4, 3)); // move e4
    click();
    expect(turnText()).toBe('Black to move');
  });

  it('a move adds one entry to the move list', () => {
    new Game(canvas());
    mockRenderer.pixelToSquare.mockReturnValueOnce(sq(4, 1));
    click();
    mockRenderer.pixelToSquare.mockReturnValueOnce(sq(4, 3));
    click();
    expect(moveEntries()).toBe(1);
  });

  it('renderer.draw receives the correct lastMove after a move', () => {
    new Game(canvas());
    mockRenderer.pixelToSquare.mockReturnValueOnce(sq(4, 1));
    click();
    mockRenderer.pixelToSquare.mockReturnValueOnce(sq(4, 3));
    click();
    const lastMove = mockRenderer.draw.mock.calls.at(-1)![3];
    expect(lastMove).not.toBeNull();
    expect(lastMove.from).toBe(sq(4, 1));
    expect(lastMove.to).toBe(sq(4, 3));
  });

  it('input is ignored while it is the AI\'s turn (board.turn !== playerColor)', () => {
    new Game(canvas());
    // White makes a move → board.turn becomes BLACK
    mockRenderer.pixelToSquare.mockReturnValueOnce(sq(4, 1));
    click();
    mockRenderer.pixelToSquare.mockReturnValueOnce(sq(4, 3));
    click();
    const countAfterMove = moveEntries();
    // Player tries to move again while it's black's turn
    mockRenderer.pixelToSquare.mockReturnValue(sq(4, 6));
    click();
    expect(moveEntries()).toBe(countAfterMove); // no extra move added
  });
});

// ---------------------------------------------------------------------------
// Touch input
// ---------------------------------------------------------------------------

describe('touch input', () => {
  it('a tap selects a piece (same result as a click)', () => {
    new Game(canvas());
    mockRenderer.pixelToSquare.mockReturnValue(sq(4, 1)); // e2 pawn
    tap(100, 100);
    const lastArgs = mockRenderer.draw.mock.calls.at(-1)!;
    expect(lastArgs[1]).toBe(sq(4, 1)); // selected
  });

  it('tap then tap on legal square executes a move', () => {
    new Game(canvas());
    mockRenderer.pixelToSquare.mockReturnValueOnce(sq(4, 1));
    tap(100, 100);
    mockRenderer.pixelToSquare.mockReturnValueOnce(sq(4, 3));
    tap(100, 200);
    expect(turnText()).toBe('Black to move');
    expect(moveEntries()).toBe(1);
  });

  it('a horizontal swipe >10px is ignored', () => {
    new Game(canvas());
    const before = mockRenderer.draw.mock.calls.length;
    mockRenderer.pixelToSquare.mockReturnValue(sq(4, 1));
    swipe(100, 100, 120, 100); // 20px — should be ignored
    expect(mockRenderer.draw.mock.calls.length).toBe(before);
  });

  it('a diagonal swipe >10px is ignored', () => {
    new Game(canvas());
    const before = mockRenderer.draw.mock.calls.length;
    mockRenderer.pixelToSquare.mockReturnValue(sq(4, 1));
    swipe(50, 50, 65, 65); // ~21px diagonal
    expect(mockRenderer.draw.mock.calls.length).toBe(before);
  });

  it('a tiny movement ≤10px is treated as a tap', () => {
    new Game(canvas());
    mockRenderer.pixelToSquare.mockReturnValue(sq(4, 1));
    swipe(100, 100, 108, 106); // 10px — still a tap
    expect(mockRenderer.draw.mock.calls.at(-1)![1]).toBe(sq(4, 1));
  });

  it('touch and click produce identical selection behaviour', () => {
    // Click path
    new Game(canvas());
    mockRenderer.pixelToSquare.mockReturnValue(sq(3, 1));
    click(50, 50);
    const clickSelected  = mockRenderer.draw.mock.calls.at(-1)![1];
    const clickTargets   = mockRenderer.draw.mock.calls.at(-1)![2] as number[];

    // Touch path — fresh game
    buildDOM();
    new Game(canvas());
    mockRenderer.pixelToSquare.mockReset().mockReturnValue(sq(3, 1));
    tap(50, 50);
    const touchSelected  = mockRenderer.draw.mock.calls.at(-1)![1];
    const touchTargets   = mockRenderer.draw.mock.calls.at(-1)![2] as number[];

    expect(touchSelected).toBe(clickSelected);
    expect(touchTargets).toEqual(clickTargets);
  });
});

// ---------------------------------------------------------------------------
// Controls
// ---------------------------------------------------------------------------

describe('controls', () => {
  it('New Game resets the turn to "White to move"', () => {
    new Game(canvas());
    mockRenderer.pixelToSquare.mockReturnValueOnce(sq(4, 1));
    click();
    mockRenderer.pixelToSquare.mockReturnValueOnce(sq(4, 3));
    click();
    expect(turnText()).toBe('Black to move');
    btnClick('btn-new-game');
    expect(turnText()).toBe('White to move');
  });

  it('New Game clears the move list', () => {
    new Game(canvas());
    mockRenderer.pixelToSquare.mockReturnValueOnce(sq(4, 1));
    click();
    mockRenderer.pixelToSquare.mockReturnValueOnce(sq(4, 3));
    click();
    expect(moveEntries()).toBe(1);
    btnClick('btn-new-game');
    expect(moveEntries()).toBe(0);
  });

  it('Flip Board calls renderer.setFlipped(true) on first flip', () => {
    new Game(canvas());
    btnClick('btn-flip');
    expect(mockRenderer.setFlipped).toHaveBeenCalledWith(true);
  });

  it('Flip Board toggles: second flip calls setFlipped(false)', () => {
    new Game(canvas());
    btnClick('btn-flip');
    btnClick('btn-flip');
    expect(mockRenderer.setFlipped).toHaveBeenLastCalledWith(false);
  });

  it('Play As White keeps white to move', () => {
    new Game(canvas());
    btnClick('btn-play-white');
    expect(turnText()).toBe('White to move');
  });

  it('Play As Black triggers an AI move after the startup delay', async () => {
    new Game(canvas());
    btnClick('btn-play-black');
    await vi.runAllTimersAsync();
    expect(findBestMove).toHaveBeenCalled();
  });
});

// ---------------------------------------------------------------------------
// AI thinking state
// ---------------------------------------------------------------------------

describe('AI thinking state', () => {
  it('shows "AI is thinking…" while the AI timer is mid-flight', async () => {
    new Game(canvas());
    // Make a white move so the 150ms AI timer is scheduled
    mockRenderer.pixelToSquare.mockReturnValueOnce(sq(4, 1));
    click();
    mockRenderer.pixelToSquare.mockReturnValueOnce(sq(4, 3));
    click();
    // Advance exactly to the outer setTimeout(150) threshold.
    // doAIMove sets aiThinking=true and calls updateStatus() before
    // hitting its own inner await, so the status is visible here.
    await vi.advanceTimersByTimeAsync(150);
    expect(turnText()).toBe('AI is thinking...');
  });

  it('returns to a normal status after AI finishes', async () => {
    new Game(canvas());
    mockRenderer.pixelToSquare.mockReturnValueOnce(sq(4, 1));
    click();
    mockRenderer.pixelToSquare.mockReturnValueOnce(sq(4, 3));
    click();
    await vi.runAllTimersAsync(); // fires 150ms + inner 10ms
    expect(turnText()).not.toBe('AI is thinking...');
  });
});

// ---------------------------------------------------------------------------
// Promotion dialog
// ---------------------------------------------------------------------------

describe('promotion dialog', () => {
  it('is hidden on game start', () => {
    new Game(canvas());
    expect((document.getElementById('promotion-dialog') as HTMLElement).style.display).toBe('none');
  });

  it('has buttons for Q, R, B, N', () => {
    new Game(canvas());
    const pieces = Array.from(
      document.querySelectorAll('.promo-btn')
    ).map(b => (b as HTMLElement).dataset['piece']);
    expect(pieces).toEqual(['Q', 'R', 'B', 'N']);
  });
});
