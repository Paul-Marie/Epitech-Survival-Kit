;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;char	*rindex(const char *str, int c);;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
%include "32lib.inc"
;; see man INDEX(3)
;; rindex return a pointer to the last occurence of c in *src
section	.text
_rindex:
rindex:
	XOR	EAX, EAX
.my_strlen:
	CMP	BYTE [EDI], 0x00
	JE	.loop
	INC	EDI
	JMP	.my_strlen
.loop:
	CMP     ESI, 0x00
        JE      .fend
	DEC	EDI
	CMP	[EDI], ESI
	JE	.fend
	CMP	BYTE [EDI], 0x00
	JE	ret_zero
	JMP	.loop
.fend:
	MOV	EAX, EDI
	JMP	end
