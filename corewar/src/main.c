/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** main
*/

#include "corewar.h"

void init(int ac, char **av, env_t *env)
{
	env->nbr_player = ac - 1
	env->players = malloc(sizeof(player_t) * (env->nbr_player));
	env->cycle_to_die = CYCLE_TO_DIE;
	env->alive = malloc(sizeof(int) * env->nbr_player);
	env->cycle = 0;
	for (int i = 0; i < env->nbr_player) {
		env->player[0] = 0;
		env->alive[0] = 0;
	}
}

int main(int ac, char **av)
{
	env_t env;

	init(ac, av, &env);
	run(env);
	return (0);
}
