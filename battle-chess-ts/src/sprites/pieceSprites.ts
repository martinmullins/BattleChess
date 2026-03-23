/**
 * Sprite mapping for Battle Chess pieces.
 *
 * Sprites extracted from ALLCANM1 using RLE decoding and a chess-tuned
 * VGA palette approximation.  White-piece sprites cluster around palette
 * indices 199–242 (cream/ivory); black-piece sprites around 24–108 (mahogany).
 *
 * Sprite filename format: sprite_NN_WxH.png
 *
 * Mapping derived from per-sprite dominant-colour analysis:
 *   White small (19 px wide)  → pawn
 *   White medium (31-35 px)   → knight / bishop / rook
 *   White large  (38-40 px)   → queen / king
 *   Black small  (17-22 px)   → pawn / minor pieces
 *   Black medium (23-28 px)   → rook / queen / king
 */

import { WHITE, BLACK, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING } from '../chess/types.js';

export interface SpriteInfo {
  filename: string;
  w: number;
  h: number;
}

/** Map from (color, pieceType) to sprite info from ALLCANM1. */
export const PIECE_SPRITES: Record<number, Record<number, SpriteInfo>> = {
  [WHITE]: {
    [PAWN]:   { filename: 'sprite_00_19x46.png', w: 19, h: 46 },
    [KNIGHT]: { filename: 'sprite_07_33x42.png', w: 33, h: 42 },
    [BISHOP]: { filename: 'sprite_08_35x42.png', w: 35, h: 42 },
    [ROOK]:   { filename: 'sprite_05_31x46.png', w: 31, h: 46 },
    [QUEEN]:  { filename: 'sprite_10_38x45.png', w: 38, h: 45 },
    [KING]:   { filename: 'sprite_04_33x46.png', w: 33, h: 46 },
  },
  [BLACK]: {
    [PAWN]:   { filename: 'sprite_13_17x40.png', w: 17, h: 40 },
    [KNIGHT]: { filename: 'sprite_25_23x47.png', w: 23, h: 47 },
    [BISHOP]: { filename: 'sprite_26_20x44.png', w: 20, h: 44 },
    [ROOK]:   { filename: 'sprite_24_24x48.png', w: 24, h: 48 },
    [QUEEN]:  { filename: 'sprite_28_26x43.png', w: 26, h: 43 },
    [KING]:   { filename: 'sprite_12_22x40.png', w: 22, h: 40 },
  },
};

const BASE_PATH = '/sprites/';

/** Pre-load all piece sprites and return a map from filename → HTMLImageElement. */
export async function loadAllSprites(): Promise<Map<string, HTMLImageElement>> {
  const map = new Map<string, HTMLImageElement>();
  const promises: Promise<void>[] = [];

  for (const colorSprites of Object.values(PIECE_SPRITES)) {
    for (const info of Object.values(colorSprites)) {
      if (map.has(info.filename)) continue;
      const img = new Image();
      const p = new Promise<void>((resolve) => {
        img.onload = () => resolve();
        img.onerror = () => {
          console.warn(`Failed to load sprite: ${info.filename}`);
          resolve();
        };
        img.src = BASE_PATH + info.filename;
      });
      map.set(info.filename, img);
      promises.push(p);
    }
  }

  await Promise.all(promises);
  return map;
}
