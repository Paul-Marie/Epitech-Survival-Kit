.TEXT
.GLOBL test

string:
.ASCII "HELLO WORLD\n"
.EQU	NUL, 0

.ALIGN
test:
	LDR	%R0, =string
	MOV	%R1, #0

.loop:
	LDRB	%R2, [%R0], #1
	ADD	%R1, %R1, #1
	CMP	%R2, #NUL
	BNE	.loop
	SUB	%R1, %R1, #1
.end:
	B	.end
