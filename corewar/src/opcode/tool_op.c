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

int up_pc(program_t *p, int size)
{
	p->PC += size;
	return (0);
}

int get_arg_data(env_t *env, program_t *p, type_arg_t type)
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
	default:
		return (0);
	}
	read_from_mem(&(env->memory[p->PC]), &value, size);
	up_pc(p, size);
}

void set_cycle(program_t *p, char code)
{
	p->cycle = op_tab[code - 1].nbr_cycles;
}

void manage_idx_mod(int *value, program_t *p, int idx_mod_ind)
{
	if (idx_mod_ind) {
		*value = (*value - p->mem_start) % IDX_MOD;
		*value = *value + p->mem_start;
	} else {
		*value = *value % MEM_SIZE;
	}
}

int setup_arg(int *arg, program_t *p, env_t *env, int idx_mod_ind)
{
	type_arg_t type;
	instr_t *info = p->info;

	for (int i = 0; i < op_tab[info->code - 1].nbr_args; i++) {
		type = get_arg_type(info->desc, i + 1);
		if (!(type & op_tab[info->code - 1].type[i]))
			return (84);
		arg[i] = get_arg_data(env, p, type);
		if (type == REG && arg[i] > REG_NUMBER)
			return (84);
		if (type == IND) {
			arg[i] = p->PC + arg[i];
			manage_idx_mod(&(arg[i]), p, idx_mod_ind);
		}
	}
	return (0);
}
