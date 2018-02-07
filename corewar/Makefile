##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## compile, et clean
##


SRC =	./src/main.c			\
	./src/op.c			\
	./src/run.c			\
	./src/opcode/live.c		\
	./src/opcode/zjmp.c		\
	./src/opcode/ld.c		\
	./src/opcode/ldi.c		\
	./src/opcode/add.c		\
	./src/opcode/and.c		\
	./src/opcode/lfork.c		\
	./src/opcode/sti.c		\
	./src/opcode/or.c		\
	./src/opcode/aff.c		\
	./src/opcode/lldi.c		\
	./src/opcode/xor.c		\
	./src/opcode/fork.c		\
	./src/opcode/st.c		\
	./src/opcode/sub.c		\
	./src/opcode/lld.c		\


OBJ =	$(SRC:.c=.o)

NAME =	test

CFLAGS +=	-Wall -Wextra -I./include

LDFLAGS	=	-L./lib/my

LDLIBS =	-lmy

all:	lib $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

lib:
	make -C lib/my

clean:
	rm -f $(OBJ)
	make clean -C lib/my

fclean: clean
	rm -f $(NAME)
	make fclean -C lib/my

re:	fclean all

.PHONY: all lib clean fclean re
