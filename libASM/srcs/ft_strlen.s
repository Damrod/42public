global ft_strlen
SECTION .text
ft_strlen:
			push	rbp					; std header: save old stack base ptr
			mov		rbp, rsp			; adjust stack base ptr to be on new
										; stack pointer
			mov		rax, rdi			; save 1st arg into rax
L_BEGIN:	movzx	edx, byte [rax]		; copy bytesized bottom of *rax (*src)
										; into edx, zeroing the top
			test	dl, dl				; test whether bottom of edx == '\0'
			jz		L_EOS				; if it's zero jump to end of string
			inc		rax					; rax++ (src++)
			jmp		L_BEGIN				; jump back to start of count loop
L_EOS:		sub		rax, rdi			; subtract initial value of 1st arg from
										; currnt value of rax and store into rax
			mov		rsp, rbp			; stack ptr to base ptr
			pop		rbp					; we restore the old stack base ptr
			ret							; to return it
