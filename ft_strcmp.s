global ft_strcmp

ft_strcmp:
	mov		rcx, 0		; i = 0
	mov		rax, 0		; res = 0
	jmp		loop

loop:
	mov		al, byte [rdi + rcx] ; dl <- s1[i]
	mov		bl, byte [rsi + rcx] ; bl <- s2[i]
	cmp		al, 0
	je		exit
	cmp		bl, 0
	je		exit
	cmp		al, bl	; if s1[i] neq s2[i] then exit
	jne		exit
	inc		rcx		; i++;
	jmp		loop

exit:
	movzx	rbx, bl
	movzx	rax, al
	sub		rax, rbx
	ret
