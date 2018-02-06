/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** header
*/

#include "asm.h"

int fill_header(char **tab, header_t *header)
{
	header->magic = COREWAR_EXEC_MAGIC;
	if (!my_strcmp(tab[0], ".name")) {
		my_strcpy(header->prog_name, tab[1]);
		return (1);
	}
	if (!my_strcmp(tab[0], ".comment")) {
		my_strcpy(header->comment, tab[1]);
		return (1);
	}
	return (0);
}
