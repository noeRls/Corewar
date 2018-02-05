/*
** EPITECH PROJECT, 2017
** task06
** File description:
** sort array of int
*/

#include "my.h"

void my_sort_int_array(int *array, int size)
{
	for (int i = 0; i < size - 1; i++) {
		if (array[i] > array[i + 1]) {
			my_swap(&array[i], &array[i + 1]);
			my_sort_int_array(array, size);
		}
	}
}
