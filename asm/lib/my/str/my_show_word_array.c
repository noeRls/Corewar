/*
** EPITECH PROJECT, 2017
** my_show_word_array
** File description:
** show word array
*/

#include "my.h"

void my_show_word_array(char * const *tab)
{
	for (int i = 0; tab[i] != 0; i++) {
		my_putstr(tab[i]);
		my_putchar('\n');
	}
}
