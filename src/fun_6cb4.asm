; fun_6cb4.asm - FUN_1000_6cb4 @ 1000:6cb4
; Translated from Ghidra disassembly - not decompiled to C by Ghidra.
; This function decodes encrypted chess position/move data from a far-pointer
; region and formats it for display (algebraic notation generation).
;
; Build: nasm -f obj -o build/fun_6cb4.obj src/fun_6cb4.asm
;
; Watcom 16-bit cdecl convention (trailing underscore on exported symbols)

BITS 16
CPU 8086

; External near functions called by this function
EXTERN FUN_1000_ecaa_
EXTERN FUN_1000_0fb0_
EXTERN FUN_1000_ca56_
EXTERN FUN_1000_cb5b_
EXTERN FUN_1000_e03a_
EXTERN FUN_1000_e197_
EXTERN FUN_1000_1780_
EXTERN FUN_1000_f2f0_
EXTERN FUN_1000_e915_
EXTERN FUN_1000_1064_
EXTERN FUN_1000_58b0_
EXTERN FUN_1000_102d_

GLOBAL FUN_1000_6cb4_

SEGMENT _TEXT CLASS=CODE PUBLIC USE16

FUN_1000_6cb4_:
    push BP
    mov BP, SP
    mov AX, 0x3e
    call near FUN_1000_ecaa_
    push DI
    push SI
    mov word [BP + -0x4], 0x0
    call near FUN_1000_0fb0_
    sub AX, AX
    push AX
    call near FUN_1000_ca56_
    add SP, 0x2
    les BX, [0x9648]
    push word [es:BX + 0x16]
    push word [es:BX + 0x14]
    call near FUN_1000_cb5b_
    add SP, 0x4
    call near FUN_1000_e03a_
    mov AX, 0x7d00
    cwd
    push DX
    push AX
    mov AX, 0x0
    mov DX, 0x1f09
    push DX
    push AX
    call near FUN_1000_e197_
    add SP, 0x8
loc_6cf9:
    push word [0x8dde]
    mov AX, 0x77
    push AX
    mov AX, 0x12f
    push AX
    mov AX, 0x50
    push AX
    mov AX, 0x10
    push AX
    call near FUN_1000_1780_
    add SP, 0xa
    lea AX, [BP + -0x3c]
    mov [0x5c8], AX
    mov AL, [0x8d22]
    mov [0x5c6], AL
    mov AL, [0x8dde]
    mov [0x5c7], AL
    call near FUN_1000_f2f0_
    cwd
    mov CX, 0x204f
    idiv CX
    mov word [BP + -0x3e], DX
    mov word [BP + -0x2], 0x8f46
    mov AX, 0xf08
    mov word [BP + -0x8], AX
    mov word [BP + -0x6], DS
    sub SI, SI
    jmp loc_6d44
loc_6d43:
    inc SI
loc_6d44:
    cmp SI, 0x48
    jge loc_6d7a
    mov BX, word [BP + -0x2]
    add word [BP + -0x2], 0x2
    mov AX, word [BP + -0x8]
    mov word [BX], AX
loc_6d55:
    les BX, [BP + -0x8]
    cmp byte [es:BX], 0xff
    je loc_6d6c
    add word [BP + -0x8], 0x1
    sbb AX, AX
    and AX, 0x1000
    add word [BP + -0x6], AX
    jmp loc_6d55
loc_6d6c:
    add word [BP + -0x8], 0x1
    sbb AX, AX
    and AX, 0x1000
    add word [BP + -0x6], AX
    jmp loc_6d43
loc_6d7a:
    mov BX, word [BP + -0x3e]
    lea AX, [BX + 0x0]
    mov DX, 0x1f09
    mov word [BP + -0x8], AX
    mov word [BP + -0x6], DX
loc_6d8a:
    les BX, [BP + -0x8]
    cmp byte [es:BX], 0x2a
    je loc_6da3
    add word [BP + -0x8], -0x1
    sbb AX, AX
    not AX
    and AX, 0x1000
    sub word [BP + -0x6], AX
    jmp loc_6d8a
loc_6da3:
    add word [BP + -0x8], 0x1
    sbb AX, AX
    and AX, 0x1000
    add word [BP + -0x6], AX
    lea AX, [BP + -0x3c]
    mov word [BP + -0xc], AX
    mov word [BP + -0xa], SS
loc_6db8:
    les BX, [BP + -0x8]
    add word [BP + -0x8], 0x1
    jnc loc_6dc6
    add word [BP + -0x6], 0x1000
loc_6dc6:
    mov AL, byte [es:BX]
    xor AL, 0x6a
    les BX, [BP + -0xc]
    add word [BP + -0xc], 0x1
    jnc loc_6dd9
    add word [BP + -0xa], 0x1000
