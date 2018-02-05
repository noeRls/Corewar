/*
** EPITECH PROJECT, 2017
** my_strnncpy
** File description:
** copy from x bythe n bythe of src string to dest string
*/

#include "my.h"

char *my_strnncpy(char *dest, char const *src, int x, int n)
{
	int i = 0;
	int c = 0;

	while (src[i] != 0 && i < x) {
		i++;
	}
	while (src[i] != '\0' && n > c) {
		dest[c] = src[i];
		i++;
		c ++;
	}
	dest[c] = '\0';
	return (dest);
}
