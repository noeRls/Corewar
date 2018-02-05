/*
** EPITECH PROJECT, 2017
** my_strdup
** File description:
** allocates memory and copies the string given as argument in it
*/

#include "my.h"

char *my_strdup(char const *src)
{
	int i = 0;
	int lsrc = 0;
	char *returned = 0;

	lsrc = my_strlen(src);
	returned = my_malloc(sizeof(char) * (lsrc + 1));
	while (src[i] != '\0') {
		returned[i] = src[i];
		i++;
	}
	returned[i] = '\0';
	return (returned);
}
