/*
** EPITECH PROJECT, 2018
** label
** File description:
** handling of labels
*/

#include "asm.h"

void reinit_pos(label_t *label)
{
	label->current_pos += label->tmp_pos;
	label->tmp_pos = 0;
}

label_t *init_label(void)
{
	label_t *label = MALLOC(sizeof(label_t));

	label->decla = NULL;
	label->call = NULL;
	label->tmp_pos = 0;
	label->current_pos = 0;
	return (label);
}

void goto_last_label_call(call_t **call, label_t *label)
{
	if (*call == NULL) {
		label->call = MALLOC(sizeof(call_t));
		*call = label->call;
	} else {
		while ((*call)->next)
			*call = (*call)->next;
		(*call)->next = MALLOC(sizeof(call_t));
		(*call) = (*call)->next;
	}
}

void fill_label_call(char *str, int fd, int mnemonique, label_t *label)
{
	call_t *call = label->call;

	goto_last_label_call(&call, label);
	if (str[0] == LABEL_CHAR)
		call->name = my_strdup(str + 1);
	else
		call->name = my_strdup(str + 2);
	call->abs_pos = label->current_pos;
	call->rel_pos = label->current_pos + label->tmp_pos;
	call->next = NULL;
	if (str[0] == DIRECT_CHAR && !check_mnemonique_case(mnemonique)) {
		call->type = DIRECT;
		write_direct_arg(str, fd, mnemonique, label);
	} else {
		call->type = INDIRECT;
		write_indirect_arg(str, fd, label);
	}
}

char **fill_label_decla(char **tab, label_t *label)
{
	decla_t *decla = label->decla;
	char *str = tab[0];

	if (decla == NULL) {
		label->decla = MALLOC(sizeof(decla_t));
		decla = label->decla;
	} else {
		while (decla->next)
			decla = decla->next;
		decla->next = MALLOC(sizeof(decla_t));
		decla = decla->next;
	}
	str[my_strlen(str) - 1] = '\0';
	decla->name = my_strdup(str);
	decla->pos = label->current_pos;
	decla->next = NULL;
	return (shift_tab(tab));
}
