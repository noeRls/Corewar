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
	prgm.fd = fd;
	prgm.prog_nb = 0;
	prgm.carry = 0;
	prgm.fork = 0;
	prgm.last_live_signal = 0;
	my_memset(prgm->reg, 0, REG_NUMBER * sizeof(int));
	return (prgm);
}

void init(int ac, char **av, env_t *env)
{
	program_t *st = 0;
	program_t *start = 0;

	env->cycle_to_die = CYCLE_TO_DIE;
	env->cycle = 0;

	st = start_prog(av[1]);
	st->next = 0;
	start = st;
	for (int i = 2; i < ac; i++) {
		st->next = start_prog(av[i]);
		st = st->next;
	}
	st->next = 0;
	env->prgm = start;
}

int main(int ac, char **av)
{
	env_t env;

	init(ac, av, &env);
	run(env);
	return (0);
}
