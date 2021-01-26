global ft_write
extern ___error

ft_write:
	mov		rbx, rdi		; movs the fd in the right register
	mov		rcx, rsi		; move the string in the right register
	mov		rax, 1			; 1 is for sys_write
	syscall
	test	rax, rax		; check if rax is negative (error occured)
	js		error			; if error, exit and ret -1
	ret

error:
	mov		rax, -1
	ret
