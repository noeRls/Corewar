/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** main
*/

#include "asm.h"

void init_header(header_t *header)
{
	my_super_memset(header, 0, sizeof(*header));
}

int main(int ac, char **av)
{
	int src = open(av[1], O_RDONLY);
	int bin = open(file_to_cor(av[1]), O_RDWR | O_CREAT, 0666);
	char *s;
	char **tab;
	int mnemonique;
	header_t header;

	(void)ac;
	if (src == -1 || bin == -1)
		return (84);
	init_header(&header);
	while ((s = get_next_line(src))) {
		if (!(*s))
			continue;
		tab = str_to_av(s);
		if (tab[0][0] == COMMENT_CHAR)
			continue;
		if (fill_header(tab, &header))
			continue;
		mnemonique = write_instruction(tab[0], bin);
		verif_syntax(mnemonique, tab);
		write_coding_byte(tab, bin);
		arg_encoder(tab, bin, mnemonique);
	}
	rewrite(bin, &header);
	return (0);
}
