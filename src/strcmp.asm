bits 64
section .text
global strcmp

; a     , b
; array , array
; 8 ptr , 8 ptr
; rdi   , rsi
strcmp:
    enter 0,0
    xor rax, rax
    xor rcx, rcx

strcmp_loop:
    mov r10b, byte[rsi + rcx]
    cmp byte[rdi + rcx], r10b
    jl strcmp_end_less
    jg strcmp_end_greater
    cmp r10b, 0
    je strcmp_end_equal
    inc rcx
    jmp strcmp_loop


strcmp_end_greater:
    mov rax, 1
    leave
    ret


strcmp_end_less:
    mov rax, -1
    leave
    ret

strcmp_end_equal:
    leave
    ret