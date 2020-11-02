global ft_strcmp
SECTION .text
ft_strcmp:
			push	rbp				; std header: save old stack base ptr
			mov		rbp, rsp		; adjust stack base ptr to be on new stack
									; pointer
L_START:	movzx	edx, byte[rdi]	; load *str1 into edx
			test	dl, dl			; if str1 is over
			jz		L_EOS			; jump to end of string (L_EOS)
			movzx	ecx, byte[rsi]	; load the bytesized last value of rsi
									; (*str2) into ecx zeroing the top
			sub		edx, ecx		; *str1 - *str2 into edx
			jnz		L_END			; if *str1 and *str2 are different, go L_END
									; to prepare the return value
			inc		rdi				; str1++
			inc		rsi				; str2++
			jmp		L_START			; jump to the start of the current function
L_EOS:		movzx	ecx, byte[rsi]	; like L10 - L11 (lines 7 to 8)
			sub		edx, ecx		; like L12
L_END:		mov		eax, edx		; store the result of the subtraction
									; (either in L9 or L16, register edx) into
									; eax to return it
			mov		rsp, rbp		; stack ptr to base ptr
			pop		rbp				; we restore the old stack base ptr
			ret						; return
