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

	for (i = 0 ; tab[i] ; i++);
	if (i - 1 != op_tab[mnemonic].nbr_args) {
		my_puterror("invalid number of arguments\n");
		exit(84);
	}
}

void verif_arg_type(int mnemonic, char **tab)
{
	for (int i = 1 ; tab[i] ; i++) {

	}
}

void verif_syntax(int mnemonic, char **tab)
{
	verif_nb_arg(mnemonic, tab);
	verif_arg_type(mnemonic, tab);
}
