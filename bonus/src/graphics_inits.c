/*
** EPITECH PROJECT, 2018
** graphics inits
** File description:
** graphics inits
*/

#include <math.h>
#include "corewar.h"

void init_window(env_t *env)
{
	sfVideoMode mode = {800, 600, 32};
	sfVector2f pos;
	sfFloatRect bounds;
	int tmp = 0;
	int offset = 0;
	int line = (int) sqrt(MEM_SIZE);
	int start = 0;
	
	my_memset(&pos, 0, sizeof(sfVector2f));
	env->win = sfRenderWindow_create(mode, "My_corewar", sfDefaultStyle, NULL);	
	sfRenderWindow_setVerticalSyncEnabled(env->win, sfFalse);
	env->blank = sfTexture_createFromFile("blank.png", sfFalse);
	for (int i = 0; i < MEM_SIZE; i++) {
		env->sprites[i] = sfSprite_create();
		sfSprite_setTexture(env->sprites[i], env->blank, sfFalse);
		if (!(start++))
			bounds = sfSprite_getGlobalBounds(env->sprites[i]);
		sfSprite_setScale(env->sprites[i], (sfVector2f) {10 / bounds.width, 10 / bounds.height});
		sfSprite_setPosition(env->sprites[i], pos);
		pos.x += 10;
		if (tmp++ == line) {
			pos.y += 10;
			pos.x = 0;
			tmp = 0;
		}
	}
}
