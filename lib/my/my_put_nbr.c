/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** dispay_the_number_given_in_argument
*/

#include "my.h"

int determine_lenght(long long nb)
{
	int lenght = 0;

	if (nb == 0)
		return (1);
	while (nb != 0) {
		nb /= 10;
		lenght ++;
	}
	return (lenght);
}

void print_nb(long long nb, int lenght)
{
	int count = 0;
	long long tmp = 0;
	long long nb_bis = 0;
	int count2 = 0;

	nb_bis = nb;
	while (count2 < lenght) {
		while (count < lenght) {
			tmp = nb % 10;
			nb = nb / 10;
			count ++;
		}
		my_putchar(tmp + 48);
		nb = nb_bis;
		count2 ++;
		count = count2;
	}
}

static int check_if_relou(long long nb)
{
	if (nb == -2147483648) {
		my_putchar('-');
		my_putchar('2');
		my_putchar('1');
		my_putchar('4');
		my_putchar('7');
		my_putchar('4');
		my_putchar('8');
		my_putchar('3');
		my_putchar('6');
		my_putchar('4');
		my_putchar('8');
		return (1);
	}
	return (0);
}

int my_put_nbr(long long nb)
{
	int lenght_of_nb = 0;
	int relou = 0;

	if (nb < 0) {
		my_putchar('-');
		nb = -nb;
		relou = check_if_relou(nb);
		if (relou)
			return (0);
	}
	lenght_of_nb = determine_lenght(nb);
	print_nb(nb, lenght_of_nb);
	return (0);
}
