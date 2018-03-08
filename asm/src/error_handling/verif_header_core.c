/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** core of verif header
*/

#include "asm.h"

void verif_header(int fd)
{
	int name = 0;
	int comment = 0;
	char *s = NULL;
	size_t len = 0;

	while ((s = get_next_line(fd)))
		if (verif_header_loop(s, &name, &comment, &len))
			break;
	if (!s)
		len = 0;
	verif_comment_name(len, comment, name, fd);
}
