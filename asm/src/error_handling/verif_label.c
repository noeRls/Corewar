/*
** EPITECH PROJECT, 2018
** verif_label
** File description:
** verifying existence of each labels
*/

#include "asm.h"

void does_the_label_exist(call_t *call, decla_t *decla, label_t *label)
{
	for (decla = label->decla; decla; decla = decla->next)
		if (!my_strcmp(call->name, decla->name))
			break;
	if (!decla) {
		my_puterror(ERROR"Label undeclared\n");
		exit(84);
	}
}

void verif_label(label_t *label)
{
	decla_t *decla = NULL;

	for (call_t *call = label->call ; call ; call = call->next)
		does_the_label_exist(call, decla, label);

}
