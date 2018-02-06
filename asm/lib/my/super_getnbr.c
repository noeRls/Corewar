/*
** EPITECH PROJECT, 2017
** getnbr
** File description:
** getnbr
*/

#include "my.h"

size_t super_getnbr(char *str)
{
	char *tmp = str;
	size_t nb = 0;
	size_t tmpnb;

	for (tmp; my_char_isnum(*tmp) && *tmp != 0; tmp++) {
		tmpnb = nb;
		nb *= 10;
		nb += (*tmp) - 48;
		if (tmpnb != nb / 10)
			return (0);
	}
	return (nb);
}
