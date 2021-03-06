/*
** EPITECH PROJECT, 2018
** run
** File description:
** core fct of the vm
*/

#include "corewar.h"

int end(env_t *env, program_t *list)
{
	int last = 0;

	if (list == NULL)
		return (1);
	else
		last = list->id;
	for (program_t *prgm = list; prgm; prgm = prgm->next) {
		if (last != prgm->id)
			return (0);
	}
	env->end = 1;
	env->last_id = last;
	my_strcpy(env->last_name, list->name);
	return (1);
}

void manage_cycle(env_t *env)
{
	program_t *next = 0;

	for (program_t *prgm = env->prgm; prgm; prgm = next) {
		next = prgm->next;
		if (prgm->live_signal > env->cycle_to_die) {
			destroy_prog(env, &(env->prgm), prgm);
		} else {
			prgm->cycle -= 1;
			prgm->live_signal += 1;
		}
	}
	if (env->live_counter >= NBR_LIVE) {
		env->cycle_to_die -= CYCLE_DELTA;
		env->live_counter = 0;
	}
	if (env->cycle % env->dump_cycle == 0 &&	\
	env->dump_cycle != -1 && env->cycle) {
		print_hexa_mem(env->memory);
		exit(0);
	}
}

void execute_prog(env_t *env, program_t *p)
{
	static void (*fctns[])(env_t *, program_t *, instr_t) = {live, ld, \
	st, add, sub, and, or, xor, zjmp, ldi, sti, fork_op, lld, \
	lldi, lfork, aff};

	if (p->info.code > 16 || p->info.code < 1)
		p->cycle = 1;
	else
		fctns[p->info.code - 1](env, p, p->info);
	read_from_mem(env->memory, &(p->info), \
	&((mem_info_t) {sizeof(instr_t), p->PC, p->id}));
	p->pc_backup = p->PC;
	if (p->info.code == 1 || p->info.code == 9 || \
	p->info.code == 12 || p->info.code == 15)
		up_pc(p, 1);
	else
		up_pc(p, sizeof(instr_t));
	if (p->info.code > 16 || p->info.code < 1)
		p->cycle = 1;
	else
		set_cycle(p, p->info.code);
}

void update(env_t *env)
{
	int i = 0;

	i = env->nb_prog;
	for (int i = 0; i < MEM_SIZE; i++)
		if (env->memory[i].lived && \
		CLOCK_TIME(env->memory[i].cl) > TIME_LIVE_COLOR)
			env->memory[i].lived = 0;
	for (program_t *p = env->prgm; p && i >= 0 ; p = p->next) {
		p->cycle ? 0 : execute_prog(env, p);
		i--;
	}
	manage_cycle(env);
	env->cycle += 1;
}

int run(env_t *env)
{
	while (!(env->end) && !end(env, env->prgm) \
	&& sfRenderWindow_isOpen(env->win)) {
		update(env);
		render(env);
	}
	my_printf("The player %d(%s) has won\n",	\
		env->last_id, env->last_name);
	clean_progs(env->prgm);
	return (0);
}
