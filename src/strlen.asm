bits 64
section .text
global strlen

strlen:
    enter 0, 0
    xor rax, rax
    jmp if
if:
    cmp byte [rdi + rax], 0
    je end
    inc rax
    jmp if

end:
    leave
    ret