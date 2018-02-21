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

	str[my_strlen(str) - 1] = '\0';
	check_label_gram(str);
	if (decla == NULL) {
		label->decla = MALLOC(sizeof(decla_t));
		decla = label->decla;
	} else {
		while (decla->next)
			decla = decla->next;
		decla->next = MALLOC(sizeof(decla_t));
		decla = decla->next;
	}
	decla->name = my_strdup(str);
	decla->next = NULL;
	return (shift_tab(tab));
}

void verif_loop(int fd, label_t *label)
{
	char *s;
	char **tab;
	int mnemonique;

	while ((s = get_next_line(fd))) {
		if (!(*s))
			continue;
		clear_comment(s);
		tab = str_to_av(s);
		if (tab[0] == NULL)
			continue;
		if (get_arg_type(tab[0]) == LABEL_DECLARATION)
			tab = add_label_decla(tab, label);
		if (tab[0] == NULL)
			continue;
		mnemonique = get_mnemonique(tab[0]);
		verif_nb_arg(mnemonique, tab, label);
		verif_arg_type(mnemonique, tab);
		verif_gram(&tab[1]);
	}
}

int verif(char *path)
{
	label_t *label = init_label();
	int fd = open(path, O_RDONLY);

	verif_header(fd);
	verif_loop(fd, label);
	verif_label(label);
	close(fd);
	return (open(file_to_cor(path), O_RDWR | O_CREAT, 0666));
}
