global ft_write
extern __errno_location

ft_write:
	mov		rax, 1				; 1 is for sys_write
	syscall
	test	rax, rax
	js		error				; if error, exit and ret -1
	ret

error:
	mov		rbx, rax
	neg		rbx
	call	__errno_location	; put in rax the location of errno
	mov		[rax], rbx			; put the sys_error in errno
	mov		rax, -1
	ret
