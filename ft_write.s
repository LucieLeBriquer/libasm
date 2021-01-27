global ft_write

ft_write:
	mov		rax, 1			; 1 is for sys_write
	syscall
	test	rax, rax		; check if rax is negative (error occured)
	js		error			; if error, exit and ret -1
	ret

error:
	mov		rax, -1
	ret
