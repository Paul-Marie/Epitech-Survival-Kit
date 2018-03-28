;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;char	*strpbrk(const char *str1, const char *str2);;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
%include "minilib.inc"
;; see man STRSPN(3)
;; return the lenght of *str1 wich contain only char of *str2
section	.text
_strcspn:
strcspn:
	XOR 	RCX, RCX
	XOR	R8, R8
.loop:
	MOV	AL, BYTE [RDI + RCX]
	CMP	AL, 0x00
	JE	.zend
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
	MOV	RAX, RCX
	JMP	end
.zend:
	MOV	RAX, RCX
	JMP	end
