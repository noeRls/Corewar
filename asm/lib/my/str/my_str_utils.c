/*
** EPITECH PROJECT, 2017
** str utils
** File description:
** str tools functions
*/

#include <stdlib.h>
#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
	int i = 0;

	for (i = 0; src[i]; i++) {
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

char *my_strncpy(char *dest, char const *src, int n)
{
	int i = 0;

	for (i = 0; i < n && src[i]; i++) {
		dest[i] = src[i];
	}
	dest[i] = 0;
	return (dest);
}

char *my_strcat(char *dest, char const *src)
{
	int destlen = my_strlen(dest);
	int srclen = my_strlen(src);

	for (int i = 0; i < srclen; i++) {
		dest[destlen + i] = src[i];
	}
	dest[destlen + srclen] = '\0';
	return (dest);
}

char *my_strncat(char *dest, char const *src, int nb)
{
	int destlen = my_strlen(dest);
	int srclen = my_strlen(src);
	int i = 0;

	for (i = 0; i < srclen && i < nb; i++) {
		dest[destlen + i] = src[i];
	}
	dest[destlen + i] = '\0';
	return (dest);
}

char *my_strdup(char const *src)
{
	char *str;
	int i = 0;

	str = MALLOC(sizeof(char) * (my_strlen(src) + 1));
	for (i = 0; src[i]; i++) {
		str[i] = src[i];
	}
	str[i] = 0;
	return (str);
}
