/*
** EPITECH PROJECT, 2018
** my_malloc
** File description:
** fct used to verify all malloc
*/

#include "my.h"
#include <unistd.h>
#include <stdio.h>

void *my_malloc(int const size)
{
	void *alloc = malloc(size);

	if (!alloc) {
		write(2, "Malloc failed\n", 14);
		return (0);
	}
	return (alloc);
}
