/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** arg_encoder
*/

#include "asm.h"

void write_register_arg(char *str, int fd, label_t *label)
{
	char c = getnbr(++str);

	write(fd, &c, sizeof(char));
	label->tmp_pos += 1;
}

int check_mnemonique_case(int mnemonique)
{
	mnemonique++;
	if (mnemonique == 9 || mnemonique == 10 || mnemonique == 11
	|| mnemonique == 12 || mnemonique == 14 || mnemonique == 15)
		return (1);
	return (0);
}

void write_direct_arg(char *str, int fd, int mnemonique, label_t *label)
{
	size_t tmp;

	if (str[0] == DIRECT_CHAR)
		++str;
	tmp = super_getnbr(str);
	if (check_mnemonique_case(mnemonique)) {
		write_indirect_arg(str, fd, label);
		return;
	}
	magic_reverse(&tmp);
	write(fd, &tmp, sizeof(int));
	label->tmp_pos += 4;
}

void write_indirect_arg(char *str, int fd, label_t *label)
{
	unsigned short int tmp = (unsigned short int) super_getnbr(str);

	short_magic_reverse(&tmp);
	write(fd, &tmp, sizeof(unsigned short int));
	label->tmp_pos += 2;
}

void arg_encoder(char **tab, int fd, int mnemonique, label_t *label)
{
	for (int i = 1 ; tab[i] ; i++) {
		switch (get_arg_type(tab[i])) {
		case REGISTER:
			write_register_arg(tab[i], fd, label);
			break;
		case DIRECT:
			write_direct_arg(tab[i], fd, mnemonique, label);
			break;
		case INDIRECT:
			write_indirect_arg(tab[i], fd, label);
			break;
		case LABEL_CALL:
			fill_label_call(tab[i], fd, mnemonique, label);
			break;
		case LABEL_DECLARATION:
			my_puterror(ERROR"Unknow error occured\n");
			my_puterror("Please contact TheWanderingCat\n");
			break;
		}
	}
}
