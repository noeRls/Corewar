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
	int pc_b = p->PC - 2;

	if (setup_arg(arg, p, env, TRUE) == 84) {
		p->cycle = 1;
		return;
	}
	printf("PASS\n");
	for (int i = 1; i < 3; i++) {
		if (get_arg_type(info.desc, i + 1) == REG)
			arg[i] = p->reg[arg[i]];
		if (get_arg_type(info.desc, i + 1) == IND)
			arg[i] -= pc_b;
	}
	printf("arg 2 :%d, arg 3 :%d\n", arg[1], arg[2]);
	index += arg[1];
	index += arg[2];
	index += pc_b;
	printf("INDEX : %d\n", index);
	printf("val index : %d\n", p->reg[arg[0]]);
	write_to_mem(env->memory, p->reg[arg[0]], sizeof(int), index);
	set_cycle(p, info.code);
}
