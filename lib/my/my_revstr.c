/*
** EPITECH PROJECT, 2017
** my_revstr
** File description:
** reverse_the_string
*/

#include "my.h"

char *my_revstr(char *str)
{
	int lenght = 0;
	int i = 0;
	char tmp = 0;

	lenght = my_strlen(str);
	if (lenght % 2 == 0) {
		while (i < (lenght / 2)) {
			tmp = str[i];
			str[i] = str[lenght - i - 1];
			str[lenght - i - 1] = tmp;
			i++;
		}
	} else {
		for (i = 0; i < (lenght / 2); i++) {
			tmp = str[i];
			str[i] = str[lenght - i - 1];
			str[lenght - i - 1] = tmp;
		}
	}
	return (str);
}
