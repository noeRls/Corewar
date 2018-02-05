/*
** EPITECH PROJECT, 2017
** my_compute_square_root
** File description:
** returns the square root
*/

#include "my.h"

static void ini_root(int *root, int nb)
{
	int nbr_digits = 0;
	int i = 0;

	i = nb;
	while (i != 0) {
		i /= 10;
		nbr_digits ++;
	}
	nbr_digits -= 2;
	nbr_digits /= 2;
	i = my_compute_power_it(10, nbr_digits);
	if (i < 1)
		i = 1;
	*root = nb / i;
}

int my_compute_square_root(int nb)
{
	int i = 0;
	int root = 0;

	ini_root(&root, nb);
	if (nb < 1)
		return (0);
	while (root * root != nb && root > 1) {
		i += 2;
		root -= 1;
	}
	if (root * root == nb)
		return (root);
	return (0);
}
