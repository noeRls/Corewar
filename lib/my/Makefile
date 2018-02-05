##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## libmy
##

SRC	=	my_printf.c	\
		my_printf_tool.c	\
		my_printf_tool2.c	\
		specifier.c	\
		specifier2.c	\
		specifier3.c	\
		add_it.c	\
		convert_base.c	\
		get_color.c	\
		my_char_isnum.c	\
		my_compute_power_it.c	\
		my_compute_power_rec.c	\
		my_compute_square_root.c	\
		my_find_prime_sup.c	\
		my_getnbr_base.c	\
		my_getnbr.c	\
		my_int_to_str.c	\
		my_isneg.c	\
		my_is_prime.c	\
		my_putchar.c	\
		my_putnbr_base.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_revstr.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_strdup.c	\
		my_str_isalpha.c	\
		my_str_islower.c	\
		my_str_isnum.c	\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_strlen.c	\
		my_strlowcase.c	\
		my_strncat.c	\
		my_strncmp.c	\
		my_strncpy.c	\
		my_strnncpy.c	\
		my_strupcase.c	\
		my_str_word_array_tool.c	\
		my_swap.c	\
		remove_it.c	\
		is_neg.c	\
		rminus.c	\
		my_str_numcmp.c	\
		my_delete_zero.c	\
		super_arg_management.c	\
		gnl.c	\
		str_to_word_array.c	\
		my_calloc.c	\
		my_malloc.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ) $(CFLAG)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean all
