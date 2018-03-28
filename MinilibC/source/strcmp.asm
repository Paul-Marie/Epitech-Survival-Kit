;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;char	*strcmp(const char *str1, const char *str2);;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
%include "minilib.inc"
;; see man STRCMP(3)
;; return 0 if *str1 and *str2 are equal, or negative ascii value if str1 is found,
;; or positive ascii value if str2 is found
section	.text
_strcmp:
strcmp:
	XOR	RCX, RCX
	XOR	R8, R8
.loop:
	MOV	AL, BYTE [RDI + RCX]
	MOV	R8B, BYTE [RSI + RCX]
	CMP	RAX, 0x00
	JE	.fend
	CMP	R8, 0x00
	JE	.fend
	CMP	AL, R8B
	JNE	.fend
	INC	RCX
	JMP	.loop
.fend:
	SUB	AL, R8B
	MOVSX	RAX, AL
	JMP	end
