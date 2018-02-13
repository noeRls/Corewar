/*
** EPITECH PROJECT, 2018
** live
** File description:
** live
*/

#include "corewar.h"

static int setup(env_t *env, program_t *p, instr_t info, int *arg)
{
	short int tmp = 0;
	int sum = 0;

	for (int i = 1; i < 3; i++) {
		if (get_arg_type(info.desc, i + 1) == DIR)
			sum += (short int) arg[i];
		if (get_arg_type(info.desc, i + 1) == IND) {
			read_from_mem(env->memory, &tmp, IND_SIZE, arg[i]);
			swap(&tmp, IND_SIZE);
			sum += tmp;
		}
	}
	return (sum);
}

void lldi(env_t *env, program_t *p, instr_t info)
{
	int arg[MAX_ARGS_NUMBER] = {0};
	int value = 0;
	int sum = 0;

	if (setup_arg(arg, p, env, FALSE) == 84) {
		p->cycle = 1;
		p->carry = 1;
		return;
	}
	sum = setup(env, p, info, arg);
	sum += p->pc_backup;
	read_from_mem(env->memory, &value, REG_SIZE, sum);
	swap(&value, REG_SIZE);
	set_reg_value(env->memory, p, arg[2], value);
	set_cycle(p, info.code);
	p->carry = 0;
}
