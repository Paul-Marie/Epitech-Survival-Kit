;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;char	*strcmp(const char *str1, const char *str2);;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
%include "32lib.inc"
;; see man STRCMP(3)
;; return 0 if *str1 and *str2 are equal, or negative ascii value if str1 is found,
;; or positive ascii value if str2 is found
section	.text
_strcmp:
strcmp:
	XOR	ECX, ECX
	XOR	EDX, EDX
.loop:
	MOV	EAX, [EDI + ECX]
	MOV	EDX, [ESI + ECX]
	CMP	EAX, 0x00
	JE	.fend
	CMP	EDX, 0x00
	JE	.fend
	CMP	EAX, EDX
	JNE	.fend
	INC	ECX
	JMP	.loop
.fend:
	SUB	EAX, EDX
	MOVSX	EAX, AL
	JMP	end
