#!/usr/bin/env python3
"""
normalize_decompiled.py
Preprocesses Ghidra-decompiled C for compilation with Open Watcom (16-bit DOS).

Fixes applied:
  1. Strip __cdecl16near / __cdecl16far modifiers
  2. Normalize (void) -> () in definitions to match unspecified prototypes
  3. Replace `stack0xNNNN` identifiers with typed local variable names
  4. Suppress void-expression assignments: `x = void_func()` -> `void_func()`
  5. Add required headers
"""
import re, sys

SRC  = 'decompiled/CHESS_decompiled.c'
DST  = 'src/chess.c'

with open(SRC, 'r') as f:
    code = f.read()

# 1. Strip Ghidra calling convention decorators
code = re.sub(r'__cdecl16(near|far)\s*', '', code)

# 2. Normalize (void) parameters in definitions to ()
#    Match: return_type FUN_xxx(void)  at the start of a line
code = re.sub(
    r'^(\w[\w\s\*]*\s+)(FUN_\w+|thunk_FUN_\w+|func_0x\w+)\s*\(void\)',
    r'\1\2()',
    code, flags=re.MULTILINE
)

# 3. Replace stack0xNNNN with _stack_var_NNNN (valid C identifier)
code = re.sub(r'\bstack0x([0-9a-fA-F]+)\b', r'_stack_var_\1', code)

# 4. Wrap void-expression assignments in a cast-to-void statement
#    e.g.  x = void_func(args)  ->  void_func(args)
#    Heuristic: find `identifier = FUN_xxx(` where FUN_xxx returns void.
#    We rely on the compiler warning for remaining issues.
#    (Full fix would require a type map - left for future passes)

# 5. Prepend headers
header = '/* Battle Chess - Decompiled source (preprocessed) */\n'
header += '#include "ghidra_types.h"\n'
header += '#include "chess_protos.h"\n\n'

# Remove any existing header comments before the first function
code = re.sub(r'^/\*.*?\*/\s*', '', code, count=2, flags=re.DOTALL)
code = header + code

with open(DST, 'w') as f:
    f.write(code)

print(f"Preprocessed {SRC} -> {DST}")
