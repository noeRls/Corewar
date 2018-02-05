/*
** EPITECH PROJECT, 2018
** coding_byte
** File description:
** write the coding byte
*/

#include "asm.h"

//r for register, which means, 01
//DIRECT_CHAR for direct char, which means, 10
//alphanumeric for indirect char, which means 11
//to add further: % to a label, which means indirect char too

arg_type get_arg_type(char *str)
{
	if (contains(str, LABEL_CHAR))
		return (LABEL);
	if (str[0] == 'r')
		return (REGISTER);
	if (str[0] == DIRECT_CHAR)
		return (DIRECT);
	return (INDIRECT);
}

void write_coding_byte(char **tab, int fd)
{
	char buffer[4] = {0, 0, 0, 0};
	arg_type type;

	for (int i = 1; tab[i]; i++) {
		type = get_arg_type(tab[i]);
		if (type == REGISTER)
			buffer[i - 1] = 1;
		if (type == DIRECT)
			buffer[i - 1] = 2;
		if (type == INDIRECT || type == LABEL)
			buffer[i - 1] = 3;
	}
}
