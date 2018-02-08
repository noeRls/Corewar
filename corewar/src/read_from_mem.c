/*
** EPITECH PROJECT, 2018
** read prog from mem
** File description:
** mem
*/

#include "corewar.h"

void read_from_mem(char *memory, void *data, int size, int start)
{
	char *tmp = (char *) data;

	for (int i = 0; i < size; i++) {
		tmp[i] = memory[(start + i) % MEM_SIZE];
	}
}
