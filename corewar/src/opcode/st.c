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

	if (setup_arg(&arg, p, &info, TRUE) == 84) {
                p->cycle = 1;
                return;
        }
	if (get_arg_type(info.desc, 2) == REG) {
		p->reg[arg[1]] = p->reg[arg[0]];
	} else {
		env->memory[arg[1]] = p->reg[arg[0]];
	}
	set_cycle(p, info.code);
}
