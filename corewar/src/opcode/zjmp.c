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
	int real_pc = p->PC - 1;

	read_from_mem(env->memory, &a, sizeof(char), p->PC);
	read_from_mem(env->memory, &b, sizeof(char), p->PC + 1);
	a = b - a;
	if (a < 0)
		p->PC = real_pc - (a + 1);
	else
		p->PC = real_pc + a;
}