loc_6dd9:
    mov byte [es:BX], AL
    les BX, [BP + -0x8]
    cmp byte [es:BX], 0x46
    jne loc_6db8
    add word [BP + -0x8], 0x1
    jnc loc_6df0
    add word [BP + -0x6], 0x1000
loc_6df0:
    mov AL, byte [es:BX]
    xor AL, 0x6a
    les BX, [BP + -0xc]
    add word [BP + -0xc], 0x1
    jnc loc_6e03
    add word [BP + -0xa], 0x1000
loc_6e03:
    mov byte [es:BX], AL
    les BX, [BP + -0xc]
    mov byte [es:BX], 0x0
    mov AX, 0x58
    push AX
    mov AX, 0x18
    push AX
    mov AX, 0x5c6
    push AX
    call near FUN_1000_e915_
    add SP, 0x6
    lea AX, [BP + -0x3c]
    mov word [BP + -0xc], AX
    mov word [BP + -0xa], SS
    add word [BP + -0x8], 0x1
    sbb AX, AX
    and AX, 0x1000
    add word [BP + -0x6], AX
loc_6e34:
    les BX, [BP + -0x8]
    cmp byte [es:BX], 0x67
    je loc_6e60
    add word [BP + -0x8], 0x1
    jnc loc_6e48
    add word [BP + -0x6], 0x1000
loc_6e48:
    mov AL, byte [es:BX]
    xor AL, 0x6a
    les BX, [BP + -0xc]
    add word [BP + -0xc], 0x1
    jnc loc_6e5b
    add word [BP + -0xa], 0x1000
loc_6e5b:
    mov byte [es:BX], AL
    jmp loc_6e34
loc_6e60:
    les BX, [BP + -0xc]
    mov byte [es:BX], 0x0
    add word [BP + -0x8], 0x1
    sbb AX, AX
    and AX, 0x1000
    add word [BP + -0x6], AX
    mov AX, 0x60
    push AX
    mov AX, 0x18
    push AX
    mov AX, 0x5c6
    push AX
    call near FUN_1000_e915_
    add SP, 0x6
    sub SI, SI
    mov AX, word [BP + -0x8]
    mov DX, word [BP + -0x6]
    mov word [BP + -0xc], AX
    mov word [BP + -0xa], DX
loc_6e93:
    mov BX, word [BP + -0x3e]
    lea AX, [BX + 0x0]
    mov DX, 0x1f09
    cmp DX, word [BP + -0x6]
    jc loc_6ecc
    ja loc_6ea9
    cmp AX, word [BP + -0x8]
    jbe loc_6ecc
loc_6ea9:
    les BX, [BP + -0x8]
    add word [BP + -0x8], 0x1
    jnc loc_6eb7
    add word [BP + -0x6], 0x1000
loc_6eb7:
    cmp byte [es:BX], 0x67
    jne loc_6eca
    inc SI
    mov AX, word [BP + -0x8]
    mov DX, word [BP + -0x6]
    mov word [BP + -0xc], AX
    mov word [BP + -0xa], DX
loc_6eca:
    jmp loc_6e93
loc_6ecc:
    mov DI, SI
    sar DI, 0x1
    inc DI
    lea AX, [BP + -0x3c]
    mov word [BP + -0x8], AX
    mov word [BP + -0x6], SS
    cmp DI, 0x9
    jle loc_6efc
    mov AX, DI
    cwd
    mov CX, 0xa
    idiv CX
    add AL, 0x30
    les BX, [BP + -0x8]
    add word [BP + -0x8], 0x1
    jnc loc_6ef7
    add word [BP + -0x6], 0x1000
loc_6ef7:
    mov byte [es:BX], AL
    jmp loc_6f0e
loc_6efc:
    les BX, [BP + -0x8]
    add word [BP + -0x8], 0x1
    jnc loc_6f0a
    add word [BP + -0x6], 0x1000
loc_6f0a:
    mov byte [es:BX], 0x20
loc_6f0e:
    mov AX, DI
    cwd
    mov CX, 0xa
    idiv CX
    add DL, 0x30
    les BX, [BP + -0x8]
    add word [BP + -0x8], 0x1
    jnc loc_6f27
    add word [BP + -0x6], 0x1000
loc_6f27:
    mov byte [es:BX], DL
    les BX, [BP + -0x8]
    add word [BP + -0x8], 0x1
    jnc loc_6f38
    add word [BP + -0x6], 0x1000
loc_6f38:
    mov byte [es:BX], 0x2e
    les BX, [BP + -0x8]
    add word [BP + -0x8], 0x1
    jnc loc_6f4a
    add word [BP + -0x6], 0x1000
loc_6f4a:
    mov byte [es:BX], 0x20
    test SI, 0x1
    je loc_6f59
    mov AX, 0x4d96
    jmp loc_6f5c
loc_6f59:
    mov AX, 0x4d9e
loc_6f5c:
    mov word [BP + -0xe], AX
