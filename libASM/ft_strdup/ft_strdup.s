default rel
global ft_strdup
extern malloc
extern ft_strlen
extern _GLOBAL_OFFSET_TABLE_
SECTION .text	6
ft_strdup:
		push	rbx
		mov		rbx, rdi
		call	ft_strlen
		lea		rdi, [rax+1H]
		call	malloc
		test	rax, rax
		jz		L_003
		movzx	ecx, byte [rbx]
		test	cl, cl
		jz		L_004
		xor		edx, edx
ALIGN	8
L_001:	mov		byte [rax+rdx], cl
		add		rdx, 1
		movzx	ecx, byte [rbx+rdx]
		test	cl, cl
		jnz		L_001
		add		rdx, rax
L_002:	mov		byte [rdx], 0
L_003:	pop		rbx
		ret
ALIGN	8
L_004:	mov		rdx, rax
		jmp		L_002
SECTION .data
SECTION .bss
SECTION .note.gnu.property align=8
		db 04H, 00H, 00H, 00H, 10H, 00H, 00H, 00H
		db 05H, 00H, 00H, 00H, 47H, 4EH, 55H, 00H
		db 02H, 00H, 00H, 0C0H, 04H, 00H, 00H, 00H
		db 03H, 00H, 00H, 00H, 00H, 00H, 00H, 00H
