/*
** EPITECH PROJECT, 2018
** live
** File description:
** live
*/

#include "corewar.h"

void set_color_live(env_t *env, int index, int id)
{
	index %= MEM_SIZE;
	if (index < 0) {
		index = MEM_SIZE + index;
	}
	sfClock_restart(env->memory[index].cl);
	env->memory[index].lived = 1 + id;
}

void live(env_t *env, program_t *p, instr_t info)
{
	int id = 0;
	int lived = 0;
	program_t *pa = 0;

	env->live_counter++;
	read_from_mem(env->memory, &id, &((mem_info_t) {sizeof(int), p->PC, p->id}));
	swap(&id, sizeof(int));
	up_pc(p, sizeof(int));
	for (program_t *p_tmp = env->prgm; p_tmp; p_tmp = p_tmp->next) {
		if (p_tmp->id == id) {
			p_tmp->live_signal = 0;
			lived += 1;
			pa = p_tmp;
		}
	}
	set_color_live(env, p->PC, id);
	if (lived)
		my_printf("The player %d(%s) is alive\n", pa->id, pa->name);
}
