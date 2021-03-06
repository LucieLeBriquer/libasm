global ft_strcpy

ft_strcpy:
	push	rcx
	push	rdx
	xor		rcx, rcx				; i = 0
	jmp		loop

loop:
	cmp		byte [rsi + rcx], 0		; src[i] = '\0' ?
	je		exit
	mov		dl, byte [rsi + rcx]	; dl <- src[i]
	mov		[rdi + rcx], dl			; dest[i] = dl
	inc		rcx						; i++;
	jmp		loop

exit:
	mov		byte [rdi + rcx], 0		; dest[i] = '\0'
	mov		rax, rdi				; strcpy return dest
	pop		rdx
	pop		rcx
	ret
