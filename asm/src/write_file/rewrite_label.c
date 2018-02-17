/*
** EPITECH PROJECT, 2018
** rewrite_label
** File description:
** rewrite file to replace labels by the good value
*/

#include "asm.h"

void write_direct_label(int x, int fd)
{
	unsigned int tmp = (unsigned int) x;

	magic_reverse(&tmp);
	write(fd, &tmp, sizeof(unsigned int));
}

void write_indirect_label(int x, int fd)
{
	unsigned short int tmp = (unsigned short int) x;

	short_magic_reverse(&tmp);
	write(fd, &tmp, sizeof(unsigned short int));
}

void change_label(int fd, call_t *call, decla_t *decla)
{
	int final_pos;

	if (!my_strcmp(call->name, decla->name)) {
		final_pos = decla->pos - call->abs_pos;
		lseek(fd, call->rel_pos, SEEK_SET);
		if (call->type == DIRECT)
			write_direct_label(final_pos, fd);
		else
			write_indirect_label(final_pos, fd);
	}
}

void rewrite_label(int fd, label_t *label)
{
	for (call_t *call = label->call ; call ; call = call->next) {
		for (decla_t *decla = label->decla; decla; decla = decla->next)
			change_label(fd, call, decla);
	}
}
