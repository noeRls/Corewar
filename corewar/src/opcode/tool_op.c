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

int get_pc(char *memory, program_t *p)
{
	return (get_reg_value(memory, p, 0));
}

void set_pc(char *memory, program_t *p, int value)
{
	set_reg_value(memory, p, 0, value);
}
int up_pc(char *memory, program_t *p, int size)
{
	int value = get_pc(memory, p);

	value += size;
	set_reg_value(memory, p, 0, value);
	return (0);
}

int is_special_size(char code)
{
	static const char special_size[] = {9, 10, 11, 12, 14, 15, 0};

	for (int i = 0; special_size[i]; i++) {
		if (special_size[i] == code)
			return (1);
	}
	return (0);
}

int get_arg_data(env_t *env, program_t *p, type_arg_t type)
{
	int value = 0;
	int size = 0;
	int special_size = is_special_size(p->info->code);

	printf("type : %d\n", type);
	switch (type) {
	case DIR:
		size = special_size ? IND_SIZE : DIR_SIZE;
		break;
	case IND:
		size = IND_SIZE;
		break;
	case REG:
		size = T_REG;
		break;
	default:
		return (0);
	}
	read_from_mem(env->memory, &value, size, get_pc(env->memory, p));
	printf("val : %d - PC : %d - size:%d\n\n", value, get_pc(env->memory, p), size);
	swap(&value, size);
	if (special_size && (type == DIR || type == IND)) {
		value = (short int) value;
		printf("val after SHORT : %hd\n", value);
	} else {
		printf("val after : %d\n", value);
	}
	up_pc(env->memory, p, size);
	return (value);
}

void set_cycle(program_t *p, char code)
{
	p->cycle = op_tab[code - 1].nbr_cycles;
}

int do_idx_mod(int value, program_t *p)
{
	value = (value - p->mem_start) % IDX_MOD;
	value = value + p->mem_start;
	return (value);
}

void manage_idx_mod(int *value, program_t *p, int idx_mod_ind)
{
	if (idx_mod_ind) {
		*value = do_idx_mod(*value, p);
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
		printf("setup_arg\n");
		if (!(type & op_tab[info->code - 1].type[i])) {
			printf("wrong type :%d\n", type);
			return (84);
		}
		printf("little_pass\n");
		arg[i] = get_arg_data(env, p, type);
		printf("arg[i]:%d\n", arg[i]);
		if (type == REG && (arg[i] > REG_NUMBER || arg[i] <= 0))
			return (84);
		printf("big pass\n");
		if (type == IND) {
			arg[i] = p->pc_backup + arg[i];
			manage_idx_mod(&(arg[i]), p, idx_mod_ind);
		}
	}
	return (0);
}
