/*
** EPITECH PROJECT, 2018
** label
** File description:
** handling of labels
*/

#include "asm.h"

void fill_label_call(char *str, int fd, label_t *label)
{
	call_t **call = &(label->call);

	fd = fd;
	while (*call)
		*call = (*call)->next;
	*call = malloc(sizeof(call_t));
	(*call)->name = my_strdup(str);
	(*call)->abs_pos = label->current_pos;
	(*call)->rel_pos = -1;
	(*call)->next = NULL;
	printf("fill label call, name: %s, abs pos = %d\n", (*call)->name, (*call)->abs_pos);
}

void fill_label_decla(char *str, int fd, label_t *label)
{
	decla_t **decla = &(label->decla);

	fd = fd;
	while (*decla)
		*decla = (*decla)->next;
	*decla = malloc(sizeof(decla_t));
	(*decla)->name = my_strdup(str);
	(*decla)->pos = label->current_pos;
	(*decla)->next = NULL;
	printf("fill label decla, name: %s, abs pos = %d\n", (*decla)->name, (*decla)->pos);
}

void printf_linked_list(call_t *call, decla_t *decla)
{
	call = call;
	decla = decla;

//	printf("call de %s pos %d\n", call->name, call->abs_pos);
//	printf("decla de %s pos %d\n", decla->name, decla->pos);
	for (call = call ; call ; call = call->next)
		printf("call de %s pos %d\n", call->name, call->abs_pos);
	for (decla = decla ; decla ; decla = decla->next)
		printf("decla de %s pos %d\n", decla->name, decla->pos);
}
