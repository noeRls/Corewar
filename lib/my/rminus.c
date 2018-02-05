/*
** EPITECH PROJECT, 2017
** rminus
** File description:
** remove the '-' from a str nb
*/

#include "my.h"

char *rminus(char *nb)
{
	if (nb[0] == '-')
		remove_it(nb, 0);
	return (nb);
}
