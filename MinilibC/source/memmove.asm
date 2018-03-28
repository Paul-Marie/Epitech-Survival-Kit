;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;char  *memmove(void *dest, const void *src, size_t n);;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
%include "minilib.inc"
;; see man MEMMOVE(3)
;; memmove is like memcpy but deal with overlap
section	.text
_memmove:
memmove:
	PUSH	RBP
	MOV	RBP, RSP
	XOR	RCX, RCX
	XOR	R8, R8
	SUB	RSP, RDX
	CMP	RDX, 0x00
	JE	.ret_rdi
.loop:
	MOV	R8, QWORD [RSI + RCX]
	MOV	BYTE [RSP + RCX], R8B
	INC	RCX
	CMP	RCX, RDX
	JNE	.loop
	MOV	RSI, RSP
	CALL	.memcpy
	JMP	.fend
.memcpy:
	XOR	RCX,  RCX
	MOV	RAX, RDI
.memloop:
	CMP	RCX, RDX
	JE	.fend
	MOV	R8B, BYTE [RSI + RCX]
	MOV	BYTE [RAX + RCX], R8B
	INC	RCX
	JMP	.memloop
.ret_rdi:
	MOV	RAX, RDI
.fend:
	MOV	RSP, RBP
	POP	RBP
	JMP	end
