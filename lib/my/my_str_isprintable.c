/*
** EPITECH PROJECT, 2017
** my_str_isprintable
** File description:
** returns 1 if the string passed is printable and 0 if not
*/

#include "my.h"

int my_str_isprintable(char const *str)
{
	int i = 0;
	int lenght = 0;

	lenght = my_strlen(str);
	if (lenght == 0)
		return (1);
	while (str[i] != '\0') {
		if (str[i] < 32 || str[i] == 127)
			return (0);
		i++;
	}
	return (1);
}
