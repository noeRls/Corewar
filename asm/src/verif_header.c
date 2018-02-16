/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** verif_header
*/

#include "asm.h"

char *verif_header(int fd)
{
	int name = 0;
	int comment = 0;
	char **tab;
	char *s = NULL;

	while ((s = get_next_line(fd))) {
		clear_comment(s);
		tab = str_to_av(s);
		if (!tab[0])
			continue;
		if (!my_strcmp(tab[0], NAME_CMD_STRING)) {
			name++;
			continue;
		}
		if (!my_strcmp(tab[0], COMMENT_CMD_STRING) && !name) {
			my_putstr("asm: error: The name must be specified\n");
			my_putstr(" just before the comment.\n");
			exit(84);
		}
		if (!my_strcmp(tab[0], COMMENT_CMD_STRING)) {
			comment++;
			continue;
		}
		break;
	}
	if (!comment)
		my_putstr("Waring: no comment specify\n");
	if (!name) {
		my_putstr("asm: error: No name specified\n");
		exit(84);
	}
	if (name > 1) {
		my_putstr("error: The name can only be defined once.\n");
		exit(84);
	}
	if (comment > 1) {
		my_putstr("error: The comment can only be defined once.\n");
		exit(84);
	}
	return (s);
}
