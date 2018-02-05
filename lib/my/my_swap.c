/*
** EPITECH PROJECT, 2017
** my_swap
** File description:
** swap_content_of_two_integer
*/

#include "my.h"

void my_swap(int *a, int *b)
{
	int tmp = 0;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
