##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## compile, et clean
##


SDIR		=	$(realpath src)/

SRC		=	$(SDIR)main.c			\
			$(SDIR)write_instruction.c	\
			$(SDIR)op.c

OBJ		=	$(SRC:.c=.o)

NAME		=	asm

CFLAGS		+=	-Wall -Wextra -I./include

LDFLAGS		=	-L./lib/my

LDLIBS		=	-lmy

all:	lib $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

lib:
	make -C lib/my

clean:
	rm -f $(OBJ)
	rm -f *.core vg*
	make clean -C lib/my

fclean: clean
	rm -f $(NAME)
	make fclean -C lib/my

re:	fclean all

r:	all clean

.PHONY: all lib clean fclean re r
