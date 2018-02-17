/*
** EPITECH PROJECT, 2018
** int_to_str
** File description:
** int_to_str
*/

#include "asm.h"

int calc_length(long int x)
{
	int result = 0;

	if (x == 0)
		return (1);
	if (x < 0)
		result += 1;
	while (x != 0) {
		x /= 10;
		result += 1;
	}
	return (result);
}

char *int_to_str(long int y, char *result)
{
	long int x = y;
	int i = calc_length(y);
	int negativ = (y < 0 ? -1 : 1);

	if (y == -2147483648)
		return (my_strdup("-2147483648"));
	if (y < 0) {
		result[0] = '-';
		y *= -1;
	}
	if (y == 0)
		result[0] = '0';
	else
		for (i = i - 1 ; y != 0 ; i--) {
			result[i] = y % (10 * negativ) + 48;
			y /= 10;
		}
	result[calc_length(x)] = '\0';
	return (result);
}
