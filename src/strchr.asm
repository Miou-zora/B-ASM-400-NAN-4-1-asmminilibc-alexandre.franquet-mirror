bits 64
section .text
global strchr


strchr:
    enter 0, 0
    xor rax, rax

if_wanted:
    cmp byte [rdi], sil   ; else if result is what we wanted
    jne if_null                    ; | ifnot got to incr
    add rax, rdi                ; set
    leave
    ret

if_null:
    cmp byte [rdi], 0     ; if character in NULL
    jne incr          ; | ifnot go to next else if
    xor rax, rax                ; set result to NULL
    leave
    ret                         ; quit


incr:
    inc rdi
    jmp if_wanted