bits 64
section .text
global memcpy

; dest  , src   , size
; array , array , size
; 8 ptr , 8 ptr , 4 size
; rdi   , rsi   , edx
memcpy:
    enter 0, 0
    mov rax, rdi            ; return le pointeur de rdi


memcpy_loop:
    cmp edx, 0                          ; si size == 0
    je memcpy_end                       ; alors on arrete, sinon
    mov r10b, byte [rsi]
    mov byte [rdi], r10b          ; set la valeur a la pos de dest a la valeur a la pos de src
    inc rsi                             ; décale de 1 le pointeur de src
    inc rdi                             ; décale de 1 le pointeur de dest
    sub edx, 1                          ; décremente la size
    jmp memcpy_loop

memcpy_end:
    leave
    ret
