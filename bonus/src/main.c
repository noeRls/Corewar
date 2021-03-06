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
	int tmp_size = size;
	int tmp_var = 0;

	my_memset(mem, 0, sizeof(int) * (size + 2));
	for (int i = 0; i < tmp_size; i++)
		if (mem_start[i] == -1)
			size--;
		else
			mem[++tmp_var] = mem_start[i];
	mem[size + 1] = MEM_SIZE;
	size += 2;
	my_sort_int_array(mem, size);
	for (int i = 0; i < size - 1; i++)
		if ((!i && (tmp_var = 0)) && mem[i + 1] - mem[i] > tmp_var) {
			tmp_var = mem[i + 1] - mem[i];
			adress = mem[i] + ((mem[i + 1] - mem[i]) / 2);
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

int env_okay(char **env)
{
	for (int i = 0; env[i]; i++)
		if (my_strncmp(env[i], "DISPLAY", 6) == 0)
			return (1);
	return (0);
}

int main(int ac, char **av, char **envp)
{
	env_t env;
	args_t args;

	my_memset(&env, 0, sizeof(env_t));
	if (ac == 1 || !my_strcmp(av[1], "-h") || !env_okay(envp))
		return (print_usage());
	manage_args(ac, av, &args);
	finally_setup_arg(&args);
	env.dump_cycle = args.dump_cycle;
	init(&args, &env);
	env.player_id = args.prog_ids;
	clean_args(&args);
	init_window(&env);
	return (run(&env));
}
