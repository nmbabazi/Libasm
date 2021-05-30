section .text
global ft_read
extern __errno_location

; les arg sont directement pris en compte par le syscall write

ft_read:
        mov rax , 0     ; num d'app system de write sur linux
        syscall         ; app system
        cmp rax , 0     ; verification d'erreur
        jl  error       ; si rax (qui correspond au retour du syscall) negatif = error
        ret

error:
        neg rax                         ; les codes errno sont positif
        mov rcx, rax                    ; enregistrer la valeur de rax dans rcx pour la conserver
        push rcx                        ; proteger la valeur de rcx pour quelle ne soit pas modifier dans l'appelle fonction
        call    __errno_location        ; appeler la fonction __errno_location qui renvoie l'adresse ou mettre l'erreur 
        pop rcx                         ; sortir la valeur enregistrer
        mov [rax] , rcx                 ; mettre la valeur de l'erreur dans errno (pointe par rax)
        mov rax, -1                     ; renvoyer -1 (ne pas renvoyer la valeur de l'adresse de errno)
        ret