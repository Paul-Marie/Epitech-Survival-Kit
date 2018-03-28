;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;char	*strcmp(const char *str1, const char *str2);;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
%include "minilib.inc"
;; see man STRCASECMP(3)
;; perform a strcmp avoiding case
section	.text
_strcasecmp:
strcasecmp:
	XOR	RAX, RAX
	XOR	RCX, RCX
	XOR	R8, R8
	CMP	BYTE [RSI + RCX], 0x00
	JE	.empty_rsi

.loop:
	MOV	AL, BYTE [RDI + RCX]
	MOV	R8B, BYTE [RSI + RCX]
	CMP	AL, 0x00
	JE	.fend
	CMP	R8B, 0x00
	JE	.fend
	CMP	AL, "Z"
	JLE	.lower

.check_r8:
	CMP	R8B, "Z"
	JLE	.lower_r8
.check_diff:
	CMP	AL, R8B
	JNE	.fend
	INC	RCX
	JMP	.loop

.lower:
	CMP	AL, "A"
	JGE	.addicant
	JMP	.check_r8
.addicant:
	ADD	RAX, 32
	JMP	.check_r8

.lower_r8:
	CMP	R8B, "A"
	JGE	.addicant_r8
	JMP	.check_diff
.addicant_r8:
	ADD	R8, 32
	JMP	.check_diff

.ret_greater:
	MOV	AL, [RDI + RCX]
	ADD	AL, 32
	JMP	end
.ret_lower:
	CMP	BYTE [RDI + RCX], "A"
	JGE	.ret_greater
	JMP	.ret_rdi_value

.empty_rsi:
	CMP	BYTE [RDI + RCX], "Z"
	JLE	.ret_lower
	JMP	.ret_rdi_value

.fend:
	SUB	AL, R8B
	MOVSX	RAX, AL
	JMP	end
.ret_rdi_value:
	MOV	AL, BYTE [RDI + RCX]
	JMP	end
