global ft_read

ft_read:
	mov		rax, 0			; 0 is for sys_read
	syscall
	test	rax, rax		; check if rax is negative (error occured)
	js		error			; if error, exit and ret -1
	ret

error:
	mov		rax, -1
	ret
