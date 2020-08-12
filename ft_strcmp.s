section .text
global ft_strcmp

ft_strcmp:
    mov dl , 0      ; dl a null pour le retour en cas de chaine vide
    mov rcx , 0     ; le compteur est mis a null

verif:
    cmp BYTE [rdi] , 0  ; verification si s1 null
    je s1null
    cmp BYTE [rsi] , 0  ; verification si s2 null
    je s2null

comp:
    mov dl , BYTE [rdi + rcx]   ; swap le caractere dans dl(registre d'un octet) car pas possibiliter de cmp directement en asm
    cmp BYTE [rdi + rcx] , 0    ; en cas de chaine identique, besoin de ret lorsqu'on arrive a la fin de s1 
    je end
    cmp BYTE [rsi + rcx] , dl   ; swp
    jne end                     ; retour en cas de difference
    inc rcx                     ; sinon incrementer le conteur (i++)
    jmp comp                    ; poursuite de la boucle de comparaison

s1null:
    SUB dl, BYTE [rsi]          ; calcule du retour en cas de s1 null
    movsx rax, dl
    ret

s2null:
    mov dl, BYTE [rdi]    ; calcule du retour en cas de s2 null
    movsx rax, dl
    ret

end:
    SUB dl, BYTE [rsi + rcx]    ; calcule de la difference
    movsx rax, dl               ; retour la difference, movsx car dl a une taille differente de celle de rax
    ret
