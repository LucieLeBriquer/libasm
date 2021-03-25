global ft_list_push_front
extern __errno_location
extern malloc

ft_list_push_front:							; void	fun(t_list **begin, void *data)
	push	rcx
	push	rdi
	push	rsi
	mov		rdi, 16
	xor		rax, rax
	call	malloc wrt ..plt				; malloc sizeof(t_list)=16
	pop		rsi
	pop		rdi
	test	rax, rax						; if (new == NULL)
	js		error_alloc
	mov		[rax], rsi						; new->data = data
	mov		rcx, [rdi]						; save = *begin
	mov		[rax + 8], rcx					; new->next = save
	mov		[rdi], rax						; *begin = new
	pop		rcx
	ret

error_alloc:
	mov		rbx, rax
	neg		rbx
	call	__errno_location wrt ..plt
	mov		[rax], rbx
	pop		rcx
	ret
