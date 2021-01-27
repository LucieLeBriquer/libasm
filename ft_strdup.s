global ft_strdup
extern malloc, ft_strlen, ft_strcpy

ft_strdup:
	call	ft_strlen
	add		rax, 1
	mov		rsi, rdi		; save src pointer in rsi
	mov		rdi, rax
	call	malloc			; new pointer is in rax
	mov		rdi, rax
	call	ft_strcpy
	ret
