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
		if (tab[i][0] == LABEL_CHAR ||\
		(tab[i][0] == DIRECT_CHAR && tab[i][1] == LABEL_CHAR)) {
			check_label_gram(tab[i] + 2);
			continue;
		}
		if ((tab[i][0] == 'r' || tab[i][0] == DIRECT_CHAR)\
		&& tab[i][1] != '\0')
			tab[i]++;
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
			my_puterror(ERROR"Labels should be written only with"
				" LABEL_CHAR\n");
			exit(84);
		}
	}
}

void check_gram(char *tab)
{
	if (my_strlen(tab) < 1) {
		my_puterror(ERROR"Wrong arg\n");
		exit(84);
	}
	for (int i = 0 ; tab[i] ; i++)
		if (tab[i] < '0' || tab[i] > '9') {
			my_puterror(ERROR"Directs and indirects args should be only"
				" composed of numericals characters\n");
			exit(84);
		}
}
