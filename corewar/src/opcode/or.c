/*
** EPITECH PROJECT, 2018
** live
** File description:
** live
*/

#include "corewar.h"

void or(env_t *env, program_t *p, instr_t info)
{
	int arg[MAX_ARGS_NUMBER] = {0};
	int tmp = 0;

	if (setup_arg(arg, p, env, TRUE) == 84) {
		p->cycle = 1;
		return;
	}
	for (int i = 0; i < 2; i++) {
		tmp = 0;
		if (get_arg_type(info.desc, i + 1) == REG) {
			arg[i] = get_reg_value(env->memory, p, arg[i]);
		}
		if (get_arg_type(info.desc, i + 1) == IND) {
			read_from_mem(env->memory, &tmp, \
			READ_SIZE_BINARY_OP, arg[i]);
			swap(&tmp, READ_SIZE_BINARY_OP);
			arg[i] = tmp;
		}
	}
	p->carry = 0;
	set_reg_value(env->memory, p, arg[2], arg[0] | arg[1]);
	set_cycle(p, info.code);
}
