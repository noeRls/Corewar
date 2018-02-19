/*
** EPITECH PROJECT, 2018
** verif
** File description:
** verification of the validity of the assembly code
*/

#include "asm.h"

char **add_label_decla(char **tab, label_t *label)
{
	decla_t *decla = label->decla;
	char *str = tab[0];

	if (decla == NULL) {
		label->decla = malloc(sizeof(decla_t));
		decla = label->decla;
	} else {
		while (decla->next)
			decla = decla->next;
		decla->next = malloc(sizeof(decla_t));
		decla = decla->next;
	}
	decla->name = my_strdup(str);
	decla->next = NULL;
	return (shift_tab(tab));
}

int verif(char *path)
{
	label_t *label = init_label();
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
			tab = add_label_decla(tab, label);
		}
		if (tab[0] == NULL)
			continue;
		mnemonique = get_mnemonique(tab[0]);
		verif_nb_arg(mnemonique, tab, label);
		verif_arg_type(mnemonique, tab);
		verif_gram(&tab[1]);
	}
	verif_label(label);
	close(fd);
	return (open(file_to_cor(path), O_RDWR | O_CREAT, 0666));
}
