/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** main
*/

#include "corewar.h"

int get_unique_id(int const *diff_id, int size)
{
	int dflt = 1;

	for (int i = 0; i < size; i++) {
		if (dflt == diff_id[i]) {
			dflt++;
			i = -1;
		}
	}
	return (dflt);
}

int get_mem_start(int const *mem_start, int size)
{
	int mem[2 + size];
	int adress = 0;
	int last_size = 0;

	my_memset(mem, 0, sizeof(int) * (2 + size));
	for (int i = 0; i < size; i++)
		if (mem_start[i] == -1) {
			size--;
			i--;
		} else
			mem[i + 1] = mem_start[i];
	mem[size] = MEM_SIZE;
	size += 2;
	my_sort_int_array(mem, size);
	for (int i = 0; i < size - 1; i++)
		if (mem[i + 1] - mem[i] > last_size) {
			last_size = mem[i + 1] - mem[i];
			adress = mem[i] + (mem[i + 1] - mem[i] / 2);
		}
	return (adress);
}

int main(int ac, char **av)
{
	env_t env;
	args_t *args = 0;

	args = manage_args(ac, av);
	finally_setup_arg(args);
	env.dump_cycle = args->dump_cycle;
	init(args, &env);
	return (run(&env));
}
