/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** core of verif header
*/

#include "asm.h"

void check_special_case(char *s)
{
	for (s = s ; *s == ' ' || *s == '\t' ; s++);
	if (!my_strncmp(s, ".name", 5)) {
		s += 5;
		for (s = s ; *s == ' ' || *s == '\t' ; s++);
		if (*s != '"')
			exit(my_puterror(ERROR"name syntax error\n"));
		s++;
		if (*s == '"')
			exit(my_puterror(ERROR"name syntax error\n"));
		for (s = s ; *s != '"' && *s != '\0' ; s++);
		if (*s == '\0')
			exit(my_puterror(ERROR"name syntax error\n"));
		if (*(s + 1) != '\0' && *(s + 1) != ' ' && *(s + 1) != '\t')
			exit(my_puterror(ERROR"name syntax error\n"));
	}
}

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
