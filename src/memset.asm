bits 64
section .text
global memset

;   array ,  value ,  size
;8 pointer, 4 value, 4 size
;   RDI,      sil,     EDX
memset:
    enter 0, 0
    mov rax, rdi            ; return le pointeur de rdi


memset_loop:
    cmp edx, 0              ; si size == 0
    je memset_end           ; alors on arrete, sinon
    mov byte [rdi], sil          ; set la valeur de la pos de rdi a la value
    add rdi, 1                 ; décale de 1 le pointeur
    sub edx, 1              ; décremente la size
    jmp memset_loop

memset_end:
    leave
    ret
