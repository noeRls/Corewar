/*
** EPITECH PROJECT, 2018
** gnl
** File description:
** gnl
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char *add_char(char *str, int *size, char c)
{
	int s = 0;
	char *new = str;

	for (s; *size && str[s]; s++);
	if (s + 1 >= *size || *size == 0) {
		new = MALLOC(sizeof(char) * (*size + READ_SIZE + 1));
		for (int i = 0; new && *size && i < *size; i++)
			new[i] = str[i];
		*size += READ_SIZE + 1;
	}
	if (!new) {
		*size = 0;
		return (0);
	}
	if (new != str)
		FREE(str);
	new[s] = c;
	new[s + 1] = 0;
	return (new);
}

char *handle_read(int *index, char *buff, char **res, int *res_size)
{
	for (*index; buff[*index]; (*index)++) {
		if (buff[*index] == '\n') {
			(*index)++;
			return (*res);
		}
		*res = add_char(*res, res_size, buff[*index]);
		if (!(*res))
			return (NULL);
	}
	*index = 0;
	return (NULL);
}

char *clear_buff(char *buff, int *index)
{
	for (int i = 0; i < READ_SIZE + 1; i++)
		buff[i] = 0;
	*index = 0;
	return (buff);
}

char *get_next_line(int fd)
{
	static char buff[READ_SIZE + 1] = { 0 };
	static int index;
	char *res = 0;
	int res_size = 0;
	int size = 0;

	res = add_char(res, &res_size, 0);
	if (handle_read(&index, buff, &res, &res_size))
		return (res);
	while ((size = read(fd, clear_buff(buff, &index), READ_SIZE))
	&& size != -1 && fd != -1)
		if (handle_read(&index, buff, &res, &res_size))
			return (res);
	if (res && res[0])
		return (res);
	if (res)
		FREE(res);
	return (NULL);
}
