/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** count_the_number_of_character
*/

#include "my.h"

int my_strlen(char const *str)
{
	int i = 0;

	if (!str)
		return (0);
	while (str[i] != '\0') {
		i++;
	}
	return (i);
}
