/*
** EPITECH PROJECT, 2018
** run
** File description:
** core fct of the vm
*/

#include "corewar.h"

void destroy_prog(env_t *env, program_t **list, program_t *p)
{
	program_t *prev = 0;

	if ((*list)->next == NULL) {
		env->last_id = (*list)->id;
		my_strcpy(env->last_name, (*list)->name);
	}
	env->nb_prog--;
	if (p == *list) {
		*list = p->next;
		free(p);
		return;
	}
	for (program_t *tmp = *list; tmp; tmp = tmp->next) {
		if (tmp == p) {
			prev->next = tmp->next;
			free(tmp);
			break;
		}
		prev = tmp;
	}
}
