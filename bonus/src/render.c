/*
** EPITECH PROJECT, 2018
** render
** File description:
** redner
*/

#include "corewar.h"

void render(env_t *env)
{
	int rgb[3] = {0};

	sfRenderWindow_clear(env->win, sfBlack);
	for (int i = 0; i < MEM_SIZE; i++) {
		rgb[0] = env->memory[i].last_id == 0;
		rgb[1] = env->memory[i].last_id == 1;
		rgb[2] = env->memory[i].last_id == 2;
		sfSprite_setColor(env->sprites[i], sfColor_fromRGBA(rgb[0] * 255, rgb[1] * 255, rgb[2] * 255, 150));
		sfRenderWindow_drawSprite(env->win, env->sprites[i], NULL);
	}
	sfRenderWindow_display(env->win);
}
	
