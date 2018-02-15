/*
** EPITECH PROJECT, 2018
** run
** File description:
** core fct of the vm
*/

#include "corewar.h"

int end(program_t *list)
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
	return (1);
}

void destroy_prog(env_t *env, program_t **list, program_t *p)
{
	program_t *prev = 0;

	if ((*list)->next == NULL) {
		env->end = 1;
		env->last_id = (*list)->id;
		my_strcpy(env->last_name, (*list)->name);
	}
	if (p == *list) {
		*list = p->next;
		free(p);
		return;
	}
	for (program_t *tmp = *list; tmp; tmp = tmp->next) {
		if (tmp == p) {
			prev->next = tmp->next;
			free(tmp);
			break;
		}
		prev = tmp;
	}
}

void manage_cycle(env_t *env)
{
	program_t *next = 0;

	for (program_t *prgm = env->prgm; prgm; prgm = next) {
		next = prgm->next;
		if (prgm->live_signal > env->cycle_to_die) {
			destroy_prog(env, &(env->prgm), prgm);
		}
		else {
			prgm->cycle -= 1;
			prgm->live_signal += 1;
		}
	}
	if (env->live_counter >= NBR_LIVE) {
		env->cycle_to_die -= CYCLE_DELTA;
		env->live_counter = 0;
	}
	if (env->cycle % env->dump_cycle == 0 && env->dump_cycle != -1)
		print_hexa_mem(env->memory);
	env->cycle += 1;
}

void execute_prog(env_t *env, program_t *p)
{
	static void (*fctns[])(env_t *, program_t *, instr_t) = {live, ld, \
	st, add, sub, and, or, xor, zjmp, ldi, sti, fork_op, lld, \
	lldi, lfork, aff};
	instr_t tmp;

	read_from_mem(env->memory, &tmp, sizeof(instr_t), p->PC);
	p->pc_backup = p->PC;
	if (tmp.code == 1 || tmp.code == 9 || \
	tmp.code == 12 || tmp.code == 15)
		up_pc(p, 1);
	else
		up_pc(p, sizeof(instr_t));
	p->info = &tmp;
	if (tmp.code > 16 || tmp.code < 1)
		p->cycle = 1;
	else
		fctns[tmp.code - 1](env, p, tmp);
}

int run(env_t *env) {
	while (!(env->end)) {
		for (program_t *p = env->prgm; p; p = p->next) {
			p->cycle ? 0 : execute_prog(env, p);
		}
		manage_cycle(env);
	}
	my_printf("The player %d(%s) has won\n",	\
		env->last_id, env->last_name);
	return (0);
}
