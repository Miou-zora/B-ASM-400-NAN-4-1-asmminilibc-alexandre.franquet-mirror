bits 64
section .text
global strncmp

; a     , b     , n
; array , array , size_t
; 8 ptr , 8 ptr , 4 size
; rdi   , rsi   , edx
strncmp:
    enter 0,0; init
    xor rax, rax; setup output
    xor rcx, rcx; setup string cursor (= ecx (4 byte))
    cmp edx, 0
    je strncmp_return
    sub edx, 1

strncmp_loop:
    cmp ecx, edx; check if cursor is arrived to the end of n
    ja strncmp_return; if ended they a equal until n
    mov r10b, byte[rsi + rcx]; move char of a + cursor in temp variable
    cmp r10b, 0
    jle strncmp_end
    cmp byte[rdi + rcx], r10b; compare char of b + cursor and char of a + cursor
    jne strncmp_end
    inc rcx; if not increment cursor
    jmp strncmp_loop; restart the loop

strncmp_end:; return greater
    xor r10d, r10d
    xor r11d, r11d
    mov r10b, byte[rdi + rcx]
    mov r11b, byte[rsi + rcx]
    mov eax, r10d
    sub eax, r11d

strncmp_return:
    leave
    ret

temp:
    mov rax, 1
    leave
    ret