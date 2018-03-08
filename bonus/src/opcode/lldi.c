/*
** EPITECH PROJECT, 2018
** live
** File description:
** live
*/

#include "corewar.h"

static int setup(env_t *env, instr_t info, int *arg, int id)
{
	short int tmp = 0;
	int sum = 0;

	for (int i = 1; i < 3; i++) {
		if (get_arg_type(info.desc, i + 1) == DIR)
			sum += (short int) arg[i];
		if (get_arg_type(info.desc, i + 1) == IND) {
			read_from_mem(env->memory, &tmp,\
				&((mem_info_t) {IND_SIZE, arg[i], id}));
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
	sum = setup(env, info, arg, p->id);
	sum += p->pc_backup;
	read_from_mem(env->memory, &value,\
		&((mem_info_t) {REG_SIZE, sum, p->id}));
	swap(&value, REG_SIZE);
	p->reg[arg[2]] = value;
	p->carry = 0;
}
