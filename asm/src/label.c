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
	call->name = my_strdup(str);
	call->abs_pos = ;
	call->rel_pos = ;
	call->next = NULL;
}

void fill_label_decla(char *str, int fd, int mnemonique, label_t *label)
{
	decla_t *decla = label->decla;

	while (decla->next)
		decla = decla->next;
}
