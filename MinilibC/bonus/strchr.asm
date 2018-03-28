;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;char	*strchr(const char *str, int c);;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
%include "32lib.inc"
;; see man STRCHR(3)
;; return a pointer to the first occurence of c in *str
section	.text
_strchr:
strchr:
	XOR	EAX, EAX
.loop:	
	CMP	[EDI], ESI
	JE	.fend
	CMP	BYTE [EDI], 0x00
	JE	ret_zero
	INC	EDI
	JMP	.loop
.fend:
	MOV	EAX, EDI
	JMP	end
