/*
** EPITECH PROJECT, 2018
** verif_syntax
** File description:
** verify the syntax of a command line
*/

#include "asm.h"

void add_label_call(char *str, label_t *label)
{
	call_t *call = label->call;

	goto_last_label_call(&call, label);
	if (str[0] == LABEL_CHAR)
		call->name = my_strdup(str + 1);
	else
		call->name = my_strdup(str + 2);
	call->next = NULL;
}

void verif_nb_arg(int mnemonic, char **tab, label_t *label)
{
	int i;

	for (i = 0 ; tab[i] ; i++) {
		if (get_arg_type(tab[i]) == LABEL_CALL)
			add_label_call(tab[i], label);
	}
	if (i - 1 != op_tab[mnemonic].nbr_args) {
		my_puterror(ERROR"Invalid number of arguments\n");
		exit(84);
	}
}

void check_type(int mnemonic, int i, int expected)
{
	if ((op_tab[mnemonic].type[i - 1] & expected) == 0) {
		my_puterror(ERROR"Invalid type of arguments\n");
		exit(84);
	}
}

void verif_arg_type(int mnemonic, char **tab)
{
	for (int i = 1 ; tab[i] ; i++) {
		if (tab[i][0] == DIRECT_CHAR)
			check_type(mnemonic, i, T_DIR);
		else if (tab[i][0] == 'r')
			check_type(mnemonic, i, T_REG);
		else
			check_type(mnemonic, i, T_IND);
	}
}
