bits 64
section .text
global strrchr

strrchr:
    enter 0, 0
    xor rax, rax

    mov r10, rdi    ; first parameter in temp
    call strlen     ; get len of first parameter with first parameter
    mov rcx, rax    ; set len in rcx (cursor)
    inc rcx
    mov rdi, r10    ; temp go back in first parameter
    jmp strrchr_if_end

strrchr_if_wanted:
    sub rcx, 0x1
    cmp byte [rdi + rcx], sil   ; if result is what we wanted
    jne strrchr_if_end          ; | ifnot got to incr
    mov rax, rdi                ; set
    add rax, rcx
    leave
    ret

strrchr_if_end:
    cmp rcx, 0x0                ; if pos is 0
    jne strrchr_if_wanted         ; | ifnot go to next else if
    xor rax, rax                ; set result to NULL
    leave
    ret                         ; quit


strlen:
    enter 0, 0
    xor rax, rax
    jmp strlen_if
strlen_if:
    cmp byte [rdi + rax], 0
    je strlen_end
    inc rax
    jmp strlen_if

strlen_end:
    leave
    ret