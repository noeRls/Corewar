/*
** EPITECH PROJECT, 2018
** freezer_core
** File description:
** freezer core
*/

#include "asm.h"

void *freezer(int mode, void *to_free, int size)
{
	static elem_t *start;

	start = (start == NULL ? init_freezer() : start);
	if (mode == 1)
		return (my_my_malloc(size, start));
	if (mode == 0)
		return (multifree(&start));
	if (mode == 2)
		return (my_my_free(to_free, start));
	my_puterror("Freezer: mode:\n"
		"0 to free everything, 1 to malloc, 2 to free");
	my_puterror(ORIGIN);
	exit(84);
	return (NULL);
}
