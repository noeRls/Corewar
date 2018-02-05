/*
** EPITECH PROJECT, 2018
** my_calloc
** File description:
** fct used to malloc and mem set
*/

#include "my.h"
#include <stdio.h>

char *my_calloc(int const array_size, char const mem_value)
{
	char *alloc = my_malloc(array_size);

	for (int i = 0; i < array_size; i++)
		alloc[i] = mem_value;
	return (alloc);
}
