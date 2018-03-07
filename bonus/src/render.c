/*
** EPITECH PROJECT, 2018
** render
** File description:
** redner
*/

#include "corewar.h"

static const char rgb_id[7][3] = {
	{150, 150, 150},
	{0, 0, 150},
	{150, 0, 0},
	{0, 150, 0},
	{0, 150, 150},
	{150, 0, 150},
	{150, 150, 0}
};

int player_nbr(env_t *env, int id)
{
	for (int i = 0; i < env->nbr_player && i < 7; i++)
		if (env->player_id[i] == id)
			return (i + 1);
	return (0);
}

void render(env_t *env)
{
	int p_nb = 0;
	sfColor color;

	sfRenderWindow_clear(env->win, sfBlack);
	for (int i = 0; i < MEM_SIZE; i++) {
		p_nb = player_nbr(env, env->memory[i].last_id);
		color = sfColor_fromRGB(rgb_id[p_nb][0], \
					rgb_id[p_nb][1], rgb_id[p_nb][2]);
		if (env->memory[i].lived) {
			p_nb = player_nbr(env, env->memory[i].lived - 1);
			color = sfColor_fromRGB(rgb_id[p_nb][0],	\
					rgb_id[p_nb][1], rgb_id[p_nb][2]);
			color = sfColor_add(color, color);
		}
		sfSprite_setColor(env->sprites[i], color);
		sfRenderWindow_drawSprite(env->win, env->sprites[i], NULL);
	}
	sfRenderWindow_display(env->win);
}
