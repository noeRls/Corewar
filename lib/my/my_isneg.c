/*
** EPITECH PROJECT, 2017
** my_isneg
** File description:
** display_P_if_positive_N_if_negative
*/

#include "my.h"

int my_isneg(int n)
{
	if (n < 0)
		my_putchar('N');
	if (n >= 0)
		my_putchar('P');
	return (0);
}
