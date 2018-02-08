/*
** EPITECH PROJECT, 2018
** live
** File description:
** live
*/

#include "corewar.h"

void lld(env_t *env, program_t *p, instr_t info)
{
	char reg_nbr;
	int pc_b = p->PC;
	int arg[MAX_ARGS_NUMBER] = {0};

	if (setup_arg(&arg, p, &info, FALSE) == 84) {
		p->cycle = 1;
		return;
	}
	if (get_arg_type(info.desc, 1) == IND)
		arg[0] = env->memory[arg[0]];
	p->carry = 0;
	set_cycle(p, info.code);
	p->reg[arg[1]] = env->memory[arg[0]];
}
