; stack.asm - declares the DOS stack segment for Battle Chess
; Original EXE: SS=0x143e (same segment as entry), SP=0x0521
; In small model (single segment), we declare a STACK segment so wlink
; can set SS:SP correctly in the MZ header.
;
; 0x600 = 1536 bytes of stack (slightly larger than original 0x521 = 1313 bytes)

BITS 16
CPU 8086

SEGMENT STACK STACK USE16 ALIGN=16
    resb 0x600
