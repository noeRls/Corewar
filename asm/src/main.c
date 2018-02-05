/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** main
*/

#include "asm.h"

int main(int ac, char **av)
{
	int src = open(av[1], O_RDONLY);
	int bin = open(av[2], O_WRONLY | O_CREAT, 0444);
	char *s;
	char **tab;

	(void)ac;
	if (src == -1 || bin == -1)
		return (84);
	while ((s = get_next_line(src))) {
		tab = str_to_av(s);
		print_tabtab(tab);
		write_instruction(tab[0], bin);
	}
	return (0);
}
