/*
** EPITECH PROJECT, 2017
** convert_base
** File description:
** returns the result from the nbr string conversion
*/

#include "my.h"

static char *get_digit(long long nb, int const len_bt, int *nb_digi)
{
	char reste = 0;
	char *digit = 0;
	int len_nb = 0;
	int i = 0;

	len_nb = determine_lenght(nb);
	digit = my_malloc(sizeof(char) * (4 * len_nb + 1));
	while (nb != 0) {
		reste = nb % len_bt;
		nb = nb / len_bt;
		digit[i] = reste;
		i++;
	}
	*nb_digi = i;
	digit[i] = 0;
	return (digit);
}

static char *build_nb(char const *base_to, char *digit, int di)
{
	int i = 0;
	char *nb_final = 0;

	nb_final = my_malloc(sizeof(char) * (di + 1));
	while (i < di) {
		for (int b = 0; base_to[b] != 0; b++)
			digit[i] == b ? nb_final[i] = base_to[b] : 0;
		i++;
	}
	nb_final[i] = 0;
	return (nb_final);
}

char *convert_base(const char *nbr, char const *base_from, \
	char const *base_to)
{
	long long nb_dec = 0;
	int len_bt = 0;
	char *digit = 0;
	char *nb_final = 0;
	int nb_digi = 0;

	if (nbr[0] == '0' && nbr[1] == 0)
		return (my_strdup(nbr));
	len_bt = my_strlen(base_to);
	if (len_bt < 2)
		return (0);
	nb_dec = my_getnbr_base(nbr, base_from);
	digit = get_digit(nb_dec, len_bt, &nb_digi);
	nb_final = build_nb(base_to, digit, nb_digi);
	free(digit);
	my_revstr(nb_final);
	return (nb_final);
}
