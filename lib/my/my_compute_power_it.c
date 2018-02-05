/*
** EPITECH PROJECT, 2017
** my_compute_power_it
** File description:
** returns the first argument raised to the power
*/

#include "my.h"

long long my_compute_power_it(long long nb, long long p)
{
	long long i = 1;
	long long nb_final = 1;

	if (p < 0)
		return (0);
	if (p == 0)
		return (1);
	while (i <= p) {
		nb_final *= nb;
		i++;
	}
	return (nb_final);
}
