/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** verif_header
*/

#include "asm.h"

void verif_header(int fd)
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
			if (my_strlen(tab[1]) > PROG_NAME_LENGTH) {
				my_putstr("error: prog name too long.\n");
				exit(84);
			}
			continue;
		}
		if (!my_strcmp(tab[0], COMMENT_CMD_STRING) && !name) {
			my_putstr("asm: error: The name must be specified\n");
			my_putstr(" just before the comment.\n");
			exit(84);
		}
		if (!my_strcmp(tab[0], COMMENT_CMD_STRING)) {
			comment++;
			if (my_strlen(tab[1]) > COMMENT_LENGTH) {
				my_putstr("error: comment too long.\n");
				exit(84);
			}
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
	lseek(fd, my_strlen(s) * -1, SEEK_CUR);
}
