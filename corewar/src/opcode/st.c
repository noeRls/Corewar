/*
** EPITECH PROJECT, 2018
** live
** File description:
** live
*/

#include "corewar.h"

void st(env_t *env, program_t *p, instr_t info)
{
	int arg[MAX_ARGS_NUMBER] = {0};
	int value = 0;

	if (setup_arg(arg, p, env, TRUE) == 84) {
		p->cycle = 1;
		return;
	}
	value = get_reg_value(env->memory, p, arg[0]);
	if (get_arg_type(info.desc, 2) == REG) {
		set_reg_value(env->memory, p, arg[1], value);
	} else {
		write_to_mem(env->memory, &value, sizeof(int), arg[1]);
	}
	set_cycle(p, info.code);
}
