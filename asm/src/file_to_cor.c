/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** file_to_core
*/

#include "asm.h"

char *file_to_cor(char *s)
{
	char *new = 0;
	int last = my_strlen(s);

	for (int i = 0; s[i]; i++)
		if (s[i] == '.')
			last = i;
	new = malloc(sizeof(char) * (last + 5));
	if (!new)
		exit(84);
	my_strncpy(new, s, last);
	my_strcat(new, ".cor");
	return (new);
}
