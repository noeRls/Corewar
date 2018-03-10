/*
** EPITECH PROJECT, 2017
** display tools
** File description:
** display tools for my_printf
*/

#include "my.h"
#include "display_f.h"

void replace(char *str, char tf, char tr)
{
	for (int i = 0; str[i]; i++) {
		if (str[i] == tf)
			str[i] = tr;
	}
}

void *check_null(void *ptr)
{
	if (!ptr)
		return (my_strdup("(null)"));
	return (ptr);
}

int my_putchars(char c, int times)
{
	int i = 0;

	for (i = 0; i < times; i++)
		my_putchar(c);
	return (i + 1);
}

int count_np(char *str)
{
	int count = 0;

	for (int i = 0; str[i]; i++) {
		if (!my_char_isprintable(str[i]))
			count++;
	}
	return (count);
}

int b_digits(int nb, int b)
{
	int dg = 0;

	while (nb != 0) {
		nb /= b;
		dg++;
	}
	return (dg);
}
