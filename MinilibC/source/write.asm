;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;size_t read(int fd, void *buf, size_t count);;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
%include "minilib.inc"

segment .text
_write:
write:
	MOV	RAX , 0x01
	SYSCALL
	JMP	end
