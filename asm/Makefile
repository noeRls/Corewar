##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## compile, et clean
##

NAME		=	asm

SDIR		=	$(realpath src)/

SRC		=	$(SDIR)main.c			\
			$(SDIR)str_to_av.c		\
			$(SDIR)arg_encoder.c		\
			$(SDIR)write_instruction.c	\
			$(SDIR)rewrite_header.c		\
			$(SDIR)file_to_cor.c		\
			$(SDIR)verif_syntax.c		\
			$(SDIR)label.c			\
			$(SDIR)int_to_str.c		\
			$(SDIR)rewrite_label.c		\
			$(SDIR)header.c			\
			$(SDIR)op.c			\
			$(SDIR)coding_byte.c		\
			$(SDIR)my_memset.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-Wall -Wextra -Werror

CPPFLAGS	=	-I $(realpath include)

LDFLAGS		=	-L./lib/my

LDLIBS		=	-lmy

DEBUG		=	false

ifeq ($(DEBUG), true)
		CFLAGS	+=	-g3
endif

all:	lib $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

lib:
	$(MAKE) -C lib/my

clean:
	$(RM) -f $(OBJ)
	$(RM) -f *.cor vg*
	make clean -C lib/my

fclean: clean
	$(RM) -f $(NAME)
	make fclean -C lib/my

re:	fclean all

r:	all clean
	clear && echo "GUILLAUME NTM" && sleep 2 && ./label.sh

.PHONY: all lib clean fclean re r
