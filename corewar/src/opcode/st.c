/*
** EPITECH PROJECT, 2018
** live
** File description:
** live
*/

#include "corewar.h"

void st(env_t *env, program_t *p)
{
	int arg[MAX_ARGS_NUMBER] = {0};
	int value = 0;

	if (setup_arg(arg, p, env, TRUE) == 84) {
		p->cycle = 1;
		return;
	}
	value = p->reg[arg[0]];
	if (get_arg_type(p->info.desc, 2) == REG) {
		p->reg[arg[1]] = value;
	} else {
		swap(&value, sizeof(int));
		write_to_mem(env->memory, &value, sizeof(int), arg[1]);
	}
}
