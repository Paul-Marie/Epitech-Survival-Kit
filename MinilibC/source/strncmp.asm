;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;char	*strncmp(const char *str1, const char *str2, int n);;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
%include "minilib.inc"
;; see man STRCMP(3)
;; compare n first *str1 char and return 0 if *str1 and *str2 are equal,
;; or negative ascii value if str1 is found,
;; or positive ascii value if str2 is found
section	.text
_strncmp:
strncmp:
	XOR	RCX, RCX
	XOR	RAX, RAX
	XOR	R8, R8
.loop:
	MOV	AL, BYTE [RDI + RCX]
	MOV	R8B, BYTE [RSI + RCX]
	CMP	RCX, RDX
	JE	ret_zero
	CMP	R8, 0x00
	JE	.fend
	CMP	AL, R8B
	JNE	.fend
	CMP	RAX, 0x00
	JE	.fend
	INC	RCX
	JMP	.loop
.fend:
	SUB	AL, R8B
	MOVSX	RAX, AL
	JMP	end
