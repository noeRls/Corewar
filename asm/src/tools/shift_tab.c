/*
** EPITECH PROJECT, 2018
** shift_tab
** File description:
** shift tab
*/

#include "asm.h"

char **shift_tab(char **tab)
{
	int i;

	for (i = 1 ; tab[i] ; i++)
		tab[i - 1] = tab[i];
	tab[i - 1] = tab[i];
	return (tab);
}
