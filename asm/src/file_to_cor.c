/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** file_to_core
*/

#include "asm.h"

char *file_to_cor(char *s)
{
	char *new = malloc(my_strlen(s) + 3);

	(!new) ? exit(84) : new;
	new = my_strcpy(new, s);
	new[my_strlen(s) - 1] = '\0';
	new = my_strcat(new, "cor");
	return (new);
}
