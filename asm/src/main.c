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
	int bin = open(file_to_core(av[1]), O_WRONLY | O_CREAT, 0666);
	char *s;
	char **tab;
	int mnemonique;

	(void)ac;
	if (src == -1 || bin == -1)
		return (84);
	while ((s = get_next_line(src))) {
		if (!(*s))
			continue;
		tab = str_to_av(s);
		if (tab[0][0] == COMMENT_CHAR)
			continue;
//		print_tabtab(tab);
		write_header(tab, bin);
		mnemonique = write_instruction(tab[0], bin);
		verif_syntax(mnemonique, tab);
		write_coding_byte(tab, bin);
		arg_encoder(tab, bin);
	}
	return (0);
}
