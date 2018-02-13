/*
** EPITECH PROJECT, 2018
** rewrite_label
** File description:
** rewrite file to replace labels by the good value
*/

#include "asm.h"

void write_direct_label(int x, int fd)
{
	char c = 0;
	unsigned int tmp = (unsigned int) x;

//	printf("direct: tmp = %d, soit en hexa: %x\n", x, x);
//	printf("direct: tmp = %u, soit en hexa: %x\n\n", tmp, tmp);

        c ^= tmp & 4278190080;
//	printf("direct char = %d\n", c);
	write(fd, &c, sizeof(c));
        c = 0;
        c ^= tmp & 16711680;
//	printf("direct char = %d\n", c);
        write(fd, &c, sizeof(c));
        c = 0;
        c ^= tmp & 65280;
//	printf("direct char = %d\n", c);
        write(fd, &c, sizeof(c));
        c = 0;
        c ^= tmp & 255;
//	printf("direct char = %d\n\n", c);
	write(fd, &c, sizeof(c));
}

void write_indirect_label(int x, int fd)
{
	char c = 0;
	unsigned short int tmp = (unsigned short int) x;

//	printf("direct: tmp = %d, soit en hexa: %x\n", x, x);
//	printf("direct: tmp = %u, soit en hexa: %x\n\n", tmp, tmp);

        c ^= tmp & 65280;
//	printf("indirect char = %d\n", c);
        write(fd, &c, sizeof(c));
        c = 0;
        c ^= tmp & 255;
//	printf("indirect char = %d\n\n", c);
        write(fd, &c, sizeof(c));
}

void change_label(int fd, call_t *call, decla_t *decla, label_t *label)
{
	int final_pos;
	char *tmp = malloc(sizeof(char) * 10);

	if (!my_strcmp(call->name, decla->name)) {
		final_pos = decla->pos - call->abs_pos;
		lseek(fd, call->rel_pos, SEEK_SET);
		if (call->type == DIRECT)
			write_direct_label(final_pos, fd);
		else
			write_indirect_label(final_pos, fd);
	}
	(void)label;
	free(tmp);
}

void rewrite_label(int fd, label_t *label)
{
	for (call_t *call = label->call ; call ; call = call->next) {
		for (decla_t *decla = label->decla; decla; decla = decla->next)
			change_label(fd, call, decla, label);
	}
}
