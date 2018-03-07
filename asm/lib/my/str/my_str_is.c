/*
** EPITECH PROJECT, 2017
** str functions
** File description:
** str related functions
*/

#include "my.h"

int my_str_isalpha(char const *str)
{
	int strlen = my_strlen(str);
	char c;

	for (int i = 0; i < strlen; i++) {
		c = str[i];
		if (!((c > 64 && c < 91) || (c > 96 && c < 123)))
			return (0);
	}
	return (1);
}

int my_str_islower(char const *str)
{
	int strlen = my_strlen(str);

	for (int i = 0; i < strlen; i++)
		if (!(str[i] >= 'a' && str[i] <= 'z'))
			return (0);
	return (1);
}

int my_str_isnum(char const *str)
{
	int strlen = my_strlen(str);

	for (int i = 0; i < strlen; i++)
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	return (1);
}

int my_str_isprintable(char const *str)
{
	int strlen = my_strlen(str);

	for (int i = 0; i < strlen; i++)
		if ((str[i] >= 0 && str[i] <= 31) || str[i] == 127)
			return (0);
	return (1);
}

int my_str_isupper(char const *str)
{
	int strlen = my_strlen(str);

	for (int i = 0; i < strlen; i++)
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
			return (0);
	return (1);
}
