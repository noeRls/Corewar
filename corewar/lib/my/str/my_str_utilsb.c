/*
** EPITECH PROJECT, 2017
** str utils second
** File description:
** second str utils
*/

#include "my.h"

int my_strlen(char const *str)
{
	int i = 0;

	for (i = 0; str[i]; i++) {}
	return (i);
}

int my_strlento(char const *str, char c)
{
	int i = 0;

	for (i = 0; str && str[i]; i++) {
		if (str[i] == c)
			return (i);
	}
	return (i);
}

char *my_strlowcase(char *str)
{
	int index = 0;

	while (str[index] != '\0') {
		if (str[index] >= 65 && str[index] <= 90) {
			str[index] = str[index] + 32;
		}
		index = index + 1;
	}
	return (str);
}

char *my_strupcase(char *str)
{
	int index = 0;

	while (str[index] != '\0') {
		if (str[index] >= 97 && str[index] <= 122) {
			str[index] = str[index] - 32;
		}
		index = index + 1;
	}
	return (str);
}

char *my_revstr(char *str)
{
	int strlen = 0;

	if (my_strlen(str) > 1) {
		strlen = my_strlen(str) - 1;
		for (int i = 0; i < strlen / 2 + 1; i++) {
			my_swap_char(&str[i], &str[strlen - i]);
		}
		return (str);
	} else {
		return (str);
	}
}
