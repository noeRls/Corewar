/*
** EPITECH PROJECT, 2018
** verif
** File description:
** verification of the validity of the assembly code
*/

#include "asm.h"

int verif(char *path)
{
	char *s;
	char **tab;
	int mnemonique;
	int fd = open(path, O_RDONLY);

	verif_header(fd);
	while ((s = get_next_line(fd))) {
		if (!(*s))
			continue;
		clear_comment(s);
		tab = str_to_av(s);
		if (tab[0] == NULL)
			continue;
		if (get_arg_type(tab[0]) == LABEL_DECLARATION) {
			tab[0][my_strlen(tab[0]) - 1] = '\0';
			check_label_gram(tab[0]);
			tab = shift_tab(tab);
		}
		if (tab[0] == NULL)
			continue;
		mnemonique = get_mnemonique(tab[0]);
		verif_nb_arg(mnemonique, tab);
		verif_arg_type(mnemonique, tab);
		verif_gram(&tab[1]);
	}
	close(fd);
	return (open(file_to_cor(path), O_RDWR | O_CREAT, 0666));
}
