/*
** EPITECH PROJECT, 2018
** graphics inits
** File description:
** graphics inits
*/

#include <math.h>
#include "corewar.h"

void ini_sprite_mem(env_t *env)
{
	sfVector2f pos = {0, 0};
	int tmp = 0;
	sfFloatRect bounds;
	int start = 0;

	for (int i = 0; i < MEM_SIZE; i++) {
		env->sprites[i] = sfSprite_create();
		sfSprite_setTexture(env->sprites[i], env->blank, sfFalse);
		if (!(start++))
			bounds = sfSprite_getGlobalBounds(env->sprites[i]);
		sfSprite_setScale(env->sprites[i], \
		(sfVector2f) {10 / bounds.width, 10 / bounds.height});
		sfSprite_setPosition(env->sprites[i], pos);
		pos.x += 10;
		if (tmp++ == (int) sqrt(MEM_SIZE)) {
			pos.y += 10;
			pos.x = 0;
			tmp = 0;
		}
	}
}

void init_window(env_t *env)
{
	sfVideoMode mode = {800, 600, 32};
	int offset = 0;

	env->win = sfRenderWindow_create(mode, "My_corewar", \
		sfDefaultStyle, NULL);
	sfRenderWindow_setVerticalSyncEnabled(env->win, sfFalse);
	env->blank = sfTexture_createFromFile("blank.png", sfFalse);
	ini_sprite_mem(env);
}
