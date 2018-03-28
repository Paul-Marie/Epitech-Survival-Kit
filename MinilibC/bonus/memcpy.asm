;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;char  *memcpy(void *dest, const void *src, size_t n);;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
%include "32lib.inc"
;; see man MEMCPY(3)
;; memcpy copy n *src into *dest
section	.text
_memcpy:
memcpy:
	XOR	ECX, ECX
	MOV	EAX, EDI
.loop:
	CMP	ECX, EDX
	JE	end
	MOV	EDX, [ESI]
	MOV	[EAX], EDX
	INC	ESI
	INC	EAX
	JMP	.loop
