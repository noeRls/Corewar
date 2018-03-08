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
	char **tab;
	char *s = NULL;

	while ((s = get_next_line(fd)))
		verif_header_loop();

	if (!s)
		len = 0;
	verif_comment_name(len, comment, name, fd);
}
