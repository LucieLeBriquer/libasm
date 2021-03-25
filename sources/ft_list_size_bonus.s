global ft_list_size

ft_list_size:
	push	rcx
	xor		rcx, rcx				; i = 0
	jmp		loop

loop:
	cmp		rdi, 0					; if begin == NULL
	je		exit
	inc		rcx						; i++
	mov		rdi, [rdi + 8]			; begin = begin->next
	jmp		loop

exit:
	mov		rax, rcx				; return (i)
	pop		rcx
	ret
