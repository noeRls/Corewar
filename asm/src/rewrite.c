/*
** EPITECH PROJECT, 2018
** rewrite
** File description:
** rewrite bytecode, but with the header at the begining
*/

#include "asm.h"

void magic_reverse(void *x)
{
	*((char *)x) ^= *(((char *)x) + 3);
	*(((char *)x) + 3) ^= *((char *)x);
	*((char *)x) ^= *(((char *)x) + 3);
	*(((char *)x) + 1) ^= *(((char *)x) + 2);
	*(((char *)x) + 2) ^= *(((char *)x) + 1);
	*(((char *)x) + 1) ^= *(((char *)x) + 2);
}

void rewrite(int bin, header_t *header)
{
	int c;
	char *buffer;

	lseek(bin, 0, SEEK_SET);
	for (header->prog_size = 0 ; read(bin, &c, 1) ; (header->prog_size)++);
	lseek(bin, 0, SEEK_SET);
	buffer = malloc(header->prog_size);
	if (read(bin, buffer, header->prog_size) == -1)
		exit(84);
	lseek(bin, 0, SEEK_SET);
	magic_reverse(&(header->magic));
	magic_reverse(&(header->prog_size));
	write(bin, header, sizeof(header_t));
	magic_reverse(&(header->prog_size));
	write(bin, buffer, header->prog_size);
}
