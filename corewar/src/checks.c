/*
** EPITECH PROJECT, 2018
** checks
** File description:
** checks
*/

#include "corewar.h"
#include "errors.h"

static void check_equal(int j, int k, int *ids)
{
	if (k != j && ids[k] == ids[j]) {
		my_printf(SAME_IDS);
		exit(84);
	}
}

void check_init(env_t *env)
{
	int *ids = my_malloc(sizeof(int) * (env->nbr_player));
	int i = 0;

	printf("NB PLAYER : %d\n", env->nbr_player);
	for (program_t *p = env->prgm; p; p = p->next) {
		ids[i] = p->id;
		i++;
	}
	for (int j = 0; j < env->nbr_player; j++) {
		for (int k = 0; k < env->nbr_player; k++) {
			check_equal(j, k, ids);
		}
	}
	free(ids);
}
