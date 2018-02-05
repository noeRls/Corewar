/*
** EPITECH PROJECT, 2017
** my_compute_power_rec
** File description:
** returns the first argument raised to the power p
*/

#include "my.h"

int my_compute_power_rec(int nb, int p)
{
	if (p < 0)
		return (0);
	if (p == 0)
		return (1);
	nb = nb * my_compute_power_rec(nb, p - 1);
	return (nb);
}
