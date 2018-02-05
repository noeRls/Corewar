/*
** EPITECH PROJECT, 2017
** my_strlowcase
** File description:
** puts every letter of every word in it in lowercase
*/

#include "my.h"

char *my_strlowcase(char *str)
{
	int i = 0;
	int len = 0;

	len = my_strlen(str);
	if (len == 0)
		return (str);
	while (str[i] != '\0') {
		if (str[i] > 64 && str[i] < 91)
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
