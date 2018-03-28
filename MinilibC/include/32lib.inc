BITS	32

GLOBAL	strcasecmp:function
GLOBAL	strpbrk:function
GLOBAL	strcspn:function
GLOBAL	strncmp:function
GLOBAL	strlen:function
GLOBAL	strcmp:function
GLOBAL	strstr:function
GLOBAL	strchr:function
GLOBAL	rindex:function
GLOBAL	memcpy:function
GLOBAL	memset:function
GLOBAL	memmove:function
GLOBAL	write:function
GLOBAL	read:function

GLOBAL	_strcasecmp:function
GLOBAL	_strpbrk:function
GLOBAL	_strcspn:function
GLOBAL	_strncmp:function
GLOBAL	_strlen:function
GLOBAL	_strcmp:function
GLOBAL	_strstr:function
GLOBAL	_strchr:function
GLOBAL	_rindex:function
GLOBAL	_memcpy:function
GLOBAL	_memset:function
GLOBAL	_memmove:function
GLOBAL	_write:function
GLOBAL	_read:function

ret_rdi:
	MOV	EAX, EDI
	RET

ret_rsi:
	MOV	EAX, ESI
	RET

ret_zero:
	MOV	EAX, 0x00
	RET

end:
	RET
