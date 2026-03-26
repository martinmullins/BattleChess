#!/usr/bin/env python3
"""
Convert Ghidra disassembly format to NASM assembly for FUN_1000_6cb4.
"""
import re
import sys

def extract_fn(path, start_label, end_label_prefix):
    lines = []
    in_fn = False
    with open(path) as f:
        for line in f:
            if start_label in line:
                in_fn = True
            if in_fn:
                lines.append(line.rstrip())
                if lines and end_label_prefix in line and start_label not in line:
                    lines.pop()
                    break
    return lines

def convert_operand(op):
    op = op.strip()
    # word ptr / byte ptr
    op = re.sub(r'\bword ptr\b\s*', 'word ', op)
    op = re.sub(r'\bbyte ptr\b\s*', 'byte ', op)
    op = re.sub(r'\bdword ptr\b\s*', 'dword ', op)
    # segment override: ES:[BX] -> [es:bx]
    op = re.sub(r'\bES:\[', '[es:', op)
    op = re.sub(r'\bDS:\[', '[ds:', op)
    op = re.sub(r'\bSS:\[', '[ss:', op)
    # 0x... hex constants -> just use them (NASM uses 0x too)
    return op

def addr_to_label(addr_str):
    # "0x1000:6d44" -> "loc_6d44"
    # "0x1000:ecaa" -> could be a function call
    m = re.match(r'0x1000:([0-9a-f]+)$', addr_str.strip(), re.I)
    if m:
        return 'loc_' + m.group(1)
    return addr_str

# External functions called from FUN_1000_6cb4
EXTERN_CALLS = {
    'ecaa': 'FUN_1000_ecaa',
    '0fb0': 'FUN_1000_0fb0',
    'ca56': 'FUN_1000_ca56',
    'cb5b': 'FUN_1000_cb5b',
    'e03a': 'FUN_1000_e03a',
    'e197': 'FUN_1000_e197',
    '1780': 'FUN_1000_1780',
    'f2f0': 'FUN_1000_f2f0',
    'e915': 'FUN_1000_e915',
    '1064': 'FUN_1000_1064',
    '58b0': 'FUN_1000_58b0',
    '102d': 'FUN_1000_102d',
}

def process_lines(raw_lines):
    out = []
    # collect all addresses in the function for label generation
    fn_addrs = set()
    for line in raw_lines:
        m = re.match(r'\s+1000:([0-9a-f]+)\s+', line, re.I)
        if m:
            fn_addrs.add(m.group(1).lower())
    # Jump/call targets that are within the function -> local labels
    jump_targets = set()
    for line in raw_lines:
        m = re.match(r'\s+1000:[0-9a-f]+\s+\w+\s+(0x1000:[0-9a-f]+)', line, re.I)
        if m:
            tm = re.match(r'0x1000:([0-9a-f]+)', m.group(1), re.I)
            if tm:
                addr = tm.group(1).lower()
                if addr in fn_addrs:
                    jump_targets.add(addr)

    for line in raw_lines:
        # skip comment/separator lines
        if line.startswith(';') or not line.strip():
            out.append('; ' + line if line.startswith(';') else '')
            continue
        # parse: "  1000:XXXX  INSTR  OPERANDS"
        m = re.match(r'\s+1000:([0-9a-f]+)\s+(\w+)\s*(.*)', line, re.I)
        if not m:
            continue
        addr = m.group(1).lower()
        instr = m.group(2).upper()
        operands_raw = m.group(3).strip()

        # Emit label if this addr is a jump target
        label = ''
        if addr in jump_targets:
            label = f'loc_{addr}:'

        # Convert instruction and operands
        nasm_line = convert_instruction(addr, instr, operands_raw, fn_addrs, jump_targets, EXTERN_CALLS)
        if label:
            out.append(label)
        if nasm_line:
            out.append('    ' + nasm_line)
    return out

def convert_instruction(addr, instr, operands_raw, fn_addrs, jump_targets, extern_calls):
    ops = [o.strip() for o in split_operands(operands_raw)]

    def fix_op(op):
        return convert_operand(op)

    # Handle jumps and calls
    if instr in ('JMP', 'JZ', 'JNZ', 'JC', 'JNC', 'JA', 'JAE', 'JB', 'JBE',
                 'JL', 'JLE', 'JG', 'JGE', 'JS', 'JNS', 'JO', 'JNO'):
        if ops and re.match(r'0x1000:([0-9a-f]+)', ops[0], re.I):
            tm = re.match(r'0x1000:([0-9a-f]+)', ops[0], re.I)
            target = tm.group(1).lower()
            nasm_instr = instr.lower()
            # Convert jz/jnz to je/jne for NASM
            nasm_instr = nasm_instr.replace('jz','je').replace('jnz','jne')
            return f'{nasm_instr} loc_{target}'
        return f'{instr.lower()} {", ".join(fix_op(o) for o in ops)}'

    if instr == 'CALL':
        if ops and re.match(r'0x1000:([0-9a-f]+)', ops[0], re.I):
            tm = re.match(r'0x1000:([0-9a-f]+)', ops[0], re.I)
            target = tm.group(1).lower()
            if target in extern_calls:
                return f'call near {extern_calls[target]}_'
            elif target in fn_addrs:
                return f'call near loc_{target}'
            else:
                return f'call near loc_{target}  ; unresolved'
        return f'call {fix_op(ops[0]) if ops else ""}'

    if instr == 'CALLF':
        # Far call - convert to call with segment info comment
        if ops and re.match(r'0x1000:([0-9a-f]+)', ops[0], re.I):
            tm = re.match(r'0x1000:([0-9a-f]+)', ops[0], re.I)
            target = tm.group(1).lower()
            if target in extern_calls:
                return f'call far {extern_calls[target]}_  ; CALLF'
            return f'call far loc_{target}  ; CALLF'
        return f'call far {ops[0]}  ; CALLF'

    if instr == 'RET':
        return 'ret'
    if instr == 'RETF':
        return 'retf'

    # Swap operand order for MOV and friends (NASM: dest, src)
    if ops:
        converted_ops = ', '.join(fix_op(o) for o in ops)
    else:
        converted_ops = ''

    return f'{instr.lower()} {converted_ops}'.strip()

def split_operands(s):
    """Split operands by comma, but not inside brackets."""
    parts = []
    depth = 0
    current = []
    for c in s:
        if c == '[':
            depth += 1
            current.append(c)
        elif c == ']':
            depth -= 1
            current.append(c)
        elif c == ',' and depth == 0:
            parts.append(''.join(current).strip())
            current = []
        else:
            current.append(c)
    if current:
        parts.append(''.join(current).strip())
    return parts

if __name__ == '__main__':
    path = '/home/user/BattleChess/decompiled/CHESS_disassembly.asm'
    raw = extract_fn(path, 'Function: FUN_1000_6cb4', '; Function:')
    converted = process_lines(raw)
    for line in converted:
        print(line)
