/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** main
*/

#include "corewar.h"

void add_prog(program_t **start, program_t *to_add)
{
	program_t *last = 0;

	if (!(*start))
		*start = to_add;
	for (last = (*start); last->next; last = last->next);
	last->next = to_add;
	to_add->next = 0;
}

program_t *prog_dup(program_t *prog)
{
	program_t *prgm = malloc(sizeof(program_t));

	prgm->pc_curr = prog->pc_curr;
	prgm->pc_backup = prog->pc_backup;
	prgm->info = prog->info;
	prgm->id = prog->id;
	prgm->fd = prog->fd;
	prgm->live_signal = prog->live_signal;
	prgm->cycle = prog->cycle;
	prgm->carry = 0;
	prgm->mem_start = prog->mem_start;
	prgm->next = 0;
	return (prgm);
}

program_t *start_prog(char *path)
{
	int fd = open(path, O_RDONLY);
	program_t *prgm = malloc(sizeof(program_t));

	if (!fd)
		exit(84);
	prgm->cycle = 0;
	prgm->fd = fd;
	prgm->carry = 0;
	prgm->live_signal = 0;
	prgm->cycle = 0;
	prgm->pc_curr = 0;
	prgm->pc_backup = 0;
	return (prgm);
}

static void magic_reverse(void *x)
{
	*((char *)x) ^= *(((char *)x) + 3);
	*(((char *)x) + 3) ^= *((char *)x);
	*((char *)x) ^= *(((char *)x) + 3);
	*(((char *)x) + 1) ^= *(((char *)x) + 2);
	*(((char *)x) + 2) ^= *(((char *)x) + 1);
	*(((char *)x) + 1) ^= *(((char *)x) + 2);
}

void ini_prog_memory(env_t *env)
{
	header_t hd;
	int x = 10;
	int pc_value = 0;

	for (program_t *tmp = env->prgm; tmp; tmp = tmp->next, ++x) {
		tmp->id = x;
		set_reg_value(env->memory, tmp, 1, x);
		tmp->pc_curr = tmp->mem_start + REG_NUMBER * REG_SIZE;
		read(tmp->fd, &hd, sizeof(header_t));
		magic_reverse(&(hd.prog_size));
		read(tmp->fd, &(env->memory[get_pc(env->memory, tmp)]), \
		hd.prog_size);
	}
}

void init(args_t *arg, env_t *env)
{
	program_t *st = 0;
	program_t *start = 0;

	env->nbr_player = arg->nb_prog;
	env->cycle_to_die = CYCLE_TO_DIE;
	env->cycle = 0;
	env->prgm = malloc(sizeof(program_t));
	st = start_prog(arg->prog_paths[0]);
	st->mem_start = 0;
	st->next = 0;
	start = st;
	for (int i = 1; i < arg->nb_prog; i++) {
		st->next = start_prog(arg->prog_paths[i]);
		if (!arg->not_mem_default) { //= mem default
			st->next->mem_start = (i * (MEM_SIZE / env->nbr_player));
		} else {
			st->next->mem_start = arg->mem_start[i];
		}
		st = st->next;
	}
	st->next = 0;
	env->prgm = start;
	my_memset(env->memory, 0, MEM_SIZE);
	ini_prog_memory(env);
	env->live_counter = 0;
}

int manage_args(int ac, char **av)
{
	int i = 0;

	if (ac <= 3)
		return (83);
	//for (i = 0; i <;);
}

int get_unique_id(int const *diff_id, int size)
{
	int dflt = 1;

	for (int i = 0; i < size; i++) {
		if (dflt == diff_id[i]) {
			dflt++;
			i = -1;
		}
	}
	return (dflt);
}

int get_mem_start(int const *mem_start, int size)
{
	int *mem = malloc(sizeof(int) * (2 + size));
	int adress = 0;
	int last_size = 0;

	mem[0] = 0;
	mem[size + 1] = MEM_SIZE;
	for (int i = size; i > 0; i--) {
		if (mem_start[i] < 0)
			size--;
		else
			mem[i] = mem_start[i];
	}
	size += 2;
	my_sort_int_array(mem, size);
	for (int i = 0; i < size + 1; i++) {
		if (mem[i + 1] - mem[i] > last_size) {
			last_size = mem[i + 1] - mem[i];
			adress = mem[i] + (mem[i + 1] - mem[i] / 2);
		}
	}
	free(mem);
	return (adress);
}

void finally_setup_arg(args_t *arg)
{
	for (int i = 0; i < arg->nb_prog; i++)
		if (arg->prog_ids[i] < 0)
			arg->prog_ids[i] = get_unique_id( \
			arg->prog_ids, arg->nb_prog);
	for (int i = 0; i < arg->nb_prog; i++)
		if (arg->mem_start[i] > 0) {
			arg->mem_start[i] = arg->mem_start[i] % MEM_SIZE;
			arg->not_mem_default = 1;
		}
	for (int i = 0; i < arg->nb_prog; i++)
		if (arg->mem_start[i] < 0)
			arg->mem_start[i] = get_mem_start(arg->mem_start, arg->nb_prog);
}

int main(int ac, char **av)
{
	env_t env;
	args_t *arg = 0;

	finally_setup_arg(arg);
	init(arg, &env);
	run(&env);
	return (0);
}
