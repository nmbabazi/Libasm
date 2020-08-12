section .text
global ft_strlen

ft_strlen:
    mov rax, 0          ; mettre les compteurs a zero/On compte avec rax car on veut retourner la valeur comptee

count:
    cmp BYTE [rdi + rax] , 0    ; verifier si on est pas arriver au char null
    je end                      ; si char null retourner
    inc rax                     ; sinon incrementer le compteur (i++)
    jmp count                   ; continuer la boucle

end:
    ret                         ; retourner rax