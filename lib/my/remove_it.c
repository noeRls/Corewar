/*
** EPITECH PROJECT, 2017
** remove_it
** File description:
** remove a character in a string at index c
*/

#include "my.h"

char *remove_it(char* str, int c)
{
	while (str[c + 1]) {
		str[c] = str[c + 1];
		c++;
	}
	str[c] = 0;
	return (str);
}
