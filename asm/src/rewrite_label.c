/*
** EPITECH PROJECT, 2018
** rewrite_label
** File description:
** rewrite file to replace labels by the good value
*/

#include "asm.h"

void change_label(int fd, call_t *call, decla_t *decla, label_t *label)
{
	int final_pos;
	char *tmp = malloc(sizeof(char) * 10);

	if (!my_strcmp(call->name, decla->name)) {
		final_pos = decla->pos - call->abs_pos;
		if (final_pos < 0)
			final_pos--;
		printf("valeur %ld en %ld\n", final_pos, call->rel_pos);
		lseek(fd, call->rel_pos, SEEK_SET);
		if (call->type == DIRECT) {
			write_direct_arg(int_to_str(final_pos, tmp), fd, 0, label);
		} else {
			write_indirect_arg(int_to_str(final_pos, tmp), fd, label);
		}
	}
	free(tmp);
}

void rewrite_label(int fd, label_t *label)
{
	for (call_t *call = label->call ; call ; call = call->next) {
		for (decla_t *decla = label->decla ; decla ; decla = decla->next) {
			change_label(fd, call, decla, label);
		}
	}
}
