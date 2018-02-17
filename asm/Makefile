##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## compile, et clean
##

NAME		=	asm

SDIR		=	$(realpath src)/

SRC		=	$(SDIR)main.c					\
			$(SDIR)write_file/arg_encoder.c			\
			$(SDIR)write_file/write_instruction.c		\
			$(SDIR)write_file/rewrite_header.c		\
			$(SDIR)write_file/label.c			\
			$(SDIR)write_file/rewrite_label.c		\
			$(SDIR)write_file/header.c			\
			$(SDIR)write_file/coding_byte.c			\
			$(SDIR)error_handling/verif_syntax.c		\
			$(SDIR)error_handling/verif_header.c		\
			$(SDIR)error_handling/verif.c			\
			$(SDIR)error_handling/verif_grammar.c		\
			$(SDIR)tools/file_to_cor.c			\
			$(SDIR)tools/int_to_str.c			\
			$(SDIR)tools/shift_tab.c			\
			$(SDIR)tools/get_mnemonique.c			\
			$(SDIR)tools/magic_reverse.c			\
			$(SDIR)tools/op.c				\
			$(SDIR)tools/str_to_av.c			\
			$(SDIR)tools/my_memset.c

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
	$(RM) -f vg*
	$(RM) -f *.cor
	make clean -C lib/my

fclean: clean
	$(RM) -f $(NAME)
	make fclean -C lib/my

re:	fclean all

r:	all clean

.PHONY: all lib clean fclean re r
