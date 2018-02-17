/*
** EPITECH PROJECT, 2018
** get_mnemonique
** File description:
** return the mnemonique of an opcode
*/

#include "asm.h"

int get_mnemonique(char *tab)
{
	for (int i = 0; op_tab[i].mnemonique != 0; i++)
		if (my_strcmp(tab, op_tab[i].mnemonique) == 0)
			return (i);
	my_puterror("Opcode unrecognized\n");
	exit(84);
	return (-1);
}
