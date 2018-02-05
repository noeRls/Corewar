/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** write_instruction
*/

#include "asm.h"

int write_instruction(char *cmd, int fd)
{
	extern op_t op_tab[];

	for (char i = 0; op_tab[i].mnemonique != 0; i++) {
		if (my_strcmp(cmd, op_tab[i].mnemonique) == 0) {
			++i;
			write(fd, &i, sizeof(i));
			return (int)i;
		}
	}
}
