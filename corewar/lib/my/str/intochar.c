/*
** EPITECH PROJECT, 2017
** EvalXPR
** File description:
** Convert int to char
*/

#include <stdlib.h>
#include "my.h"

char *my_intochar(int base)
{
	char *converted = my_malloc(sizeof(char) * 11);
	int neg = (base < 0 ? 1 : 0);
	int div = 1;
	int cont = 0;

	if (neg == 1) {
		base *= -1;
		converted[digits(base)] = '0';
	}
	while (div != 0) {
		converted[cont] = (base % 10) + 48;
		div = base / 10;
		base = base / 10;
		cont++;
	}
	converted[cont] = 0;
	my_revstr(converted);
	if (neg == 1)
		converted[0] = '-';
	return (converted);
}
