bits 64
section .text
global strstr

; a     , b
; array , array
; 8 ptr , 8 ptr
; rdi   , rsi
strstr:
    enter 0, 0
    xor rax, rax
    mov r11, rdi
    xor r10, r10
    cmp byte [rsi], 0
    jne strstr_loop
    je strstr_return_good

strstr_loop:
    cmp byte [rdi], 0
    je strstr_return_bad
    call strcmp
    cmp rax, 0
    je strstr_return_good
    inc rdi
    jmp strstr_loop

strstr_return_good:
    mov rax, rdi
    jmp strstr_end

strstr_return_bad:
    xor rax, rax

strstr_end:
    leave
    ret

strcmp:
    xor rax, rax
    xor rcx, rcx

strcmp_loop:
    mov r10b, byte[rsi + rcx]
    cmp r10b, 0
    je strcmp_end_equal
    cmp byte[rdi + rcx], r10b
    jb strcmp_end_less
    ja strcmp_end_greater
    inc rcx
    jmp strcmp_loop


strcmp_end_greater:
    mov rax, 1
    ret


strcmp_end_less:
    mov rax, -1
    ret

strcmp_end_equal:
    xor rax, rax
    ret
