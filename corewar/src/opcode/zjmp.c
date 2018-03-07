/*
** EPITECH PROJECT, 2018
** live
** File description:
** live
*/

#include "corewar.h"

void zjmp(env_t *env, program_t *p)
{
	int arg[MAX_ARGS_NUMBER] = {0};
	int index = 0;

	p->info.desc = 128;
	if (setup_arg(arg, p, env, TRUE) == 84 && p->carry != 1) {
		p->cycle = 1;
		return;
	}
	index = arg[0];
	index += p->pc_backup;
	set_pc(p, index);
}
