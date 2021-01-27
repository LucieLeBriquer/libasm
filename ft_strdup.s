global ft_strdup
extern malloc
extern __errno_location
extern ft_strlen
extern ft_strcpy

ft_strdup:
	push	rbx
	push	rdi
	push	rsi
	call	ft_strlen			; rax = len
	add		rax, 1				; rax = len + 1
	mov		rbx, rdi			; rbx = src
	mov		rdi, rax			; put len in rdi for malloc 
	call	malloc wrt ..plt
	test	rax, rax
	js		error_dup
	mov		rdi, rax			; rdi = dest
	mov		rsi, rbx
	call	ft_strcpy
	pop		rsi
	pop		rdi
	pop		rbx
	ret

error_dup:
	mov		rbx, rax
	neg		rbx
	call	__errno_location wrt ..plt
	mov		[rax], rbx
	xor		rax, rax			; return (null)
	pop		rsi
	pop		rdi
	pop		rbx
	ret
