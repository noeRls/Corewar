/*
** EPITECH PROJECT, 2018
** inits
** File description:
** inits
*/

#include "corewar.h"

void init_progs(args_t const *arg, env_t *env)
{
	program_t *st = 0;
	program_t *start = 0;

	st = start_prog(arg->prog_paths[0]);
	st->mem_start = 0;
	st->next = NULL;
	start = st;
	for (int i = 1; i < arg->nb_prog; i++) {
		st->next = start_prog(arg->prog_paths[i]);
		if (!arg->not_mem_default) {
			st->next->mem_start =				\
			(i * (MEM_SIZE / env->nbr_player));
		} else {
			st->next->mem_start = arg->mem_start[i];
		}
		st = st->next;
	}
	st->next = NULL;
	env->prgm = start;
}

void ini_prog_memory(env_t *env)
{
	header_t hd;
	int x = 0;

	for (program_t *tmp = env->prgm; tmp; tmp = tmp->next, ++x) {
		tmp->id = x;
		tmp->reg[1] = x;
		tmp->PC = tmp->mem_start;
		if (read(tmp->fd, &hd, sizeof(header_t)) != sizeof(header_t))
			exit(84);
		swap(&(hd.prog_size), sizeof(hd.prog_size));
		if (read(tmp->fd, &(env->memory[tmp->PC]),	\
		hd.prog_size) != hd.prog_size)
			exit(84);
		my_memset(tmp->name, 0, PROG_NAME_LENGTH + 1);
		my_strcpy(tmp->name, hd.prog_name);
	}
}

void init(args_t const *arg, env_t *env)
{
	env->nbr_player = arg->nb_prog;
	env->cycle_to_die = CYCLE_TO_DIE;
	env->cycle = 0;
	env->end = 0;
	env->last_id = 0;
	my_memset(env->last_name, 0, PROG_NAME_LENGTH + 1);
	my_memset(env->memory, 0, MEM_SIZE);
	init_progs(arg, env);
	ini_prog_memory(env);
	env->live_counter = 0;
}
