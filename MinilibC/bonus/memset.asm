;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;char  *memset(void *s, int c, size_t n);;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
%include "minilib.inc"
;; see man MEMSET(3)
;; copy n time c in *s
section	.text
_memset:
memset:
	XOR	ECX, ECX
	MOV	EAX, EDI
.loop:
	CMP	ECX, EDX
	JE	end
	MOV	[EAX + ECX], ESI
	INC	ECX
	JMP	.loop
