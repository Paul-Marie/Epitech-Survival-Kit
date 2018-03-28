;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;char	*strpbrk(const char *str1, const char *str2);;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
%include "minilib.inc"
;; see man STRSPN(3)
;; return the lenght of *str1 wich contain only char of *str2
section	.text
_strcspn:
strcspn:
	XOR 	ECX, ECX
	XOR	EDX, EDX
.loop:
	MOV	EAX, [EDI + ECX]
	CMP	EAX, 0x00
	JE	.zend
	INC	ECX
.search:
	XOR	EBP, EBP
.loop_sub:
	MOV	EDX, [ESI + EBP]
	CMP	EDX, 0x00
	JE	.loop
	CMP	EAX, EDX
	JE	.fend
	INC	EBP
	JMP	.loop_sub
.fend:
	SUB	ECX, 1
	MOV	EAX, ECX
	JMP	end
.zend:
	MOV	EAX, ECX
	JMP	end
