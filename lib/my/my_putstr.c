/*
** EPITECH PROJECT, 2017
** my_putsyr
** File description:
** display_characters_of_a_string
*/

#include "my.h"

int my_putstr(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		my_putchar(str[i]);
		i++;
	}
	return (0);
}
