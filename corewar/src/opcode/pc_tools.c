/*
** EPITECH PROJECT, 2018
** pc tools
** File description:
** pc tools
*/

#include "corewar.h"

void set_pc(program_t *p, int value)
{
	p->PC = value;
}

int up_pc(program_t *p, int size)
{
	p->PC += size;
	return (0);
}
