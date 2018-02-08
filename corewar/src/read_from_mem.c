/*
** EPITECH PROJECT, 2018
** read prog from mem
** File description:
** mem
*/

#include "corewar.h"

void swap(void *data, int size)
{
	char *tmp = (char *) data;
	char t = 0;

	for (int i = 0; i < size / 2; i++) {
		t = tmp[i];
		tmp[i] = tmp[size - 1 - i];
		tmp[size - 1 - i] = t;
	}
}

void print_hexa_mem(unsigned char *memory)
{
	unsigned char *tmp = 0;
	int x = 0;

	for (int i = 0; i < MEM_SIZE; i++) {
		printf("%02x ", memory[i]);
		x++;
		if (x == 8) {
			printf(" ");
		} else if (x == 16) {
			printf("\n");
			x = 0;
		}
		free(tmp);
	}
}

void write_to_mem(unsigned char *memory, void *data, int size, int start)
{
	char *tmp = (char *) data;

	for (int i = 0; i < size; i++) {
		memory[(start + i) % MEM_SIZE] = tmp[i];
	}
}

void read_from_mem(unsigned char *memory, void *data, int size, int start)
{
	unsigned char *tmp = (unsigned char *) data;

	for (int i = 0; i < size; i++) {
		tmp[i] = memory[(start + i) % MEM_SIZE];
	}
}

int get_reg_value(char *memory, program_t *p, int index)
{
	int res = 0;

	res = p->reg[index];
	swap(&res, sizeof(int));
	return (res);
}
