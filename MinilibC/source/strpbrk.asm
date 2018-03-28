;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;char	*strpbrk(const char *str1, const char *str2);;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
%include "minilib.inc"
;; see man STRBRK(3)
;; return a pointer to the first occurence of str1 in str2
section	.text
_strpbrk:
strpbrk:
	XOR 	RCX, RCX
	XOR	R8, R8
.loop:
	MOV	AL, BYTE [RDI + RCX]
	CMP	AL, 0x00
	JE	ret_zero
	INC	RCX
.search:
	XOR	R9, R9
.loop_sub:
	MOV	R8B, BYTE [RSI + R9]
	CMP	R8B, 0x00
	JE	.loop
	CMP	AL, R8B
	JE	.fend
	INC	R9
	JMP	.loop_sub
.fend:
	SUB	RCX, 1
	ADD	RDI, RCX
	MOV	RAX, RDI
	JMP	end
.zend:
	MOV	RAX, 0x00
	JMP	end
