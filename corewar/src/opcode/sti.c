/*
** EPITECH PROJECT, 2018
** live
** File description:
** live
*/

#include "corewar.h"

void sti(env_t *env, program_t *p, instr_t info)
{
	printf("STI\n");
	int arg[MAX_ARGS_NUMBER] = {0};
	int index = 0;
	int pc_b = get_pc(env->memory, p) - 2;
	int tmp = 0;

	if (setup_arg(arg, p, env, TRUE) == 84) {
		p->cycle = 1;
		return;
	}
	printf("PASS\n");
	for (int i = 1; i < 3; i++) {
		if (get_arg_type(info.desc, i + 1) == REG)
			arg[i] = get_reg_value(env->memory, p, arg[i]);
		if (get_arg_type(info.desc, i + 1) == IND)
			arg[i] -= pc_b;
	}
	index += arg[1];
	index += arg[2];
	index += pc_b;
	tmp = get_reg_value(env->memory, p, arg[0]);
	write_to_mem(env->memory, &tmp, sizeof(int), index);
	set_cycle(p, info.code);
}
