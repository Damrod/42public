default rel
global ft_list_size
SECTION .text
ft_list_size:
		xor		eax, eax			; prepare rax to start at zero to return
L_STRT:	test	rdi, rdi			; if the current list element is NULL
		jz		L_END				; jump to return
		mov		rdi, qword [rdi+8H]	; otherwise move the second field
									; (list->next) of the current element
									; of the list into rdi to make it
									; current. The fields are 8 bytes aligned.
		inc		eax					; increment the return value by one
		jmp		L_STRT				; and loop back to L_START to check if the
									; element is NULL
L_END:	ret							; from L7 : and return the value in eax
