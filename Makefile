NAME	=	libasm.a
SRCS	=	ft_strlen.s \
			ft_strdup.s \
			ft_strcpy.s \
			ft_strcmp.s \
			ft_write.s	\
			ft_read.s \

OBJS	=	$(SRCS:.s=.o)

CFLAGS = -Wall -Wextra -Werror -g -no-pie

.s.o:
	nasm -f elf64 $< -o $@ 

$(NAME): ${OBJS}
	ar -rcs $(NAME) $(OBJS)
	@echo "libasm compiled successfully"

all: $(NAME)

clean:
	rm -f $(NAME) $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm a.out
	@echo "lib deleted"

re:	fclean all

debug: $(NAME)
	@gcc $(CFLAGS) main.c $(NAME)
	@lldb ./a.out

test: $(NAME)
	@gcc $(CFLAGS) main.c $(NAME)
	@echo "\n>> PROGRAM OUTPUT :"
	@./a.out

test2: $(NAME)
	@gcc $(CFLAGS) main2.c $(NAME)
	@echo "\n>> PROGRAM OUTPUT :"
	@./a.out