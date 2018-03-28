;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;char	*strpbrk(const char *str1, const char *str2);;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
%include "32lib.inc"
;; see man STRBRK(3)
;; return a pointer to the first occurence of str1 in str2
section	.text
_strpbrk:
strpbrk:
	XOR 	ECX, ECX
	XOR	EDX, EDX
.loop:
	MOV	EAX, [EDI + ECX]
	CMP	EAX, 0x00
	JE	ret_zero
	INC	ECX
.search:
	XOR	EBX, EBX
.loop_sub:
	MOV	EDX, [ESI + EBX]
	CMP	EDX, 0x00
	JE	.loop
	CMP	EAX, EDX
	JE	.fend
	INC	EBX
	JMP	.loop_sub
.fend:
	SUB	ECX, 1
	ADD	EDI, ECX
	MOV	EAX, EDI
	JMP	end
.zend:
	MOV	EAX, 0x00
	JMP	end
