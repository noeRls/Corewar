/*
** EPITECH PROJECT, 2018
** verif_syntax
** File description:
** verify the syntax of a command line
*/

#include "asm.h"

void check_label_gramm(char *tab)
{
	if (my_strlen(tab) == 0) {
		my_puterror("Empty label\n");
		exit(84);
	}
	for (int i = 0 ; tab[i] ; i++) {
		if (!contains(LABEL_CHARS, tab[i])) {
			my_puterror("Labels should be written only with"
				" LABEL_CHAR\n");
			exit(84);
		}
	}
}

void check_gram(char *tab)
{
	if (my_strlen(tab) < 1) {
		my_puterror("Wrong arg\n");
		exit(84);
	}
	for (int i = 0 ; tab[i] ; i++)
		if (tab[i] < '0' || tab[i] > '9') {
			my_puterror("Directs and indirects args should be only"
				" composed of numericals characters\n");
			exit(84);
		}
}

void verif_gram(char **tab)
{
	for (int i = 0 ; tab[i] ; i++) {
		if (tab[i][0] == LABEL_CHAR ||\
		    (tab[i][0] == DIRECT_CHAR && tab[i][1] == LABEL_CHAR)) {
			check_label_gramm(tab[i] + 2);
			continue;
		}
		if ((tab[i][0] == 'r' || tab[i][0] == DIRECT_CHAR) && tab[i][1] != '\0')
			tab[i]++;
		check_gram(tab[i]);
	}
}

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
		if (tab[i][0] == DIRECT_CHAR) {
			if ((op_tab[mnemonic].type[i - 1] & T_DIR) == 0) {
				my_puterror("Invalid type of arguments\n");
				exit(84);
			}
		} else if (tab[i][0] == 'r') {
			if ((op_tab[mnemonic].type[i - 1] & T_REG) == 0) {
				my_puterror("Invalid type of arguments\n");
				exit(84);
			}
		} else {
			if ((op_tab[mnemonic].type[i - 1] & T_IND) == 0) {
				my_puterror("Invalid type of arguments\n");
				exit(84);
			}
		}
	}
}

int get_mnemonique(char *tab)
{
	for (int i = 0; op_tab[i].mnemonique != 0; i++)
		if (my_strcmp(tab, op_tab[i].mnemonique) == 0)
			return (i);
	my_puterror("Opcode unrecognized\n");
	exit(84);
	return (-1);
}

void verif_syntax(char *path)
{
	char *s;
	char **tab;
	int mnemonique;
	int fd = open(path, O_RDONLY);

	verif_header(fd);
	//TODO: verif the line returned by the function
	while ((s = get_next_line(fd))) {
		if (!(*s))
			continue;
		clear_comment(s);
		tab = str_to_av(s);
		if (tab[0] == NULL)
			continue;
		mnemonique = get_mnemonique(tab[0]);
		verif_nb_arg(mnemonique, tab);
		verif_arg_type(mnemonique, tab);
		verif_gram(&tab[1]);
	}
}
