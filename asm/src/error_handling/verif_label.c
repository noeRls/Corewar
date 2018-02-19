/*
** EPITECH PROJECT, 2018
** verif_label
** File description:
** verifying existence of each labels
*/

#include "asm.h"

void verif_label(label_t *label)
{
	decla_t *decla;

	for (call_t *call = label->call ; call ; call = call->next) {
		for (decla = label->decla; decla; decla = decla->next)
			if (!my_strcmp(call->name, decla->name))
				break;
		if (!decla) {
			my_puterror(ERROR"Label undeclared\n");
			exit(84);
		}
	}
}
