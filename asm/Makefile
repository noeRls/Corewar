##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## compile, et clean
##


SDIR		=	$(realpath src)/

SRC		=	$(SDIR)main.c			\
			$(SDIR)str_to_av.c		\
			$(SDIR)arg_encoder.c		\
			$(SDIR)write_instruction.c	\
			$(SDIR)file_to_core.c		\
			$(SDIR)verif_syntax.c		\
			$(SDIR)header.c			\
			$(SDIR)op.c			\
			$(SDIR)coding_byte.c

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
