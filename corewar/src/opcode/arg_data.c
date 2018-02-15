/*
** EPITECH PROJECT, 2018
** arg data
** File description:
** args data
*/

#include "corewar.h"

type_arg_t get_arg_type(char desc, int arg_nbr)
{
	char nbr;
	type_arg_t type;

	nbr = desc >> (4 - arg_nbr) * 2;
	nbr &= 3;
	switch (nbr) {
	case 1:
		type = REG;
		break;
	case 2:
		type = DIR;
		break;
	case 3:
		type = IND;
		break;
	default:
		type = NONE;
		break;
	}
	return (type);
}

int get_size_type(type_arg_t type, int is_special)
{
	switch (type) {
	case DIR:
		return (is_special ? IND_SIZE : DIR_SIZE);
		break;
	case IND:
		return (IND_SIZE);
		break;
	case REG:
		return (T_REG);
		break;
	default:
		return (0);
	}
}

int get_arg_data(env_t *env, program_t *p, type_arg_t type)
{
	int value = 0;
	int size = 0;
	int special_size = is_special_size(p->info->code);

	size = get_size_type(type, special_size);
	if (size == -1)
		return (0);
	read_from_mem(env->memory, &value, size, p->PC);
	swap(&value, size);
	if (special_size && (type == DIR || type == IND))
		value = (short int) value;
	up_pc(p, size);
	return (value);
}
