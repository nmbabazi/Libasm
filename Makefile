NAME	=	libasm.a
SRCS	=	src/ft_strlen.s \
			src/ft_strdup.s \
			src/ft_strcpy.s \
			src/ft_strcmp.s \
			src/ft_write.s	\
			src/ft_read.s \

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
	@gcc $(CFLAGS) test/main.c $(NAME)
	@lldb ./a.out

test: $(NAME)
	@gcc $(CFLAGS) test/main.c $(NAME)
	@echo "\n>> PROGRAM OUTPUT :"
	@./a.out

test2: $(NAME)
	@gcc $(CFLAGS) test/main2.c $(NAME)
	@echo "\n>> PROGRAM OUTPUT :"
	@./a.out