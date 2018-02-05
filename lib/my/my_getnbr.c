/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** conver_string_to_int
*/

#include "my.h"

static long long puissance_10(long long b)
{
	long long i = 0;
	long long a = 1;
	if (b == 0)
		a = 1;
	for (i = 0; i < b; i++) {
		a *= 10;
	}
	return (a);
}

long long convert_digit_to_int(int *digits, int nb_digit, int negative)
{
	int i = nb_digit;
	int count = 0;
	long nb = 0;
	long long nb_int = 0;
	long long tmp = 0;

	while (i != 0) {
		tmp = puissance_10(count);
		tmp = tmp * digits[i - 1];
		nb += tmp;
		count ++;
		i--;
	}
	if (negative == -1)
		nb = -nb;
	if (nb >= -2147483648 && nb <= 2147483647)
		nb_int = nb;
	return (nb_int);
}

void check_if_changement_signe(int tmp, int *negative)
{
	if (tmp == '+') {
		*negative *= 1;
	} else if (tmp == '-') {
		*negative *= -1;
	} else {
		*negative = 1;
	}
}

long long my_getnbr(char const *str)
{
	int i = 0;
	int digits[11] = {0};
	int negative = 1;
	int tmp = 0;

	for (i = 0; (str[i] > 57 || str[i] < 49) && str[i] != '\0'; i++) {
		tmp = str[i];
		check_if_changement_signe(tmp, &negative);
	}
	tmp = 0;
	while (str[i] > 47 && str[i] < 58 && str[i] != '\0') {
		digits[tmp] = str [i];
		digits[tmp] -= 48;
		i++;
		tmp ++;
		if (tmp > 10)
			return (0);
	}
	return (convert_digit_to_int(digits, tmp, negative));
}
