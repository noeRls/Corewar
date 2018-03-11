/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** verif_header
*/

#include "asm.h"

static int verif_name(char **tab, int *name)
{
	if (!my_strcmp(tab[0], NAME_CMD_STRING)) {
		(*name)++;
		if (!tab[1]) {
			my_puterror(ERROR"prog name not specified\n");
			exit(84);
		}
		if (tab[2]) {
			my_puterror(ERROR"name error\n");
			exit(84);
		}
		if (my_strlen(tab[1]) > PROG_NAME_LENGTH) {
			my_puterror(ERROR"Program name too long.\n");
			exit(84);
		}
		return (1);
	}
	return (0);
}

static void verif_comment_before_name(char **tab, int name)
{
	if (!my_strcmp(tab[0], COMMENT_CMD_STRING) && !name) {
		my_puterror(ERROR"The name must be specified");
		my_puterror(" just before the comment.\n");
		exit(84);
	}
}

static void verif_comment(char **tab, int *comment)
{
	(*comment)++;
	if (!tab[1]) {
		my_puterror(ERROR"comment not specified\n");
		exit(84);
	}
	if (tab[2]) {
		my_puterror(ERROR"comment error\n");
		exit(84);
	}
	if (my_strlen(tab[1]) > COMMENT_LENGTH) {
		my_puterror(ERROR"Comment too long.\n");
		exit(84);
	}
}

void verif_comment_name(size_t len, int comment, int name, int fd)
{
	if (!comment)
		my_puterror(WARNING"No comment specified\n");
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
	if (len != 0)
		lseek(fd, (len + 1) * -1, SEEK_CUR);
}

int verif_header_loop(char *s, int *name, int *comment, size_t *len)
{
	char **tab;

	*len = my_strlen(s);
	clear_comment(s);
	check_special_case(s);
	tab = str_to_av(s);
	if (!tab[0]) {
		*len = 0;
		return (0);
	}
	if (verif_name(tab, name))
		return (0);
	verif_comment_before_name(tab, *name);
	if (!my_strcmp(tab[0], COMMENT_CMD_STRING)) {
		verif_comment(tab, comment);
		return (0);
	}
	return (1);
}
