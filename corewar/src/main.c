/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** main
*/

#include "corewar.h"

void add_prog(program_t **start, program_t *to_add)
{
	program_t *last = 0;

	if (!(*start))
		*start = to_add;
	for (last = (*start); last->next; last = last->next);
	last->next = to_add;
	to_add->next = 0;
}

program_t *prog_dup(program_t *prog)
{
	program_t *prgm = malloc(sizeof(program_t));

	prgm->pc_curr = prog->pc_curr;
	prgm->pc_backup = prog->pc_backup;
	prgm->info = prog->info;
	prgm->id = prog->id;
	prgm->fd = prog->fd;
	prgm->live_signal = prog->live_signal;
	prgm->cycle = prog->cycle;
	prgm->carry = 0;
	prgm->mem_start = prog->mem_start;
	prgm->next = 0;
	return (prgm);
}

program_t *start_prog(char *path)
{
	int fd = open(path, O_RDONLY);
	program_t *prgm = malloc(sizeof(program_t));

	if (!fd)
		exit(84);
	prgm->cycle = 0;
	prgm->fd = fd;
	prgm->carry = 0;
	prgm->live_signal = 0;
	prgm->cycle = 0;
	prgm->pc_curr = 0;
	prgm->pc_backup = 0;
	return (prgm);
}

static void magic_reverse(void *x)
{
	*((char *)x) ^= *(((char *)x) + 3);
	*(((char *)x) + 3) ^= *((char *)x);
	*((char *)x) ^= *(((char *)x) + 3);
	*(((char *)x) + 1) ^= *(((char *)x) + 2);
	*(((char *)x) + 2) ^= *(((char *)x) + 1);
	*(((char *)x) + 1) ^= *(((char *)x) + 2);
}

void ini_prog_memory(env_t *env)
{
	header_t hd;
	int x = 10;
	int pc_value = 0;

	for (program_t *tmp = env->prgm; tmp; tmp = tmp->next, ++x) {
		tmp->id = x;
		set_reg_value(env->memory, tmp, 1, x);
		tmp->pc_curr = tmp->mem_start + REG_NUMBER * REG_SIZE;
		read(tmp->fd, &hd, sizeof(header_t));
		magic_reverse(&(hd.prog_size));
		read(tmp->fd, &(env->memory[get_pc(env->memory, tmp)]), \
		hd.prog_size);
	}
}

void init(int ac, char **av, env_t *env)
{
	program_t *st = 0;
	program_t *start = 0;

	env->nbr_player = ac - 1;
	env->cycle_to_die = CYCLE_TO_DIE;
	env->cycle = 0;
	env->prgm = malloc(sizeof(program_t));
	st = start_prog(av[1]);
	st->mem_start = 0;
	st->next = 0;
	start = st;
	for (int i = 2; i < ac; i++) {
		st->next = start_prog(av[i]);
		st->next->mem_start = (i - 1) * (MEM_SIZE / env->nbr_player);
		st = st->next;
	}
	st->next = 0;
	env->prgm = start;
	my_memset(env->memory, 0, MEM_SIZE);
	ini_prog_memory(env);
	env->live_counter = 0;
}

int manage_args(int ac, char **av)
{
	int i = 0;

	if (ac <= 3)
		return (83);
	for (i = 0; i <
}

int main(int ac, char **av)
{
	env_t env;

	init(ac, av, &env);
	run(&env);
	return (0);
}
