/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** arg_encoder
*/

#include "asm.h"

void arg_encoder(char **tab, int fd)
{
	char c = 0;
	arg_type type;

	for (int i = 1 ; tab[i] ; i++) {
		type = get_arg_type(tab[i]);
		if (type == REGISTER) {
			c = getnbr(++(tab[i]));
			write(fd, &c, sizeof(char));
		}
		if (type == INDIRECT) {

		}
	}
}
