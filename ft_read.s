global ft_read
extern __errno_location

ft_read:
	push	rbx
	mov		rax, 0			; 0 is for sys_read
	syscall
	test	rax, rax		; check if rax is negative (error occured)
	js		error			; if error, exit and ret -1
	pop		rbx
	ret

error:
	mov		rbx, rax
	neg		rbx
	call	__errno_location
	mov		[rax], rbx
	mov		rax, -1
	pop		rbx
	ret