loc_6f5f:
    mov BX, word [BP + -0xe]
    cmp byte [BX], 0x0
    je loc_6f7f
    inc word [BP + -0xe]
    mov AL, byte [BX]
    les BX, [BP + -0x8]
    add word [BP + -0x8], 0x1
    jnc loc_6f7a
    add word [BP + -0x6], 0x1000
loc_6f7a:
    mov byte [es:BX], AL
    jmp loc_6f5f
loc_6f7f:
    les BX, [BP + -0x8]
    mov byte [es:BX], 0x0
    les BX, [BP + -0x8]
    mov AL, 0x48
    mul byte [es:BX]
    add AX, 0x8c6e
    mov word [BP + -0x2], AX
    mov AX, [0x53f8]
    mov word [BP + -0x8], AX
    mov word [BP + -0x6], DS
    sub SI, SI
    jmp loc_6fa2
loc_6fa1:
    inc SI
loc_6fa2:
    cmp SI, 0x48
    jge loc_6fd8
    mov BX, word [BP + -0x2]
    add word [BP + -0x2], 0x2
    mov AX, word [BP + -0x8]
    mov word [BX], AX
loc_6fb3:
    les BX, [BP + -0x8]
    cmp byte [es:BX], 0xff
    je loc_6fca
    add word [BP + -0x8], 0x1
    sbb AX, AX
    and AX, 0x1000
    add word [BP + -0x6], AX
    jmp loc_6fb3
loc_6fca:
    add word [BP + -0x8], 0x1
    sbb AX, AX
    and AX, 0x1000
    add word [BP + -0x6], AX
    jmp loc_6fa1
loc_6fd8:
    mov AX, 0x68
    push AX
    mov AX, 0x18
    push AX
    mov AX, 0x5c6
    push AX
    call near FUN_1000_e915_
    add SP, 0x6
    sub AX, AX
    push AX
    mov AX, 0xa
    push AX
    lea AX, [BP + -0x3c]
    push AX
    mov AX, 0x68
    push AX
    mov AX, 0x70
    push AX
    call near FUN_1000_1064_
    add SP, 0xa
    lea AX, [BP + -0x3c]
    mov word [BP + -0x8], AX
    mov word [BP + -0x6], SS
loc_700c:
    les BX, [BP + -0xc]
    mov AL, byte [es:BX]
    sub AH, AH
    xor AL, 0x6a
    or AL, 0x20
    les BX, [BP + -0x8]
    mov CL, byte [es:BX]
    sub CH, CH
    or CL, 0x20
    cmp AX, CX
    jne loc_7041
    add word [BP + -0x8], 0x1
    sbb AX, AX
    and AX, 0x1000
    add word [BP + -0x6], AX
    add word [BP + -0xc], 0x1
    sbb AX, AX
    and AX, 0x1000
    add word [BP + -0xa], AX
    jmp loc_700c
loc_7041:
    les BX, [BP + -0x8]
    cmp byte [es:BX], 0x0
    jne loc_7053
    les BX, [BP + -0xc]
    cmp byte [es:BX], 0x67
    jmp loc_7061
loc_7053:
    mov AX, word [BP + -0x4]
    inc word [BP + -0x4]
    cmp AX, 0x2
    jge loc_7061
    jmp loc_6cf9
loc_7061:
    mov AX, 0x77
    push AX
    mov AX, 0x50
    push AX
    mov AX, 0x4b
    push AX
    mov AX, 0x4
    push AX
    call near FUN_1000_58b0_
    add SP, 0x8
    les BX, [BP + -0x8]
    cmp byte [es:BX], 0x0
    nop
    nop
    les BX, [BP + -0xc]
    cmp byte [es:BX], 0x67
    jmp loc_708d
loc_708d:
    les BX, [BP + -0x8]
    mov AL, 0x30
    mul byte [es:BX]
    add AX, 0x8e24
    mov word [BP + -0x2], AX
    mov AL, byte [es:BX]
    sub AH, AH
    add AX, word [0x8ae4]
    mov word [BP + -0x8], AX
    mov word [BP + -0x6], DS
    sub SI, SI
    jmp loc_70af
loc_70ae:
    inc SI
loc_70af:
    cmp SI, 0x90
    jge loc_70e6
    mov BX, word [BP + -0x2]
    add word [BP + -0x2], 0x2
    mov AX, word [BP + -0x8]
    mov word [BX], AX
loc_70c1:
    les BX, [BP + -0x8]
    cmp byte [es:BX], 0xff
    je loc_70d8
    add word [BP + -0x8], 0x1
    sbb AX, AX
    and AX, 0x1000
    add word [BP + -0x6], AX
    jmp loc_70c1
loc_70d8:
    add word [BP + -0x8], 0x1
    sbb AX, AX
    and AX, 0x1000
    add word [BP + -0x6], AX
    jmp loc_70ae
loc_70e6:
    call near FUN_1000_102d_
    pop SI
    pop DI
    mov SP, BP
