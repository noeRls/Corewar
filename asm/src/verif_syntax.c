/*
** EPITECH PROJECT, 2018
** verif_syntax
** File description:
** verify the syntax of a command line
*/

#include "asm.h"

void verif_nb_arg(int mnemonic, char **tab)
{
	int i;
	extern op_t op_tab[];

	for (i = 0 ; tab[i] ; i++);
	if (i - 1 != op_tab[mnemonic].nbr_args) {
		my_puterror("invalid number of arguments\n");
		exit(84);
	}
}

void verif_syntax(int mnemonic, char **tab)
{
	verif_nb_arg(mnemonic, tab);
}
