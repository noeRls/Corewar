/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** main
*/

#include "asm.h"

int main(int ac, char **av)
{
	int src = check_main(ac, av);
	int bin = verif(av[1]);
	header_t header;
	label_t *label = init_label();

	init_header(&header);
	loop(label, &header, src, bin);
	rewrite_label(bin, label);
	rewrite_header(bin, &header);
	close(src);
	close(bin);
	FREEZER;
	return (0);
}

int check_main(int ac, char **av)
{
	int fd;

	if (ac < 2 || !my_strcmp(av[1], "-h")) {
		my_putstr("USAGE:\n\t./asm file_name[.s] ....\n");
		my_putstr("\nDESCRIPTION\n\tfile_name\tfile in assembly"
			" language to be converted into file_name.cor,\n\t\t\t"
			"an executable in the Virtual Machine.\n");
		exit(0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1) {
		my_puterror("Please, sir, enter a valid file!\n"
			"Or maybe are you an asteck?\n");
		exit(84);
	}
	return (fd);
}

void write_file(char **tab, int bin, label_t *label)
{
	int mnemonique;

	mnemonique = write_instruction(tab[0], bin, label);
	write_coding_byte(tab, bin, label);
	arg_encoder(tab, bin, mnemonique, label);
	reinit_pos(label);
}

void loop(label_t *label, header_t *header, int src, int bin)
{
	char *s;
	char **tab;

	while ((s = get_next_line(src))) {
		reinit_pos(label);
		if (!(*s))
			continue;
		clear_comment(s);
		tab = str_to_av(s);
		if (tab[0] == NULL)
			continue;
		if (fill_header(tab, header))
			continue;
		if (get_arg_type(tab[0]) == LABEL_DECLARATION)
			tab = fill_label_decla(tab, label);
		if (tab[0] == NULL)
			continue;
		write_file(tab, bin, label);
	}
}
