/*
** EPITECH PROJECT, 2017
** my_str_isnum
** File description:
** returns 1 if the string passed as parameter only contains digits
*/

#include "my.h"

int my_str_isnum(char const *str)
{
	int i = 0;

	if (!str)
		return (0);
	if (str[i] == '-' && str[i + 1])
		i++;
	for (i = i; str[i]; i++)
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}
