/*
** EPITECH PROJECT, 2018
** tool
** File description:
** opo
*/

#include "corewar.h"

type_arg_t get_arg_type(char desc, int arg_nbr)
{
	char nbr;

	nbr = desc >> (4 - arg_nbr) * 2;
	nbr &= 3;
	return ((type_arg_t)(nbr));
}

int up_pc(program_t *p, int size)
{
	p->PC += size;
	return (0);
}

int get_arg_value(program_t *p, type_arg_t type)
{
	int value = 0;
	int size = 0;

	switch (type) {
	case DIR:
		size = DIR_SIZE;
		break;
	case IND:
		size = IND_SIZE;
		break;
	case REG:
		size = REG_SIZE;
		break;
	}
	read_from_mem(&(env->memory[p->PC]), &value, size);
	up_pc(p, size);
}

void set_cycle(program_t *p, char code)
{
	p->cycle = op_tab[code - 1].nbr_cycles;
}

int setup_arg(int *arg, program_t *p, char desc)
{
	type_arg_t type;

	for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
		type = get_arg_type(desc, i + 1);
		if (type == NONE)
			return (84);
		arg[i] = get_arg_value(p, type);
	}
	return (0);
}
