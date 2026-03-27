/*
 * sdl/args.h  --  command-line / PSP environment argument parsing
 *
 * Original source:
 *   src/chess.c          FUN_243e_0024 @ 243e:0024  (lines 16469-16480)
 *   CHESS_disassembly.asm  243e:003e - 243e:005b
 */
#ifndef ARGS_H
#define ARGS_H

/*
 * ArgsState -- parsed argument state.
 *
 * Original: the startup segment uses two 16-bit data slots in CS:
 *
 *   CS:[BP+0x434]  (CS:0x0337) -- DI after ADD DI,0x3
 *                  Near-offset within the environment segment pointing to
 *                  the start of the fully-qualified program path.
 *                  disassembly: 243e:005b
 *                  SDL equivalent: argv[0]
 *
 *   CS:[BP+0x436]  (CS:0x0339) -- the environment segment selector (ES after
 *                  MOV ES, word ptr ES:[0x2c])
 *                  disassembly: 243e:0037
 *                  SDL equivalent: not used (flat address space)
 *
 * RECOVER NEXT (step 3-1-ii): add fields for every flag the DOS version
 * accepted once those flags are identified in the disassembly.
 */
typedef struct {
    const char *exe_path;   /* argv[0] -- mirrors CS:[BP+0x434] path ptr    */
} ArgsState;

/*
 * args_parse -- extract the program path and any command-line flags.
 *
 * Maps to the PSP environment-block scan in FUN_243e_0024:
 *   src/chess.c:16469-16480   disassembly: 243e:003e-243e:005b
 *
 * In DOS, the code found the exe path by:
 *   1. Loading the environment segment from PSP offset 0x2c
 *      (MOV ES, word ptr ES:[0x2c]  disassembly: 243e:0037)
 *   2. SCASB.REPNE scanning for the double-NUL end-of-environment marker
 *      (disassembly: 243e:004e-243e:0054)
 *   3. Skipping 3 bytes (2-byte word-count + first char) to land on the
 *      fully-qualified program path
 *      (ADD DI, 0x3  disassembly: 243e:0056)
 *   4. Saving the near-offset into CS:[BP+0x434]
 *      (MOV word ptr CS:[BP+0x434], DI  disassembly: 243e:005b)
 *
 * In the SDL port argv[0] is the flat-model equivalent of that path pointer.
 *
 * out  -- caller-allocated ArgsState to fill in.
 * argc -- main() argc.
 * argv -- main() argv.
 *
 * Returns 0 on success, -1 on error (e.g. argc < 1).
 */
int args_parse(ArgsState *out, int argc, char *argv[]);

#endif /* ARGS_H */
