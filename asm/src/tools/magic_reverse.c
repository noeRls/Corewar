/*
** EPITECH PROJECT, 2018
** magic_reverse
** File description:
** swap indian, but using some magic and rainbow
*/

#include "asm.h"

void magic_reverse(void *x)
{
	*((char *)x) ^= *(((char *)x) + 3);
	*(((char *)x) + 3) ^= *((char *)x);
	*((char *)x) ^= *(((char *)x) + 3);
	*(((char *)x) + 1) ^= *(((char *)x) + 2);
	*(((char *)x) + 2) ^= *(((char *)x) + 1);
	*(((char *)x) + 1) ^= *(((char *)x) + 2);
}

void short_magic_reverse(void *x)
{
	*((char *)x) ^= *(((char *)x) + 1);
	*(((char *)x) + 1) ^= *((char *)x);
	*((char *)x) ^= *(((char *)x) + 1);
}

void the_magic_reverse(void *x, int size)
{
	for (int i = 0 ; i <= (size - 1) / 2 ; i++) {
		*(((char *)x) + i) ^= *(((char *)x) + (size - 1 - i));
		*(((char *)x) + (size - 1 - i)) ^= *(((char *)x) + i);
		*(((char *)x) + i) ^= *(((char *)x) + (size - 1 - i));
	}
}
