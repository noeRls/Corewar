/*
** EPITECH PROJECT, 2018
** live
** File description:
** live
*/

#include "corewar.h"

void add(env_t *env, program_t *p, instr_t info)
{
	int arg[MAX_ARGS_NUMBER] = {0};
	int value1 = 0;
	int value2 = 0;

	if (setup_arg(arg, p, env, TRUE) == 84) {
		p->cycle = 1;
		return;
	}
	value1 = get_reg_value(env->memory, p, arg[0]);
	value2 = get_reg_value(env->memory, p, arg[1]);
	set_reg_value(env->memory, p, arg[2], value1 + value2);
	set_cycle(p, info.code);
}
