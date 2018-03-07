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

void print_hexa_mem(cell_t const *memory)
{
	int x = 0;
	int line = 0;

	my_printf("0x%08X: ", line);
	line += 32;
	for (int i = 0; i < MEM_SIZE; i++) {
		my_printf("%02X ", (int) memory[i].value);
		x++;
		if (x % 8 == 0 && x != BYTES_PER_LINE) {
			my_printf(" ");
		} else if (x == BYTES_PER_LINE && i != MEM_SIZE - 1) {
			my_printf("\n0x%08X: ", line);
			line += 32;
			x = 0;
		}
	}
	my_putchar('\n');
}

void write_to_mem(cell_t *memory, void const *data, mem_info_t *infos)
{
	unsigned char *tmp = (unsigned char *) data;
	int index = 0;

	for (int i = 0; i < infos->size; i++) {
		index = (infos->start + i) % MEM_SIZE;
		if (index < 0) {
			index = MEM_SIZE + index;
		}
		memory[index].value = tmp[i];
		memory[index].last_id = infos->id;
	}
}

void read_from_mem(cell_t *memory, void *data, mem_info_t *infos)
{
	unsigned char *tmp = (unsigned char *) data;
	int index = 0;

	for (int i = 0; i < infos->size; i++) {
		index = (infos->start + i) % MEM_SIZE;
		if (index < 0) {
			index = MEM_SIZE + index;
		}
		tmp[i] = memory[index].value;
		memory[index].last_id = infos->id;
	}
}
