global ft_strcmp

ft_strcmp:
	push	rcx
	push	rbx
	xor		rcx, rcx				; i = 0
	xor		rax, rax				; res = 0
	jmp		loop0

loop0:
	mov		al, byte [rdi + rcx]	; al <- s1[i]
	mov		bl, byte [rsi + rcx]	; bl <- s2[i]
	cmp		al, 0
	je		exit
	cmp		bl, 0
	je		exit
	cmp		al, bl					; if s1[i] neq s2[i] then exit
	jne		exit
	inc		rcx						; i++;
	jmp		loop0

exit:
	movzx	rbx, bl
	movzx	rax, al
	sub		rax, rbx
	pop		rbx
	pop		rcx
	ret
