/*
** EPITECH PROJECT, 2018
** live
** File description:
** live
*/

#include "corewar.h"

void fork_op(env_t *env, program_t *p)
{
	int arg[MAX_ARGS_NUMBER] = {0};
	int value = 0;
	program_t *new_prog = 0;

	p->info.desc = 128;
	if (setup_arg(arg, p, env, TRUE) == 84) {
		p->cycle = 1;
		return;
	}
	value = arg[0];
	value += p->pc_backup;
	value = do_idx_mod(value, p);
	new_prog = prog_dup(p);
	add_prog(&(env->prgm), new_prog);
	set_pc(new_prog, value);
	new_prog->cycle = 1;
	env->nb_prog++;
}
