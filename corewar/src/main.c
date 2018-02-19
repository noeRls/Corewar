/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** main
*/

#include "corewar.h"
#include "errors.h"

int get_unique_id(int const *diff_id, int size)
{
	int dflt = 0;

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

int print_usage(void)
{
	char *line = 0;
	int fd = open("./usage", O_RDONLY);

	if (fd == -1) {
		my_printf(USAGE_RM);
		return (84);
	}
	while ((line = get_next_line(fd))) {
		my_printf("%s\n", line);
		free(line);
	}
	return (0);
}

int main(int ac, char **av)
{
	env_t env;
	args_t args;

	if (ac == 1 || !my_strcmp(av[1], "-h"))
		return (print_usage());
	manage_args(ac, av, &args);
	finally_setup_arg(&args);
	env.dump_cycle = args.dump_cycle;
	init(&args, &env);
//	clean_args(&args);
	return (run(&env));
}
