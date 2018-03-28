;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;char  *strlen(const char *str);;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
%include "32lib.inc"
;;//BITS	32
;; see man STRLEN(3)
;; strlen return str's length
section	.text
_strlen:
strlen:
	XOR	EAX, EAX
	CMP	BYTE [EDI], 0x00
	JE	.end
	JMP	.loop
.loop:
	INC	EAX
	INC	EDI
	CMP	BYTE [EDI], 0x00
	JNE	.loop
	JMP	.end
.end:
	RET
