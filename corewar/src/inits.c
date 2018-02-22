/*
** EPITECH PROJECT, 2018
** inits
** File description:
** inits
*/

#include "corewar.h"

void init_progs(args_t *arg, env_t *env)
{
	program_t *st = 0;
	program_t *start = 0;

	st = start_prog(arg->prog_paths[0]);
	st->id = arg->prog_ids[0];
	st->mem_start = !arg->not_mem_default ? 0 : arg->mem_start[0];
	start = st;
	for (int i = 1; i < arg->nb_prog; i++) {
		st->next = start_prog(arg->prog_paths[i]);
		if (!arg->not_mem_default) {
			st->next->mem_start =				\
			(i * (MEM_SIZE / env->nbr_player));
		} else {
			st->next->mem_start = arg->mem_start[i];
		}
		st->next->id = arg->prog_ids[i];
		st = st->next;
	}
	st->next = NULL;
	env->prgm = start;
}

int get_default_id(env_t *env)
{
	int x = 0;
	program_t *p = env->prgm;
	
	while (p) {
		if (p->id == x) {
			p = env->prgm;
			x++;
		} else {
			p = p->next;
		}
	}
	return (x);
}

void ini_prog_memory(env_t *env)
{
	header_t hd;
	unsigned char *stock = 0;
	
	for (program_t *tmp = env->prgm; tmp; tmp = tmp->next) {
		if (tmp->id == -1)
			tmp->id = get_default_id(env);
		tmp->reg[1] = tmp->id;
		tmp->PC = tmp->mem_start;
		if (read(tmp->fd, &hd, sizeof(header_t)) != sizeof(header_t))
			exit(84);
		swap(&(hd.prog_size), sizeof(hd.prog_size));
		stock = malloc(sizeof(unsigned char) * hd.prog_size);
		if (read(tmp->fd, stock, hd.prog_size) != hd.prog_size)
			exit(84);
		write_to_mem(env->memory, stock, hd.prog_size, tmp->PC);
		free(stock);
		my_memset(tmp->name, 0, PROG_NAME_LENGTH + 1);
		my_strcpy(tmp->name, hd.prog_name);
	}
}

void init(args_t *arg, env_t *env)
{
	env->nbr_player = arg->nb_prog;
	env->cycle_to_die = CYCLE_TO_DIE;
	env->cycle = 0;
	env->end = 0;
	env->last_id = 0;
	env->nb_prog = 0;
	my_memset(env->last_name, 0, PROG_NAME_LENGTH + 1);
	my_memset(env->memory, 0, MEM_SIZE);
	init_progs(arg, env);
	ini_prog_memory(env);
	env->live_counter = 0;	
	check_init(env);
	for (program_t *p = env->prgm; p; p = p->next)
		env->nb_prog++;
}
