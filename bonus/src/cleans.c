/*
** EPITECH PROJECT, 2018
** cleans
** File description:
** cleans
*/

#include "corewar.h"

void clean_args(args_t *args)
{
	free(args->prog_paths);
	free(args->mem_start);
}

void clean_env(env_t *env)
{
	free(env->prgm);
}

void clean_progs(program_t *list)
{
	program_t *next = 0;

	for (program_t *tmp = list; tmp; tmp = next) {
		next = tmp->next;
		free(tmp);
	}
}
