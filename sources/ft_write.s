global ft_write
extern __errno_location

ft_write:
	mov		rax, 1			; 1 is for sys_write
	syscall
	test	rax, rax
	js		error_write		; if error, exit and ret -1
	ret

error_write:
	push	rbx
	mov		rbx, rax
	neg		rbx
	call	__errno_location wrt ..plt		; put in rax the location of errno
	mov		[rax], rbx						; put the sys_error in errno
	mov		rax, -1
	pop		rbx
	ret
