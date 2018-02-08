/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** arg_encoder
*/

#include "asm.h"

void write_register_arg(char *str, int fd)
{
	char c = getnbr(++str);

	write(fd, &c, sizeof(char));
}

int check_mnemonique_case(int mnemonique)
{
	mnemonique++;
	if (mnemonique == 9 || mnemonique == 10 || mnemonique == 11\
	|| mnemonique == 12 || mnemonique == 14 || mnemonique == 15)
		return (1);
	return (0);
}

void write_direct_arg(char *str, int fd, int mnemonique)
{
	char c = 0;
	size_t tmp = super_getnbr(++str);

	if (check_mnemonique_case(mnemonique)) {
		write_indirect_arg(str, fd);
		return;
	}
	c ^= tmp & 4278190080;
	write(fd, &c, sizeof(c));
	c = 0;
	c ^= tmp & 16711680;
	write(fd, &c, sizeof(c));
	c = 0;
	c ^= tmp & 65280;
	write(fd, &c, sizeof(c));
	c = 0;
	c ^= tmp & 255;
	write(fd, &c, sizeof(c));
}

void write_indirect_arg(char *str, int fd)
{
	char c = 0;
	int tmp = getnbr(str);

	c ^= tmp & 65280;
	write(fd, &c, sizeof(c));
	c = 0;
	c ^= tmp & 255;
	write(fd, &c, sizeof(c));
}

void arg_encoder(char **tab, int fd, int mnemonique, label_t *label)
{
	for (int i = 1 ; tab[i] ; i++) {
		switch (get_arg_type(tab[i])) {
		case REGISTER:
			write_register_arg(tab[i], fd);
			break;
		case DIRECT:
			write_direct_arg(tab[i], fd, mnemonique);
			break;
		case INDIRECT:
			write_indirect_arg(tab[i], fd);
			break;
		case LABEL_CALL:
			fill_label_call(tab[i], fd, mnemonique, label->call);
			break;
		case LABEL_DECLARATION:
			fill_label_decla(tab[i], fd, mnemonique, label->decla);
			break;
		}
	}
}
