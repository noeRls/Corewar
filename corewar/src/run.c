/*
** EPITECH PROJECT, 2018
** run
** File description:
** core fct of the vm
*/

#include "corewar.h"

int nbr_prog_alive(env_t *env)
{
	int nbr_alive = 0;

	for (program_t *prgm = env->prgm; prgm; prgm = prgm->next) {
		nbr_alive += 1;
	}
	return (nbr_alive);
}

void manage_cycle(env_t *env)
{
	for (program_t *prgm = env->prgm; prgm; prgm = prgm->next) {
		prgm->live_signal += 1;
		if (prgm->live_signal > env->cycle_to_die)
			destroy_program(prgm);
		prgm->cycle -= 1;
	}
	if (env->live_counter >= NBR_LIVE) {
		env->cycle_to_die -= CYCLE_DELTA;
		env->live_counter = 0;
	}
	env->cycle += 1;
}

int run(env_t *env) {
	while (nbr_prog_alive(env) > 2) {
		/*read_prog_data();*/ //if cycle == 0 read data
		/*execute_prog();*/ //if cycle == 0 execute
		//during execution, don't forget to set the new cycle time
		manage_cycle(env);
	}
}
