/*
** EPITECH PROJECT, 2018
** grammar
** File description:
** verify the grammar of args
*/

#include "asm.h"

void verif_gram(char **tab)
{
	for (int i = 0 ; tab[i] ; i++) {
		if (tab[i][0] == LABEL_CHAR ||
		(tab[i][0] == DIRECT_CHAR && tab[i][1] == LABEL_CHAR)) {
			check_label_gram(tab[i] + 2);
			continue;
		}
		check_gram(tab[i]);
	}
}

void check_label_gram(char *tab)
{
	if (my_strlen(tab) == 0) {
		my_puterror(ERROR"Empty label\n");
		exit(84);
	}
	for (int i = 0 ; tab[i] ; i++) {
		if (!contains(LABEL_CHARS, tab[i])) {
			my_puterror(ERROR"Labels should be written only with");
			my_puterror(" LABEL_CHARS\n");
			exit(84);
		}
	}
}

void check_gram(char *tab)
{
	if (tab[0] == 'r') {
		tab++;
		if (getnbr(tab) < 1 || getnbr(tab) > 16) {
			my_puterror(ERROR"Registers shall ");
			my_puterror("be between r1 and REG_NUMBER\n");
			exit(84);
		}
	} else if (tab[0] == DIRECT_CHAR)
		tab++;
	if (my_strlen(tab) < 1) {
		my_puterror(ERROR"Empty argument\n");
		exit(84);
	}
	tab[0] == '-' ? tab++ : 0;
	for (int i = 0 ; tab[i] ; i++)
		if (tab[i] < '0' || tab[i] > '9') {
			my_puterror(ERROR"Directs and indirects args should ");
			my_puterror("be  composed of numericals characters\n");
			exit(84);
		}
}
