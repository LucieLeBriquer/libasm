global ft_strcmp

ft_strcmp:
	mov		rcx, 0	; i = 0
	mov		rax, 0	; res = 0
	jmp		loop

loop:
	mov		al, byte [rdi + rcx] ; al <- s1[i]
	mov		bl, byte [rsi + rcx] ; bl <- s2[i]
	cmp		al, 0
	je		exit
	cmp		bl, 0
	je		exit
	sub		al, bl	; res = s1[i] - s2[i]
	cmp		al, 0	; if neq 0 then exit
	jne		exit
	inc		rcx		; i++;
	jmp		loop

exit:
	ret
