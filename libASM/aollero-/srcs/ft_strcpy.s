global ft_strcpy
section .text
ft_strcpy:
			push	rbp				; std header: save old stack base ptr
			mov		rbp, rsp		; adjust stack base ptr to be on new stack
									; pointer
			mov		r8, rdi			;save dst (1st arg) to r8 to return it later
L_CP:		movzx	edx, byte [rsi]	; copy bytesized (*src) (2nd arg) to edx
									; zeroing the top
			mov		byte [rdi], dl	; copy bottom of edx (dl) to bytesizd (*dst)
			test	dl, dl			; test if *dst == '\0'
			jz		L_END			; if it's zero, jump to end (L_END)
			inc		rdi				; dst++
			inc		rsi				; src++
			jmp		L_CP			; jump to the start of the copy loop(L_COMP)
L_END:		mov		rax, r8			; restore original dst address to return it
			mov		rsp, rbp		; stack ptr to base ptr
			pop		rbp				; we restore the old stack base ptr
			ret						; return
