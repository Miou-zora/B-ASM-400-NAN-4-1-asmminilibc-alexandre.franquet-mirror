bits 64
section .text
global memmove
; to    , from  , size
; dest  , src   , size
; array , array , size
; 8 ptr , 8 ptr , 4 size
; rdi   , rsi   , edx
memmove:
    enter 0, 0
    mov rax, rdi                        ; return le pointeur de rdi
    cmp rdi, rsi
    je memmove_end
    cmp edx, 0                          ; si size == 0
    je memmove_end

memmove_if_dest_sup_src:
    cmp rdi, rsi
    jng memmove_loop                    ; check if dest is inferior to src

    mov r10, rdi
    sub r10, rsi                        ; take the difference of dest and src to check if there are overlaping
    cmp r10d, edx
    jnl memmove_loop
    xor rcx, rcx
    mov ecx, edx

memove_overlap:
    cmp rcx, 0                          ; si size == 0
    je memmove_end                     ; alors on arrete, sinon
    mov r10b, byte [rsi + rcx - 1]
    mov byte [rdi + rcx - 0x1], r10b      ; set la valeur a la pos de dest a la valeur a la pos de src
    sub rcx, 1                          ; décremente la size
    jmp memove_overlap


memmove_loop:
    cmp edx, 0                          ; si size == 0
    je memmove_end                       ; alors on arrete, sinon
    mov r10b, byte [rsi]
    mov byte [rdi], r10b                ; set la valeur a la pos de dest a la valeur a la pos de src
    inc rsi                             ; décale de 1 le pointeur de src
    inc rdi                             ; décale de 1 le pointeur de dest
    sub edx, 1                          ; décremente la size
    jmp memmove_loop

memmove_end:
    leave
    ret