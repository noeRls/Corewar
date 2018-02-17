/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** verif_header
*/

#include "asm.h"

static void verif_name(char **tab, int *name)
{
	(*name)++;
	if (my_strlen(tab[1]) > PROG_NAME_LENGTH) {
		my_puterror(ERROR"prog name too long.\n");
		exit(84);
	}
}

static void verif_comment_before_name(char **tab, int name)
{
	if (!my_strcmp(tab[0], COMMENT_CMD_STRING) && !name) {
		my_puterror(ERROR"The name must be specified\n");
		my_puterror(" just before the comment.\n");
		exit(84);
	}
}

static void verif_comment(char **tab, int *comment)
{
	comment++;
	if (my_strlen(tab[1]) > COMMENT_LENGTH) {
		my_puterror(ERROR"comment too long.\n");
		exit(84);
	}
}

static void verif_comment_name(char *s, int comment, int name, int fd)
{
	if (!comment)
		my_puterror(WARNING"no comment specify\n");
	if (!name) {
		my_puterror(ERROR"No name specified\n");
		exit(84);
	}
	if (name > 1) {
		my_puterror(ERROR"The name can only be defined once.\n");
		exit(84);
	}
	if (comment > 1) {
		my_puterror(ERROR"The comment can only be defined once.\n");
		exit(84);
	}
	lseek(fd, (my_strlen(s) + 1) * -1, SEEK_CUR);
}

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
			verif_name(tab, &name);
			continue;
		}
		verif_comment_before_name(tab, name);
		if (!my_strcmp(tab[0], COMMENT_CMD_STRING)) {
			verif_comment(tab, &name);
			continue;
		}
		break;
	}
	verif_comment_name(s, comment, name, fd);
}
