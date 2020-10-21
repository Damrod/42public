global ft_strlen
ft_strlen:
		cmp		byte [rdi], 0
		jz		L_002
		mov		rax, rdi
L_001:	add		rax, 1
		cmp		byte [rax], 0
		jnz		L_001
		sub		rax, rdi
		ret
L_002:	xor		eax, eax
		ret