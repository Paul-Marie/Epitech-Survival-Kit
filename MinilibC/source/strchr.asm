;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;char	*strchr(const char *str, int c);;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
%include "minilib.inc"
;; see man STRCHR(3)
;; return a pointer to the first occurence of c in *str
section	.text
_strchr:
strchr:
	XOR	RAX, RAX
.loop:	
	CMP	BYTE [RDI], SIL
	JE	.fend
	CMP	BYTE [RDI], 0x00
	JE	ret_zero
	INC	RDI
	JMP	.loop
.fend:
	MOV	RAX, RDI
	JMP	end
