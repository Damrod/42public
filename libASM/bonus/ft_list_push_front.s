default rel
global ft_list_push_front
extern malloc
SECTION .text
ft_list_push_front:
		push	r14						; push preserved registers on the stack
		push	rbx						; r14, rbx
		push	rax						; and align rsp to 16 byte boundary
		test	rdi, rdi				; if the first argument (**list) is null
		jz		L_END					; jump to restore the stack and return
		mov		r14, rsi				; save data (void *) into r14
		mov		rbx, rdi				; save list (t_list **) into rbx
		mov		edi, 16					; pass unsigned int 16 to malloc
		call	malloc WRT ..plt		; to allocate 16 bytes on the heap
										; (two 64-bit pointers)
		test	rax, rax				; if malloc returned null
		jz		L_END					; jump to restore the stack and return
		mov		qword [rax], r14		; otherwise store data on the location
										; pointed to by the return of the malloc
										; AKA the first field of the new element
										; of type t_list (list.data)
		mov		rcx, qword [rbx]		; use rcx as intermediate register
		mov		qword [rax+8H], rcx		; to copy *list (t_list *) to the second
										; field of the struct t_list (list.next)
										; to link the new element to the old lst
		mov		qword [rbx], rax		; update the head of the list by copying
										; the pointer to the element into *list
L_END:	add		rsp, 8					; restore the stack pointer to pop
		pop		rbx						; the old value of preserved registers
		pop		r14						; rbx and r14 in the proper order
		ret								; and return
