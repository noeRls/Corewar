/*
** EPITECH PROJECT, 2018
** live
** File description:
** live
*/

#include "corewar.h"

void ld(env_t *env, program_t *p, instr_t info)
{
	int value = 0;
	int arg[MAX_ARGS_NUMBER] = {0};

	if (setup_arg(arg, p, env, TRUE) == 84) {
		p->cycle = 1;
		p->carry = 1;
		return;
	}
	if (get_arg_type(info.desc, 1) == IND) {
		read_from_mem(env->memory, &value, REG_SIZE, arg[0]);
		swap(&value, REG_SIZE);
		arg[0] = value;
	}
	p->carry = 0;
	p->reg[arg[1]] = arg[0];
}
