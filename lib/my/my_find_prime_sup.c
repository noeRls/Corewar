/*
** EPITECH PROJECT, 2017
** my_find_prime_sup
** File description:
** the smallest prime number the number given as a parameter
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
	if (nb < 3)
		return (2);
	if (nb % 2 == 0)
		nb ++;
	while (!my_is_prime(nb)) {
		nb += 2;
	}
	return (nb);
}
