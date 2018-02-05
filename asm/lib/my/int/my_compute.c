/*
** EPITECH PROJECT, 2017
** few mathematical operations
** File description:
** maths operations
*/

#include "my.h"

int my_compute_power(int nb, int p)
{
	int res = nb;
	int wasp = 0;

	if (nb >= 0)
		wasp = 1;
	if (p == 0) {
		return (1);
	} else if (p < 0) {
		return (0);
	}
	res = res * my_compute_power(res, p - 1);
	if ((res < 0 && wasp == 1) || (wasp == 1 && res < nb && p >= 1)) {
		return (0);
	} else {
		return (res);
	}
}

int my_compute_square_root(int nb)
{
	int dg = 0;
	int bs;
	int bi;

	dg = digits(nb);
	if (dg % 2 != 0 || dg <= 2)
		dg = dg + 1;
	bs = my_compute_power(10, dg / 2);
	bi = bs / 10;
	bi = bi - (nb % 2);
	while (bi <= bs) {
		if (bi * bi == nb) {
			return (bi);
		}
		bi = bi + 1;
	}
	return (0);
}
