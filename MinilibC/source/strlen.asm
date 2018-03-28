;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;char  *strlen(const char *str);;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
%include "minilib.inc"
;; see man STRLEN(3)
;; strlen return str's length
section	.text
_strlen:
strlen:
	XOR	RAX, RAX
	CMP	BYTE [RDI], 0x00
	JE	end
	JMP	.loop
.loop:
	INC	RAX
	INC	RDI
	CMP	BYTE [RDI], 0x00
	JNE	.loop
	JMP	end
