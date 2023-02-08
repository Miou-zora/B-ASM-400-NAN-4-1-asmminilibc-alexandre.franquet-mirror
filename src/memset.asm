bits 64
section .text
global memset

;8 pointer, 4 value, 4 size
;   RDI,      ESI,     EDX
memset:
    enter 0, 0
    cmp edx, 0          ; si size == 0
    je memset_end       ; alors on arrete, sinon
    mov [rdi], esi
    inc rdi
    inc edx
    jmp memset

memset_end:
    leave
    ret
