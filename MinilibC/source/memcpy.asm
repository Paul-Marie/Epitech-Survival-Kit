;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;char  *memcpy(void *dest, const void *src, size_t n);;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
%include "minilib.inc"
;; see man MEMCPY(3)
;; memcpy copy n *src into *dest
section	.text
_memcpy:
memcpy:
	XOR	RCX, RCX
	MOV	RAX, RDI
.loop:
	CMP	RCX, RDX
	JE	end
	MOV	R8B, BYTE [RSI + RCX]
	MOV	BYTE [RAX + RCX], R8B
	INC	RCX
	JMP	.loop
