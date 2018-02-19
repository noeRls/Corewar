/*
** EPITECH PROJECT, 2018
** coding_byte
** File description:
** write the coding byte
*/

#include "asm.h"

arg_type get_arg_type(char *str)
{
	if (contains(str, LABEL_CHAR)) {
		if (str[my_strlen(str) - 1] != ':')
			return (LABEL_CALL);
		if (str[my_strlen(str) - 1] == ':')
			return (LABEL_DECLARATION);
	}
	if (str[0] == 'r')
		return (REGISTER);
	if (str[0] == DIRECT_CHAR)
		return (DIRECT);
	return (INDIRECT);
}

void write_coding_byte(char **tab, int fd, label_t *label)
{
	char c = 0;
	arg_type type;

	if (!my_strcmp(tab[0], "live") || !my_strcmp(tab[0], "zjmp")
	|| !my_strcmp(tab[0], "fork") || !my_strcmp(tab[0], "lfork"))
		return;
	for (int i = 1; tab[i]; i++) {
		type = get_arg_type(tab[i]);
		if (type == REGISTER)
			c = c ^ (85 & (192 >> (i - 1) * 2));
		if (tab[i][0] == DIRECT_CHAR)
			c = c ^ (170 & (192 >> (i - 1) * 2));
		if (tab[i][0] != DIRECT_CHAR && tab[i][0] != 'r')
			c = c ^ (255 & (192 >> (i - 1) * 2));
	}
	write(fd, &c, sizeof(char));
	label->tmp_pos += 1;
}
