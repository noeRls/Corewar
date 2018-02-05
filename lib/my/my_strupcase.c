/*
** EPITECH PROJECT, 2017
** my_strupcase
** File description:
** every letter of every word in it in uppercase
*/

#include "my.h"

char *my_strupcase(char *str)
{
	int i = 0;
	int len = 0;

	len = my_strlen(str);
	if (len == 0)
		return (str);
	while (str[i] != '\0') {
		if (str[i] > 96 && str[i] < 123)
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
