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
	int lived = 0;

	read_from_mem(env->memory, &id, sizeof(int), get_pc(env->memory, p));
	swap(&id, sizeof(int));
	up_pc(env->memory, p, sizeof(int));
	set_cycle(p, info.code);
	for (program_t *p_tmp = env->prgm; p_tmp; p_tmp = p_tmp->next) {
		if (p_tmp->id == id) {
			p_tmp->live_signal = 0;
			lived += 1:
		}
	}
	if (lived)
		my_printf("The player %d(%s) is alive\n", p->id, p->name);
}
