/*
** EPITECH PROJECT, 2017
** my_int_to_str
** File description:
** convert an int to an str
*/

#include "my.h"

char *its(long long b)
{
	long long a = b;
	int i = 0;
	char *strresult = my_malloc(determine_lenght(a) + 2);
	char *tmp = 0;

	a < 0 ? a = -a : 0;
	for (i = 0; a > 0; i++) {
		strresult[i] = a % 10 + 48;
		a /= 10;
	}
	strresult[i] = 0;
	strresult = my_revstr(strresult);
	if (b < 0) {
		tmp = strresult;
		strresult = add_it(strresult, '-', 0);
		free(tmp);
	}
	b == 0 ? strresult[0] = '0' : 0;
	b == 0 ? strresult[1] = 0 : 0;
	return (strresult);
}
