global ft_read
extern __errno_location
extern error

ft_read:
	push	rbx
	mov		rax, 0			; 0 is for sys_read
	syscall
	test	rax, rax		; check if rax is negative (error occured)
	js		error_read		; if error, exit and ret -1
	pop		rbx
	ret

error_read:
	mov		rbx, rax
	neg		rbx
	call	__errno_location wrt ..plt
	mov		[rax], rbx
	mov		rax, -1
	pop		rbx
	ret
