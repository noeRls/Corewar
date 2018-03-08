##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## compile, et clean
##

SRC =	./src/main.c			\
	./src/graphics_inits.c		\
	./src/inits.c			\
	./src/prog_tools.c		\
	./src/manage_args.c		\
	./src/op.c			\
	./src/run.c			\
	./src/memory_tools.c		\
	./src/cleans.c			\
	./src/checks.c			\
	./src/opcode/pc_tools.c		\
	./src/opcode/arg_data.c		\
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
	./src/opcode/tool_op.c		\
	./src/render.c			\
	./src/destroy.c			\

OBJ =	$(SRC:.c=.o)

CFLAGS = -Wall -Wextra #-Werror

CPPFLAGS = -Iinclude -g3

LDFLAGS = -lc_graph_prog -L../corewar/lib/my -lmy -lm

NAME =	corewar

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ../corewar/lib/my
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CPPFLAGS)

clean:
	make clean -C ../corewar/lib/my
	$(RM) -f $(OBJ)

fclean: clean
	make fclean -C ../corewar/lib/my
	$(RM) -f $(NAME)

re:	fclean all

.PHONY: all lib clean fclean re
