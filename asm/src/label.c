/*
** EPITECH PROJECT, 2018
** label
** File description:
** handling of labels
*/

#include "asm.h"

void fill_label_call(char *str, int fd, int mnemonique, label_t *label)
{
	call_t *call = label->call;

	while (call->next)
		call = call->next;
	call->next = malloc(sizeof(call_t));
	call = call->next;
	call->name = my_strdup(str);
	call->abs_pos = label->current_pos;
	call->rel_pos = -1;
	call->next = NULL;
}

void fill_label_decla(char *str, int fd, int mnemonique, label_t *label)
{
	decla_t *decla = label->decla;

	while (decla->next)
		decla = decla->next;
	decla->next = malloc(sizeof(decla_t));
	decla = decla->next;
	decla->name = my_strdup(str);
	decla->pos = label->current_pos;
	decla->next = NULL;
}
