bits 64
section .text
global strpbrk


; a     , b
; array , array
; 8 ptr , 8 ptr
; rdi   , rsi
strpbrk:
    enter 0, 0
    xor rax, rax
    xor rcx, rcx
    jmp strpbrk_loop

strpbrk_is_char_is_that:
    cmp byte [rsi + rcx], 0
    je strpbrk_loop2
    mov r10b, byte [rsi + rcx]
    cmp r10b, byte [rdi]
    je strpbrk_end_not_null
    inc rcx
    jmp strpbrk_is_char_is_that

strpbrk_loop:
    jmp strpbrk_is_char_is_that

strpbrk_loop2:
    xor rcx, rcx
    cmp byte [rdi], 0
    je strpbrk_end
    inc rdi
    jmp strpbrk_loop

strpbrk_end_not_null:
    mov rax, rdi
    jmp strpbrk_end

strpbrk_end:
    leave
    ret
