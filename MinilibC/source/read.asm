;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;size_t read(int fd, void *buf, size_t count);;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
%include "minilib.inc"

segment .text
_read:
read:
	MOV	RAX , 0x00
	SYSCALL
	JMP	end
