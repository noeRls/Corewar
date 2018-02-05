/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** main
*/

#include "asm.h"

void print_help()
{
}

int replace_space(char *str)
{
	int string_mode = 0;
	int i;

	for (i = 0 ; str[i] != '\0' ; i++) {
		if (string_mode == 0 && str[i] == '"') {
			str[i] = '\0';
			string_mode = 1;
			i++;
		}
		if (string_mode == 1 && str[i] == '"') {
			str[i] = '\0';
			string_mode = 0;
			i++;
		}
		if (string_mode == 0 && (str[i] == ' ' || str[i] == '\t' || str[i] == ','))
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

int main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	char *s;
	char **tab;

	if (fd == -1)
		return (84);
	while ((s = get_next_line(fd))) {
		my_printf("on a choppé ligne 1: %s\n", s);
		tab = str_to_av(s);
		print_tabtab(tab);
	}
	return (0);
}
