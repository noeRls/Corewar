/*
** EPITECH PROJECT, 2018
** live
** File description:
** live
*/

#include "corewar.h"

static int setup(env_t *env, int *arg, program_t *p)
{
	int sum = 0;
	short int tmp = 0;

	for (int i = 1; i < 3; i++) {
		if (get_arg_type(p->info.desc, i + 1) == DIR)
			sum += (short int) arg[i];
		if (get_arg_type(p->info.desc, i + 1) == IND) {
			read_from_mem(env->memory, &tmp, IND_SIZE, arg[i]);
			swap(&tmp, IND_SIZE);
			sum += tmp;
		}
	}
	return (sum);
}

void ldi(env_t *env, program_t *p)
{
	int arg[MAX_ARGS_NUMBER] = {0};
	int sum = 0;
	int value = 0;

	if (setup_arg(arg, p, env, TRUE) == 84) {
		p->cycle = 1;
		p->carry = 1;
		return;
	}
	sum = setup(env, arg, p);
	sum += p->pc_backup;
	sum = do_idx_mod(sum, p);
	read_from_mem(env->memory, &value, REG_SIZE, sum);
	swap(&value, REG_SIZE);
	p->reg[arg[2]] = value;
	p->carry = 0;
}
