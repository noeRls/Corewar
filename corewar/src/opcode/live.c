/*
** EPITECH PROJECT, 2018
** live
** File description:
** live
*/

#include "corewar.h"

void live(env_t *env, program_t *p, instr_t info)
{
	int id = 0;

	read_from_mem(env->memory, &id, sizeof(int), p->PC);
	up_pc(p, sizeof(int));
	set_cycle(p, info.code);
	printf("je vais live : %d\n", id);
	for (program_t *p_tmp = env->prgm; p_tmp; p_tmp = p_tmp->next) {
		if (p_tmp->id == id) {
			p_tmp->live_signal = 0;
			my_printf("id:%d est en vie\n", p->id);
		}
	}
}
