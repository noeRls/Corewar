/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** main
*/

#include "corewar.h"

program_t start_prog(char *path)
{
	int fd = open(path);
	program_t prgm;

	if (!fd)
		exit(84);
	prgm.fd = fd;
	prgm.prog_nb = 0;
	prgm.carry = 0;
	prgm.fork = 0;
	prgm.last_live_signal = 0;
	my_memset(prgm.reg, 0, REG_NUMBER * sizeof(int));
	return (prgm);
}

void init(int ac, char **av, env_t *env)
{
	env->cycle_to_die = CYCLE_TO_DIE;
	env->cycle = 0;
	env->prgm = malloc(sizeof(program_t));
	*(env->prgm) = start_prog(av[1]);
	for (int i = 2; i < ac; i++) {
	}
}

int main(int ac, char **av)
{
	env_t env;

	init(ac, av, &env);
	run(env);
	return (0);
}
