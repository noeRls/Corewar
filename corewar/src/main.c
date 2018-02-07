/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** main
*/

void init(int ac, char **av, env_t *env)
{
	env->players = malloc(sizeof(player_t) * (ac - 1));
	for (int i = 0; i < ac - 1);
}

int main(int ac, char **av)
{
	env_t env;

	init(ac, av, &env);
	for (int i = 0; i < env.players; i++) {

	}
}
