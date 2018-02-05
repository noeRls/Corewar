/*
** EPITECH PROJECT, 2018
** gnl
** File description:
** core of get next line
*/

#include "my.h"
#include "get_next_line.h"
#include <unistd.h>

static char *cl_buff(char *buff)
{
	for (int i = 0; i < READ_SIZE + 1; i++)
		buff[i] = 0;
	return (buff);
}

static int cpy_past_ret(char *past_returned, char *returned)
{
	int i = 0;

	if (past_returned) {
		for (i = 0; past_returned[i]; i++) {
			returned[i] = past_returned[i];
		}
		free(past_returned);
	}
	return (i);
}

static char *fill_realloc(char *past_returned, \
	char *read_buff, int size, int *index)
{
	char *returned = my_malloc(sizeof(char) * (size + 1));
	int i = cpy_past_ret(past_returned, returned);
	int b = 0;

	for (b = *index; read_buff[b]; i++) {
		if (read_buff[b] != '\n') {
			returned[i] = read_buff[b];
		} else {
			*index = b + 1;
			b = -1;
			break;
		}
		b++;
	}
	if (b != -1) {
		*index = 0;
		cl_buff(read_buff);
	}
	returned[i] = 0;
	return (returned);
}

char *get_next_line(int fd)
{
	static char read_buff[READ_SIZE + 1] = {0};
	static int index = 0;
	char *returned = 0;
	int size = 0;
	int stop = 0;
	static int tmp = READ_SIZE;

	if (index >= tmp) {
		index = 0;
		cl_buff(read_buff);
	}
	while ((!size && read_buff[index]) || (!index \
	&& !stop && (tmp = read(fd, cl_buff(read_buff), READ_SIZE)))) {
		if (tmp < READ_SIZE)
			stop = 1;
		size += READ_SIZE;
		returned = fill_realloc(returned, read_buff, \
			size, &index);
	}
	return (returned);
}
