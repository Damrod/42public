global ft_read
extern __errno_location
SECTION .text
ft_read:
			push	rbp				 ; std header: save old stack base ptr
			mov		rbp, rsp		 ; adjust stack base ptr to be on new stack
									 ; pointer
			push	rbx				 ; save rbx aligning to 16 bit boundary
			mov		rax, 0H			 ; in linux, 0x0 is the code for read
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

; global ft_read
; default rel						 ; this should fix the -fPIE problem but
; 									 ; it doesn't
; SECTION .text
; ft_read:
; 			mov		rax, 0H			 ; in linux, 0x0 is the code for read
; 									 ; syscall. It has to be loaded into rax
; 									 ; before the call. We pass the same
; 									 ; rdi, rsi, rdx as we receive (we do not
; 									 ; modify them)
; 			syscall					 ; syscall
; 			cmp		rax, 0			 ; if it returns smaller than zero there
; 			jl		L_ERROR			 ; was an error, and we jump to deal with it
; 			ret						 ; otherwise we just return the return
; 									 ; value of the syscall (rax) as is.
; L_ERROR:	imul	rax, -1			 ; errno is a positive number, but the
; 									 ; syscall returns a negative number
; 									 ; so we want to rax = rax * -1
; 			mov		rcx, rax		 ; and we save it into rcx for later use.
; 			lea		rax, [errno]	 ; unlike the case with ft_write, here
; 									 ; it works just to declare an
; 									 ; uninitialized "errno" of size double
; 									 ; word, in the section bss and take
; 									 ; the address with the `lea` instruction
; 									 ; into the register rax
; 			mov		dword [rax], ecx ; copy the value we saved in L44 to
; 									 ; *(&errno)
; 			mov		rax, -1			 ; copy -1 to rax to return it
; 			ret						 ; return
; SECTION .bss
; errno: resd 0						 ; see L46
