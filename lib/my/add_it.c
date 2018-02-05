/*
** EPITECH PROJECT, 2017
** add_it
** File description:
** add a character to a string
*/

#include "my.h"

char *add_it(char const *str, char const c, int const pos)
{
	int a = 0;
	char *returned = 0;
	int len = my_strlen(str);

	returned = my_malloc(sizeof(char) * (len + 2));
	for (a = 0; a < (len + 1); a++) {
		a == pos ? returned[a] = c : 0;
		a < pos ? returned[a] = str[a] : 0;
		a > pos ? returned[a] = str[a - 1] : 0;
	}
	returned[a] = 0;
	return (returned);
}
