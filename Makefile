##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## compile, et clean
##


SRC	=	src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	test

CFLAGS	+=	-Wall -Wextra -I./include

all:	lib $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -L./lib/my -lmy

lib:
	make -C lib/my

clean:
	rm -f $(OBJ)
	make clean -C lib/my

fclean: clean
	rm -f $(NAME)
	make fclean -C lib/my

re:	fclean all

r:	all clean

.PHONY: all lib clean fclean re r
