/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** main
*/

#include "corewar.h"

program_t *start_prog(char *path)
{
	int fd = open(path);
	program_t *prgm = malloc(sizeof(program_t));

	if (!fd)
		exit(84);
	prgm->fd = fd;
	prgm->prog_nb = 0;
	prgm->carry = 0;
	prgm->fork = 0;
	prgm->live_signal = 0;
	my_memset(prgm->reg, 0, REG_NUMBER * sizeof(int));
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
	int x = 1;
	int code_size = 0;

	for (program_t *tmp = env->prgm; tmp; tmp = tmp->next) { //assign nbr
		tmp->reg = &(env->memory[tmp->mem_start]);
		tmp->reg[1] = x++; //assign r1 | id
		tmp->reg[0] = tmp->mem_start + REG_NUMBER;  //ini_pc
		read(tmp->fd, &hd, sizeof(header_t));
		magic_reverse(&(hd.prog_size));
		code_size = hd.prog_size - sizeof(header_t);
		read(tmp->fd, &(env->memory[tmp->PC]), code_size);
	}
}

void init(int ac, char **av, env_t *env)
{
	program_t *st = 0;
	program_t *start = 0;

	env->nbr_player = ac - 1;
	env->cycle_to_die = CYCLE_TO_DIE;
	env->cycle = 0;
	env->prgm = malloc(sizeof(program_t));
	st->mem_start = 0;
	st = start_prog(av[1]);
	st->next = 0;
	start = st;
	for (int i = 2; i < ac; i++) {
		st->mem_start = (i - 1) * (MEM_SIZE / env->nbr_player);
		st->next = start_prog(av[i]);
		st = st->next;
	}
	st->next = 0;
	env->prgm = start;
	for (int i = 0; i < MEM_SIZE; i++) {
		env->memory[i] = 0;
	}
	ini_prog_memory(env);
}

int main(int ac, char **av)
{
	env_t env;

	init(ac, av, &env);
	run(env);
	return (0);
}
