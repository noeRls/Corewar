/*
** EPITECH PROJECT, 2017
** my_is_prime
** File description:
** returns 1 if the number is prime and 0 if not
*/

#include "my.h"

static int check_if_prime(int nb)
{
	int div = 0;

	div = 2;
	while (nb % div != 0) {
		div ++;
		if (div > nb / 2 + 1)
			return (1);
	}
	return (0);
}

int my_is_prime(int nb)
{
	if (nb == 2)
		return (1);
	if (nb % 2 == 0 || nb < 2)
		return (0);
	return (check_if_prime(nb));
}
