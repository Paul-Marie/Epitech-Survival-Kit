.DATA

msg:
.ASCII "Hello World!\n"
len = . - msg

.TEXT
.GLOBL _start
_start:
	MOV	%R0, #1
	LDR	%R1, =msg
	LDR	%R2, =len
	MOV	%R7, #4
	SWI	#0

	MOV	%R0, #0
	MOV	%R7, #1
	SWI	#0

	B	test
