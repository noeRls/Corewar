/*
** EPITECH PROJECT, 2017
** task07
** File description:
** my put nbr
*/

#include "my.h"

void my_put_nbr(int nb)
{
	int dig;

	if (nb == 0) {
		my_putchar('0');
		return;
	}
	if (nb < 0) {
		my_putchar('-');
		nb = -nb;
	}
	dig = digits(nb);
	for (int i = dig; i > 0; i--) {
		my_putchar(nb / (my_compute_power(10, i - 1)) + 48);
		nb = nb % my_compute_power(10, i - 1);
	}
}
