.GLOBL strlen
.TEXT
strlen:
	LDRB    R3, [R0]
	CMP     R3, #0
	BEQ    .end
	MOV     R3, R0
	MOV     R0, #0
.loop:
	LDRB    R2, [R3, #1]!
	ADD     R0, R0, #1
	CMP     R2, #0
	BNE     .loop
	BX	LR
.end:
	MOV     R0, R3
	BX	LR
