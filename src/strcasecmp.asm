bits 64
section .text
global strcasecmp

; a     , b
; array , array
; 8 ptr , 8 ptr
; rdi   , rsi
strcasecmp:
    enter 0, 0
    xor rax, rax
    xor rcx, rcx

strcasecmp_loop:
    mov r10b, byte[rsi + rcx]
    mov r11b, byte[rdi + rcx]
    call strcasecmp_reduct_A
    cmp r11b, r10b
    jne strcasecmp_end
    cmp r10b, 0
    je strcasecmp_return
    inc rcx
    jmp strcasecmp_loop


strcasecmp_end:; return greater
    xor r10d, r10d
    xor r11d, r11d
    mov r10b, byte[rdi + rcx]
    mov r11b, byte[rsi + rcx]
    call strcasecmp_reduct_A
    mov eax, r10d
    sub eax, r11d

strcasecmp_return:
    leave
    ret


strcasecmp_return_no_leave:
    ret

strcasecmp_reduct_A:
    cmp r11b, 'A'
    jl strcasecmp_reduct_B
    cmp r11b, 'Z'
    jg strcasecmp_reduct_B
    add r11b, 32

strcasecmp_reduct_B:
    cmp r10b, 'A'
    jl strcasecmp_return_no_leave
    cmp r10b, 'Z'
    jg strcasecmp_return_no_leave
    add r10b, 32
    ret

strcasecmp_ok:


strcasecmp_maj:
