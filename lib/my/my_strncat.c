/*
** EPITECH PROJECT, 2017
** my_strncat
** File description:
** concatenates two strings, n c of last one
*/

#include "my.h"

int goto_end_str(char const *dest, int i)
{
	if (dest[i] == '\0')
		return (i);
	i++;
	return (goto_end_str(dest, i));
}

char *my_strncat(char *dest, char const *src, int n)
{
	int i = 0;
	int b = 0;
	int lenght = 0;

	i = goto_end_str(dest, i);
	while (src[b] != '\0' && b + i < n) {
		dest[i + b] = src[b];
		b ++;
	}
	lenght = my_strlen(dest);
	if (n > lenght)
		dest[i + b] = '\0';
	return (dest);
}
