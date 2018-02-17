/*
** EPITECH PROJECT, 2018
** str_to_av
** File description:
** split a single string into a char **
*/

#include "asm.h"

int replace_space(char *str)
{
	int string_mode = 0;
	int i;

	for (i = 0 ; str[i] != '\0' ; i++) {
		if (string_mode == 0 && str[i] == '"') {
			str[i] = '\0';
			string_mode = 1;
		}
		if (string_mode == 1 && str[i] == '"') {
			str[i] = '\0';
			string_mode = 0;
		}
		if (string_mode == 0 && (str[i] == ' ' || str[i] == '\t'
					|| str[i] == SEPARATOR_CHAR))
			str[i] = '\0';
	}
	return (i);
}

int count_av(char *str, int size)
{
	int nb = 0;

	for (int i = 1 ; i <= size ; i++)
		if (str[i] == '\0' && str[i - 1] != '\0')
			nb++;
	return (nb);
}

void clear_comment(char *str)
{
	for (size_t i = 0; str[i]; i++) {
		if (str[i] == COMMENT_CHAR) {
			str[i] = '\0';
			return;
		}
	}
}

char **str_to_av(char *str)
{
	int size = replace_space(str);
	int nb_av = count_av(str, size);
	char **av = malloc(sizeof(char *) * (nb_av + 1));
	int j = 0;

	if (str[0] != '\0') {
		av[j] = str;
		j++;
	}
	for (int i = 1 ; i < size ; i++) {
		if (str[i] != '\0' && str[i - 1] == '\0') {
			av[j] = &str[i];
			j++;
		}
	}
	av[j] = NULL;
	return (av);
}

void print_tabtab(char **tab)
{
	for (int i = 0 ; tab[i] ; i++)
		my_printf("tab[%d]: '%s'\n", i, tab[i]);
}
