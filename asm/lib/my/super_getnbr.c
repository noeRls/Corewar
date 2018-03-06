/*
** EPITECH PROJECT, 2017
** getnbr
** File description:
** getnbr
*/

#include "my.h"

ssize_t super_getnbr(char *str)
{
	char *tmp = str;
	ssize_t nb = 0;
	ssize_t tmpnb;
	int neg = 1;

	while (*tmp == '-') {
		tmp++;
		neg *= -1;
	}
	while (*tmp == '+')
		tmp++;
	for (tmp; my_char_isnum(*tmp) && *tmp != 0; tmp++) {
		tmpnb = nb;
		nb *= 10;
		nb += (*tmp) - 48;
		if (tmpnb != nb / 10)
			return (0);
	}
	return ((neg == -1 ? -nb : nb));
}
