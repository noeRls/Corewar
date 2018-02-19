##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## generic
##

all:
	make -C ./asm/
	make -C ./corewar/

tests_run:

clean:
	make clean -C ./asm/
	make clean -C ./corewar/

fclean:	clean
	make fclean -C ./asm/
	make fclean -C ./corewar/

re: fclean all

.PHONY: re fclean all clean
