section .text
global ft_strcpy

ft_strcpy:
    mov rcx , 0     ; mettre le compteur a zero

cpy:
    cmp BYTE [rsi + rcx] , 0    ; verifier si on est arriver au char null
    je end                      ; si char null retourner
    mov dl , BYTE [rsi + rcx]   ; swap le caractere dans dl(registre d'un octet) car pas possibiliter de copier directement en asm
    mov BYTE [rdi + rcx], dl    ; swap
    inc rcx                     ; incrementation du compteur (i++)
    jmp cpy                     ; poursuite de la boucle de copie

end:
    mov BYTE [rdi + rcx], 0     ; '\0'
    mov rax, rdi                ; mettre la chaine modifier dans rax pour la retourner
    ret
