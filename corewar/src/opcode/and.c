/*
** EPITECH PROJECT, 2018
** live
** File description:
** live
*/

#include "corewar.h"

void and(env_t *env, program_t *p, instr_t info)
{
	int arg[MAX_ARGS_NUMBER] = {0};

	if (setup_arg(&arg, p, &info, TRUE) == 84) {
		p->cycle = 1;
		return;
	}
	for (int i = 0; i < 2; i++) {
		if (get_arg_type(info.desc, i + 1) == REG)
			arg[i] = p->reg[arg[i]];
		if (get_arg_type(info.desc, i + 1) == IND)
			arg[i] = env->memory[arg[i]];
	}
	p->carry = 0;
	p->reg[arg[2]] = arg[0] & arg[1];
	set_cycle(p, info.code);
}
