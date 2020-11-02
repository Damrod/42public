global ft_strdup
extern malloc
extern ft_strlen
SECTION .text
ft_strdup:
			push	rbp				; std header: save old stack base ptr
			mov		rbp, rsp		; adjust stack base ptr to be on new stack
									; pointer
			push	rdi				; save the value of rdi and align the stack
									; before the call, and also in case the
									; callee changes it.
			call	ft_strlen wrt ..plt; call ft_strlen
			inc		rax				; len = len + 1, to pass to malloc
			push	rax				; save len to use as a counter later.
			mov		rdi, rax		; pass len into std rdi (1st argument)
			call	malloc wrt ..plt; call malloc
			test	rax, rax		; test whether malloc returned NULL
			jz		L_NMA			; if NULL, go to L_NMA (null malloc)
			pop		rcx				; load the last value in the stack (len)
									; into rcx to use as a counter.
			pop		rdi				; Recover rdi.
			push	rax				; save return value of malloc to return it
									; later
L_CP:		movzx	rdx, byte [rdi] ; bytesized bottom of *rdi (*src) into rdx
									; (zeroing the top)
			mov		byte [rax], dl	; bytesized bottom of rdx into *rax (*dst)
			inc		rax				; rax++ (dst++)
			inc		rdi				; rdi++ (src++)
			dec		ecx				; rcx-- (len--)
			test	cl, cl			; if len != 0
			jnz		L_CP			; loop back into L_CP (label copy)
			pop		rax				; recover the return value of malloc
L_NMA:		mov		rsp, rbp		; stack ptr to base ptr
			pop		rbp				; we restore the old stack base ptr
			ret						; to return it
