/*
** EPITECH PROJECT, 2017
** maths functions
** File description:
** maths related functions
*/

#include "my.h"

int digits(int a)
{
	int dg = 0;

	if (a == 0)
		return (1);
	while (a > 0) {
		a = a / 10;
		dg++;
	}
	return (dg);
}

int my_find_prime_sup(int nb)
{
	int nbpr;

	if (my_is_prime(nb)) {
		return (nb);
	}
	while (1) {
		nbpr = my_is_prime(nb);
		if (nbpr == 1) {
			return (nb);
		}
		nb++;
	}
}

int my_is_prime(int nb)
{
	if (nb < 2)
		return (0);
	for (int i = 2; i <= nb / 2; i++) {
		if (nb % i == 0 && nb != 1 && nb != 0) {
			return (0);
		}
	}
	return (1);
}

int min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int max(int a, int b)
{
	return ((a > b ? a : b));
}
