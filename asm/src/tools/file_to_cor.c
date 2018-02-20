/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** file_to_core
*/

#include "asm.h"

char *set_string(char *s)
{
	size_t slash = 0;

	for (size_t i = 0; s[i]; i++) {
		if (s[i] == '/')
			slash++;
	}
	for (; slash && *s; s++) {
		if (*s == '/')
			--slash;
	}
	return (s);
}

char *file_to_cor(char *s)
{
	char *new = 0;
	int last = my_strlen(s);

	s = set_string(s);
	for (int i = 0; s[i]; i++)
		if (s[i] == '.')
			last = i;
	new = MALLOC(sizeof(char) * (last + 5));
	if (!new)
		exit(84);
	my_strncpy(new, s, last);
	my_strcat(new, ".cor");
	return (new);
}
