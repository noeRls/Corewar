/*
** EPITECH PROJECT, 2017
** my_getnbr_base
** File description:
** converts and returns a numbe in a given base into int
*/

#include "my.h"

long long is_base_num(char const c, char const *base)
{
	long long i = 0;

	while (base[i] != 0) {
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static long long get_value(char const c, char const *base, long long i, \
			long long end)
{
	long long b = 0;
	long long value = 0;
	long long len = 0;

	len = my_strlen(base);
	while (base[b] != 0) {
		if (c == base[b]) {
			value = b * my_compute_power_it(len, end - i);
			return (value);
		}
		b++;
	}
	return (0);
}

long long my_getnbr_base(char const *str, char const *base)
{
	int negative = 1;
	long long i = 0;
	long long nbr = 0;
	long long end = 0;

	if (my_strlen(base) < 2)
		return (0);
	for (i = 0; str[i] != 0 && !is_base_num(str[i], base); i++) {
		check_if_changement_signe(str[i], &negative);
	}
	for (end = i; str[end] != 0 && is_base_num(str[end], base); end ++) {
	}
	end --;
	while (str[i] != 0 && is_base_num(str[i], base)) {
		nbr += get_value(str[i], base, i, end);
		i++;
	}
	if (negative == -1)
		return (-nbr);
	return (nbr);
}
