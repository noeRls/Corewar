/*
** EPITECH PROJECT, 2018
** manage input args
** File description:
** input args management
*/

#include "corewar.h"

const char * const params[] = {"-dump", "-n", "-a"};

void finally_setup_arg(args_t *arg)
{
	arg->not_mem_default = 0;
	for (int i = 0; i < arg->nb_prog; i++)
		if (arg->prog_ids[i] < 0)
			arg->prog_ids[i] = get_unique_id( \
			arg->prog_ids, arg->nb_prog);
	for (int i = 0; i < arg->nb_prog; i++)
		if (arg->mem_start[i] > 0) {
			arg->mem_start[i] = arg->mem_start[i] % MEM_SIZE;
			arg->not_mem_default = 1;
		}
	for (int i = 0; i < arg->nb_prog; i++)
		if (arg->mem_start[i] < 0)
			arg->mem_start[i] = get_mem_start(	\
			arg->mem_start, arg->nb_prog);
}

int handle_for(int *i, int j, args_t *args, char **av)
{
	int error = 1;
	int tmp = *i;

	if (!my_strcmp(params[j], av[*i])) {
		error = my_str_isnum(av[*i + 1]);
		if (!j) {
			args->dump_cycle = getnbr(av[*i + 1]);
		} else if (j == 1) {
			args->prog_ids[args->curr] = getnbr(av[*i + 1]);
		} else {
			args->mem_start[args->curr] = getnbr(av[*i + 1]);
		}
		(*i)++;
	}
	if (!error)
		exit(84);
	if (tmp != *i)
		return (1);
	else
		return (0);
}

void second_part(args_t *args, int ac, char **av)
{
	int exists = 0;

	for (int i = 0; i < args->nb_prog; i++) {
		args->prog_ids[i] = -1;
		args->mem_start[i] = -1;
	}
	for (int i = 1; i < ac; i++) {
		exists = 0;
		if (av[i][0] != '-') {
			args->prog_paths[args->curr] = av[i];
			args->curr++;
		}
		for (int j = 0; j < 3 && av[i][0] == '-'; j++)
			exists = max(exists, handle_for(&i, j, args, av));
		if (!exists && av[i - 1][0] == '-')
			exit(84);
	}
}

void manage_args(int ac, char **av, args_t *args)
{
	int count = 0;

	for (int i = 1; i < ac; i++)
		if (av[i][0] != '-' && i && av[i - 1][0] != '-')
			count++;
	args->curr = 0;
	args->nb_prog = count;
	args->prog_paths = malloc(sizeof(char *) * count);
	args->prog_ids = malloc(sizeof(int) * count);
	args->mem_start = malloc(sizeof(int) * count);
	args->dump_cycle = -1;
	second_part(args, ac, av);
}
