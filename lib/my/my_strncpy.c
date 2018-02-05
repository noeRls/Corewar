/*
** EPITECH PROJECT, 2017
** my_strncpy
** File description:
** copies n characters from a string into another
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
	int i = 0;
	char *returned;

	returned = my_malloc(sizeof(char) * (n + 1));
	while (src[i] != '\0' && n > i) {
		returned[i] = src[i];
		i++;
	}
	returned[i] = '\0';
	dest = returned;
	return (dest);
}
