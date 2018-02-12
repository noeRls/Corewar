/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** write_instruction
*/

#include "asm.h"

int write_instruction(char *cmd, int fd, label_t *label)
{
	for (char i = 0; op_tab[(int)i].mnemonique != 0; i++) {
		if (my_strcmp(cmd, op_tab[(int)i].mnemonique) == 0) {
			label->tmp_pos += 1;
			++i;
			write(fd, &i, sizeof(i));
			--i;
			return (int)i;
		}
	}
	return (-1);
}
