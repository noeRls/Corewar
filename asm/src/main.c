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

label_t *init_label(void)
{
	label_t *label = malloc(sizeof(label_t));

	label->decla = NULL;
	label->call = NULL;
	label->tmp = 0;
	label->current_pos = 0;
	return (label);
}

char **shift_tab(char **tab)
{
	int i;

	for (i = 1 ; tab[i] ; i++)
		tab[i - 1] = tab[i];
	tab[i - 1] = tab[i];
	return (tab);
}

int main(int ac, char **av)
{
	int src = open(av[1], O_RDONLY);
	int bin = open(file_to_cor(av[1]), O_RDWR | O_CREAT, 0666);
	char *s;
	char **tab;
	int mnemonique;
	header_t header;
	label_t *label = init_label();

	(void)ac;
	if (src == -1 || bin == -1)
		return (84);
	init_header(&header);
	while ((s = get_next_line(src))) {
		if (!(*s))
			continue;
		tab = str_to_av(s);
		//print_tabtab(tab);
		if (tab[0][0] == COMMENT_CHAR)
			continue;
		if (fill_header(tab, &header))
			continue;
//		printf("tab 0 = %s\n", tab[0]);
		if (get_arg_type(tab[0]) == LABEL_DECLARATION) {
			fill_label_decla(tab[0], bin, label);
			tab = shift_tab(tab);
		}
		mnemonique = write_instruction(tab[0], bin, label);
//		verif_syntax(mnemonique, tab);
		write_coding_byte(tab, bin, label);
		arg_encoder(tab, bin, mnemonique, label);
	}
	printf_linked_list(label->call, label->decla);
	rewrite(bin, &header);
	return (0);
}
