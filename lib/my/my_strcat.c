/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** concatenates two strings
*/

#include "my.h"

int goto_end_string(char const *dest, char *returned, int i)
{
	if (!dest || dest[i] == '\0')
		return (i);
	returned[i] = dest[i];
	i++;
	return (goto_end_string(dest, returned, i));
}

char *my_strcat(char const *dest, char const *src)
{
	int i = 0;
	int b = 0;
	char *returned = my_malloc(my_strlen(dest) + my_strlen(src) + 1);

	i = goto_end_string(dest, returned, i);
	while (src && src[b] != '\0') {
		returned[i + b] = src[b];
		b ++;
	}
	returned[i + b] = '\0';
	return (returned);
}
