/*
** EPITECH PROJECT, 2018
** live
** File description:
** live
*/

#include "corewar.h"

void ld(env_t *env, program_t *p, instr_t info)
{
	char reg_nbr;
	int value;
	int pc_b = p->PC;
	int arg[MAX_ARGS_NUMBER] = {0};

	if (setup_arg(&arg, p, &info, TRUE) == 84) {
		p->cycle = 1;
		return;
	}
	p->carry = 0;
	set_cycle(p, info.code);
	p->reg[arg[1]] = value;
}
