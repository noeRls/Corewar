/*
** EPITECH PROJECT, 2018
** live
** File description:
** live
*/

#include "corewar.h"

static void setup(env_t *env, program_t *p, int *arg)
{
	int tmp = 0;

	for (int i = 0; i < 2; i++) {
		tmp = 0;
		if (get_arg_type(p->info.desc, i + 1) == REG) {
			arg[i] = p->reg[arg[i]];
		}
		if (get_arg_type(p->info.desc, i + 1) == IND) {
			read_from_mem(env->memory, &tmp, \
			READ_SIZE_BINARY_OP, arg[i]);
			swap(&tmp, READ_SIZE_BINARY_OP);
			arg[i] = tmp;
		}
	}
}

void or(env_t *env, program_t *p)
{
	int arg[MAX_ARGS_NUMBER] = {0};

	if (setup_arg(arg, p, env, TRUE) == 84) {
		p->cycle = 1;
		return;
	}
	setup(env, p, arg);
	p->carry = 0;
	p->reg[arg[2]] = arg[0] | arg[1];
}
