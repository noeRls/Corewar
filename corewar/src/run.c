/*
** EPITECH PROJECT, 2018
** run
** File description:
** core fct of the vm
*/

#include "corewar.h"

int nbr_ply_alive(env_t *env)
{
	int nbr_alive = 0;

	for (int i = 0; i < env->nbr_player; i++)  {
		if (env->alive[i] != -1)
			nbr_alive += 1;
	}
	return (nbr_alive);
}

void manage_cycle(env_t *env)
{
	for (int i = 0; i < env->nbr_player) { //manage alive - dead
		if (env->alive[i] != -1) //= isn't dead
			env->alive[i] += 1;
		if (env->alive[i] > env->cycle_to_die)
			env->alive[i] = -1;
	}
	for (int i = 0; i < env->nbr_player; i++) { //manage cycle in prog
		player[i]->cycle -= 1;
	}
	if (env->live_counter >= NBR_LIVE)
		env->cycle_to_die -= CYCLE_DELTA
}

int read_prog_data(prog)
{

}

int run(env_t *env) {

	while (nbr_ply_alive(env) > 2) {
		read_prog_data(); //if cycle == 0 read data
		execute_prog(); //if cycle == 0 execute
		//during execution, don't forget to set the new cycle time
		manage_cycle(env);
	}
}
