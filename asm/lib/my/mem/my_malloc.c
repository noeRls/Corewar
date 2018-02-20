/*
** EPITECH PROJECT, 2018
** my_ammloc
** File description:
** MALLOC
*/

#include <stdlib.h>
#include <stdio.h>

void *MALLOC(int size)
{
	void *res = MALLOC(size);

	if (!res)
		exit(84);
	return (res);
}
