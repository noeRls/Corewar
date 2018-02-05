/*
** EPITECH PROJECT, 2018
** my_ammloc
** File description:
** my_malloc
*/

#include <stdlib.h>
#include <stdio.h>

void *my_malloc(int size)
{
	void *res = malloc(size);

	if (!res)
		exit(84);
	return (res);
}
