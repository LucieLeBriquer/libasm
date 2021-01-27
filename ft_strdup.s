global ft_strdup
extern malloc
extern ft_strlen
extern ft_strcpy

ft_strdup:
	call	ft_strlen		; rax = len
	add		rax, 1			; rax = len + 1
	mov		rbx, rdi		; rbx = src
	mov		rdi, rax		; put len in rdi for malloc 
	call	malloc			; new pointer is in rax
	test	rax, rax
	js		error
	mov		rdi, rax		; rdi = dest
	mov		rsi, rbx
	call	ft_strcpy
	ret

error:
	xor		rax, rax		; return (null)
	ret
