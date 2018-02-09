/*
** EPITECH PROJECT, 2018
** live
** File description:
** live
*/

#include "corewar.h"

void zjmp(env_t *env, program_t *p, instr_t info)
{
	char a = 0;
	char b = 0;
	int real_pc = get_pc(env->memory, p);

	read_from_mem(env->memory, &a, sizeof(char), get_pc(env->memory, p));
	read_from_mem(env->memory, &b, sizeof(char), \
	get_pc(env->memory, p) + 1);
	a = b - a;
	if (a < 0)
		set_pc(env->memory, p, real_pc - (a + 1));
	else
		set_pc(env->memory, p, real_pc + 1);
}
