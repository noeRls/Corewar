/*
** EPITECH PROJECT, 2017
** my_str_isalpha
** File description:
** returns 1 if the string passed as parameter only contains alphabetical c
*/

#include "my.h"

int my_str_isalpha(char const *s)
{
	int i = 0;
	int lenght = 0;

	lenght = my_strlen(s);
	if (lenght == 0)
		return (1);
	while (s[i] != '\0') {
		if (!((s[i] > 96 && s[i] < 123) || (s[i] > 64 && s[i] < 91)))
			return (0);
		i++;
	}
	return (1);
}
