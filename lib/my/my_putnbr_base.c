/*
** EPITECH PROJECT, 2017
** my_putnbr_base
** File description:
** t converts and displays a decimal number into a number in a given base
*/

#include "my.h"

static void print_nbr(int *nbr, char const *base, int nbr_lenght)
{
	int i = 0;
	int to_print = 0;

	while (i < nbr_lenght) {
		to_print = nbr[nbr_lenght - i - 1];
		my_putchar(base[to_print]);
		i++;
	}
}

int my_putnbr_base(int nbr, char const *base)
{
	int basee = 0;
	int reste = 0;
	int i = 0;
	int *nbr_final = 0;
	int len_nb = 0;

	len_nb = determine_lenght(nbr);
	nbr_final = my_malloc(sizeof(int) * (len_nb * 4 + 1));
	nbr_final[len_nb * 4] = 0;
	basee = my_strlen(base);
	if (basee < 2)
		return (0);
	for (i = 0; nbr != 0; i++) {
		reste = nbr % basee;
		nbr = nbr / basee;
		nbr_final[i] += reste;
	}
	print_nbr(nbr_final, base, i);
	free(nbr_final);
	return (0);
}
