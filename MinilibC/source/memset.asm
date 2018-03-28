;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;char  *memset(void *s, int c, size_t n);;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
%include "minilib.inc"
;; see man MEMSET(3)
;; copy n time c in *s
section	.text
_memset:
memset:
	XOR	RCX, RCX
	MOV	RAX, RDI
.loop:
	CMP	RCX, RDX
	JE	end
	MOV	BYTE [RAX + RCX], SIL
	INC	RCX
	JMP	.loop
