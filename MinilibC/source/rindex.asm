;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;char	*rindex(const char *str, int c);;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
%include "minilib.inc"
;; see man INDEX(3)
;; rindex return a pointer to the last occurence of c in *src
section	.text
_rindex:
rindex:
	XOR	RAX, RAX
.my_strlen:
	CMP	BYTE [RDI], 0x00
	JE	.loop
	INC	RDI
	JMP	.my_strlen
.loop:
	CMP     SIL, 0x00
        JE      .fend
	DEC	RDI
	CMP	BYTE [RDI], SIL
	JE	.fend
	CMP	BYTE [RDI], 0x00
	JE	ret_zero
	JMP	.loop
.fend:
	MOV	RAX, RDI
	JMP	end
