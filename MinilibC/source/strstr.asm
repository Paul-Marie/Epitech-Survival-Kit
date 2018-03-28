;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;char	*strcmp(const char *str1, const char *str2);;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
%include "minilib.inc"
;; see man STRSTR(3)
;; return a pointer of the first occurrence of *str2 in the string *str1
section	.text
_strstr:
strstr:
	XOR	RCX, RCX
	MOV	AL, BYTE [RDI]
	CMP	AL, 0x00
	JE	.full_null
.main:
	XOR	R9, R9
	MOV	AL, BYTE [RDI + RCX]
	MOV	R8B, BYTE [RSI + R9]
	CMP	AL, 0x00
	JE	ret_zero
	CMP	R8B, 0x00
	JE	ret_rdi
	MOV	R10, RCX
	INC	RCX
	CMP	AL, R8B
	JE	.loop
	JMP	.main
.loop:
	MOV	AL, BYTE [RDI + R10]
	MOV	R8B, BYTE [RSI + R9]
	CMP	AL, 0x00
	JE	.fend
	CMP	R8B, 0x00
	JE	.ret_value
	INC	R9
	INC	R10
	CMP	AL, R8B
	JNE	.main
	JMP	.loop
.full_null:
	MOV	R8B, BYTE [RSI]
	CMP	R8B, 0x00
	JE	ret_rdi
	JMP	.main
.fend:
	CMP	BYTE [RSI + R9], 0x00
	JNE	.inverse
	SUB	RCX, 1
	ADD	RDI, RCX
	MOV	RAX, RDI
	JMP	end
.ret_value:
	SUB	RCX, 1
	ADD	RDI, RCX
	MOV	RAX, RDI
	JMP	end
.inverse:
	MOV	RAX, 0
	JMP	end
