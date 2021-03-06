/*
** EPITECH PROJECT, 2018
** live
** File description:
** live
*/

#include "corewar.h"

void lfork(env_t *env, program_t *p, instr_t info)
{
	int arg[MAX_ARGS_NUMBER] = {0};
	int value = 0;
	program_t *new_prog = 0;

	UNUSED(info);
	p->info.desc = 128;
	if (setup_arg(arg, p, env, FALSE) == 84) {
		p->cycle = 1;
		return;
	}
	value = arg[0];
	value += p->pc_backup;
	new_prog = prog_dup(p);
	add_prog(&(env->prgm), new_prog);
	set_pc(new_prog, value);
	new_prog->cycle = 1;
	env->nb_prog++;
}
