global ft_write
extern __errno_location
SECTION .text
ft_write:
			push	rbp				 ; std header: save old stack base ptr
			mov		rbp, rsp		 ; adjust stack base ptr to be on new stack
									 ; pointer
			push	rbx				 ; save rbx aligning to 16 bit boundary
			mov		rax, 1H			 ; in linux, 0x1 is the code for write
									 ; syscall. It has to be loaded into rax
									 ; before the call. We pass the same
									 ; rdi, rsi, rdx as we receive (we do not
									 ; modify them)
			syscall					 ; syscall
			cmp		rax, 0			 ; if it returns smaller than zero there
			jl		L_ERROR			 ; was an error, and we jump to deal with it
			jmp		L_END			 ; otherwise we just jump to return the
									 ; return value of the syscall (rax) as is.
L_ERROR:	imul	rax, -1			 ; errno is a positive number, but the
									 ; syscall returns a negative number
									 ; so we want to rax = rax * -1
			push	rax				 ; we save it for later use and also as a
									 ; stack alignment to 16 bit boundary
			call	__errno_location WRT ..plt
									 ; this func is the equivalent to ___error
									 ; in macOS. It doesn't take any arguments
									 ; and it returns the address of errno.
			pop		rdx				 ; copy the value we saved in L19 to rdx
			mov		byte[rax], dl	 ; copy lower byte of rdx to *(&errno)
			mov		rax, -1			 ; copy -1 to rax to return it
L_END:		mov		rbx, [rbp - 8]	 ; restore rbx relatively to rbp, to fool
									 ; proof against mangling the rsp
			mov		rsp, rbp		 ; stack ptr to base ptr
			pop		rbp				 ; we restore the old stack base ptr
			ret						 ; return

; global ft_write
; default rel
; SECTION .text
; ft_write:
; 			mov		rax, 1H
; 			syscall
; 			cmp		rax, 0
; 			jl		L_ERROR
; 			ret
; L_ERROR:	imul	rax, -1
; 			mov		rcx, rax
; 			lea		rax, [errno]
; 			mov		dword [rax], ecx
; 			mov		rax, -1
; 			ret
; SECTION .bss
; errno: resd 0						 ; this function as in this comment doesn't
									 ; properly set errno, unlike with ft_read
