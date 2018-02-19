/*
** EPITECH PROJECT, 2017
** my_put_pointer
** File description:
** put pointer in hexa
*/

#include <stdlib.h>
#include "my.h"

char *get_nbr_base(long long nb, char const *base)
{
	long long basenb = my_strlen(base);
	char *final = nb ? my_malloc(50) : 0;
	int index = 0;
	long long tmp = 0;
	int neg = (nb < 0 ? 1 : 0);

	if (nb == 0)
		return (my_strdup("0"));
	nb = (nb > 0 ? nb : -nb);
	while (nb) {
		tmp = nb;
		nb = nb / basenb;
		final[index++] = base[tmp % basenb];
	}
	if (neg)
		final[index++] = '-';
	final[index] = 0;
	return (my_revstr(final));
}
