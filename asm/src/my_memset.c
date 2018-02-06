/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** my_memset
*/

#include "asm.h"

void *my_super_memset(void *ptr, int c, size_t n)
{
	for (size_t i = 0; i < n; i++) {
		*((char *)ptr++) = c;
	}
	return (ptr);
}
