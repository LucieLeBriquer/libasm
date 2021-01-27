global ft_strlen

ft_strlen:
	xor		rcx, rcx				; i = 0
	jmp		loop

loop:
	cmp		byte [rdi + rcx], 0		; s[i] neq 0
	je		exit
	inc		rcx						; i++
	jmp		loop

exit:
	mov		rax, rcx				; return (i)
	ret
