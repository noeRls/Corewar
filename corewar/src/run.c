/*
** EPITECH PROJECT, 2018
** run
** File description:
** core fct of the vm
*/

#include "corewar.h"

int nbr_prog_alive(env_t *env)
{
	int nbr_alive = 1;

	for (program_t *prgm = env->prgm; prgm; prgm = prgm->next) {
		nbr_alive += 1;
	}
	return (nbr_alive);
}

void manage_cycle(env_t *env)
{
	for (program_t *prgm = env->prgm; prgm; prgm = prgm->next) {
		prgm->live_signal += 1;
		if (prgm->live_signal > env->cycle_to_die)
			//destroy_program(prgm);
			;
		prgm->cycle -= 1;
	}
	if (env->live_counter >= NBR_LIVE) {
		env->cycle_to_die -= CYCLE_DELTA;
		env->live_counter = 0;
	}
	env->cycle += 1;
}

int execute_prog(env_t *env, program_t *p)
{
	static void (*fctns[])(env_t *, program_t *, instr_t) = {live, ld, st, add, sub, and, or, xor, zjmp, ldi, sti, fork_op, lld, lldi, lfork, aff};
	instr_t tmp;

	read_from_mem(env->memory, &tmp, sizeof(instr_t), p->PC);
	p->PC += sizeof(instr_t);
	p->info = &tmp;
	fctns[tmp.code](env, p, tmp);
}

int run(env_t *env) {
	while (nbr_prog_alive(env) > 2) {
		for (program_t *p = env->prgm; p; p = p->next) {
			if (!p->cycle) {
				execute_prog(env, p);
			}
		}
		manage_cycle(env);
	}
}
