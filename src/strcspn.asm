bits 64
section .text
global strcspn


; a     , b
; array , array
; 8 ptr , 8 ptr
; rdi   , rsi
strcspn:
    enter 0, 0
    xor rax, rax
    xor rcx, rcx
    xor r11, r11
    jmp strcspn_loop

strcspn_is_char_is_that:
    cmp byte [rsi + rcx], 0
    je strcspn_loop2
    mov r10b, byte [rsi + rcx]
    cmp r10b, byte [rdi]
    je strcspn_end
    inc rcx
    jmp strcspn_is_char_is_that

strcspn_loop:
    jmp strcspn_is_char_is_that

strcspn_loop2:
    xor rcx, rcx
    cmp byte [rdi], 0
    je strcspn_end
    inc rdi
    inc r11
    jmp strcspn_loop

strcspn_end:
    mov rax, r11
    leave
    ret
