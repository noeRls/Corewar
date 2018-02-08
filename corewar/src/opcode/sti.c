/*
** EPITECH PROJECT, 2018
** live
** File description:
** live
*/

#include "corewar.h"

void sti(env_t *env, program_t *p, instr_t info)
{
	int arg[MAX_ARGS_NUMBER] = {0};
	int index = 0;
	int pc_b = p->PC;

	if (setup_arg(arg, p, env, TRUE) == 84) {
		p->cycle = 1;
		return;
	}
	for (int i = 1; i < 3; i++) {
		if (get_arg_type(info.desc, i + 1) == REG)
			arg[i] = p->reg[arg[i]];
		if (get_arg_type(info.desc, i + 1) == IND)
			arg[i] -= pc_b;
	}
	index += arg[1];
	index += arg[2];
	index += pc_b;
	env->memory[index] = p->reg[arg[0]];
	set_cycle(p, info.code);
}
