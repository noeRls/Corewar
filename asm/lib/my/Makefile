##
## EPITECH PROJECT, 2017
## my_lib Makefile
## File description:
## Makefile for my lib
##

NAME	= libmy.a

RM	= rm -f

SRCS	= ./char/my_char.c \
	  ./char/my_charb.c \
	  ./int/getnbr.c \
	  ./int/my_compute.c \
	  ./int/my_maths.c \
	  ./int/my_sort_int_array.c \
	  ./mem/my_malloc.c \
	  ./mem/my_sys_utils.c \
	  ./my_printf/display_basenb.c \
	  ./my_printf/display_f.c \
	  ./my_printf/display_nb.c \
	  ./my_printf/display_tools.c \
	  ./my_printf/my_printf.c \
	  ./my_printf/indent.c \
	  ./put/my_puterror.c \
	  ./put/my_put.c \
	  ./put/my_put_nbr.c \
	  ./super_getnbr.c  \
	  ./str/word_arrays/str_words.c \
	  ./str/word_arrays/str_words_forb.c \
	  ./str/word_arrays/str_words_param.c \
	  ./str/get_nbr_base.c \
	  ./str/get_next_line.c \
	  ./str/intochar.c \
	  ./str/my_show_word_array.c \
	  ./str/my_str_is.c \
	  ./str/my_str_utils.c \
	  ./str/my_str_utilsb.c \
	  ./str/my_strcmps.c \
	  ./str/my_strdigits.c \
	  ./str/match.c \

CFLAGS	=	-I./ -g3

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	 ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
