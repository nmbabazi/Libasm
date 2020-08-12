section .text
global ft_strdup
extern ft_strlen
extern malloc
extern ft_strcpy

ft_strdup:
        call ft_strlen      ; prend en argument ce qu'il y a dans rdi
        inc rax             ; ajouter l'espace pour '\0'
        push rdi            ; conserver l'arg initial avant de le modifier rdi pour malloc
        mov rdi , rax       ; mettre la longueur trouvee par strlen dans rdi(arg 1) pour quelle puisse etre utilisee par malloc
        call malloc
        pop rdi             ; recuperer l'arg initial
        cmp rax, 0          ; verifier le malloc
        je mallocnull
        mov rsi, rdi        ; mettre mon arg initial dans le second argument (voir man strcpy)   
        mov rdi, rax        ; mettre ma len dans le premier argument (voir man strcpy)
        call ft_strcpy      ;
        ret

mallocnull:
        mov rax, 0
        ret