global ft_list_remove_if
extern free

;void	remove_aux(t_list *prev = r11, t_list **suppr = r10, void (*free_fct)(void *) = rcx)
remove_aux:
	push	r13
	push	r14
	push	r15

	mov		r15, [r10]			; r12 = *suppr
	mov		r13, [r15 + 8]		; r10 = (*suppr)->next
	mov		r14, [r15]			; r11 = (*suppr)->data

	push	rdi
	mov		rdi, r14
	call	rcx
	pop		rdi					; (*free_fct)((*suppr)->data);

	push	rdi
	mov		rdi, r15
	call	free
	pop		rdi					; free(*suppr);

	mov		[rdi + 8], r13		; prev->next = save;

	mov		r10, r11			; *suppr = prev;
	
	pop		r15
	pop		r14
	pop		r13
	jmp		loop1


loop0:
	test	r10, r10		; test if curr(r10) == 0
	js		end_loop0
	mov		r11, [r10 + 8]	; r11 = curr->data
	
	push	rdi
	mov		r11, rdi
	call	r14
	pop		rdi				; (*cmp)(curr->data, data_ref)

	test	rax, rax
	js		end_loop0

	mov		r12, [r10 + 8]	; save(r12) = curr->next
	
	push	rdi
	mov		rdi, r11
	call	r15
	pop		rdi				; (*free_fct)(curr->data);
	
	push	rdi
	mov		rdi, r10
	call	free
	pop		rdi				; free(curr);

	mov		r10, r12		; curr = save;

	jmp		loop0

loop1:
	test	r10, r10		; if (curr == 0)
	js		end_loop1

	mov		r11, [r10 + 8]	; r11 = curr->next
	test	r11, r11
	js		end_loop1

	mov		r12, r10		; prev(r12) = curr(r10)
	mov		r11, [r10 + 8]	; r11 = curr->next
	mov		r10, r11		; curr = curr->next;

	push	rdi
	mov		rdi, [r10 + 8]	; rdi = curr->data
	call	rdx
	pop		rdi				; (*cmp)(curr->data, data_ref)

	test	rax, rax
	js		remove_aux		; remove_aux(prev, &curr, free_fct);

	jmp		loop1
	

;void	ft_list_remove_if(t_list **begin_list = rdi, void *data_ref = rsi, 
;							int (*cmp)() = rdx, void (*free_fct)(void *) = rcx)
ft_list_remove_if:
	push	r10
	push	r11
	push	r12
	push	r13
	push	r14
	push	r15

	mov		r13, rsi
	mov		r14, rdx
	mov		r15, rcx
	mov		r10, [rdi]		; curr(r10) = *begin_list
	jmp		loop0
end_loop0:
	mov		[rdi], r10		; *begin_list = curr;

	jmp		loop1
end_loop1:
	jmp		exit

exit:
	pop		r15
	pop		r14
	pop		r13
	pop		r12
	pop		r11
	pop		r10
	ret
