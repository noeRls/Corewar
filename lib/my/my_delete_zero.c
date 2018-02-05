/*
** EPITECH PROJECT, 2017
** delete_zero
** File description:
** delete the first '0' of a str
*/

#include "my.h"

char *my_delete_zero(char *result, int const size)
{
	int i = 0;
	int neg = 0;
	char *returned = 0;

	for (i = 0; (result[i] <= '0' || result[i] > '9') && i < size; i++) {
		if (result[0] == '-')
			neg = 1;
	}
	if (i == size)
		return (my_strdup(&result[i - 1]));
	returned = my_malloc(sizeof(char) * (size - i + neg + 1));
	if (neg) {
		result[i - 1] = '-';
		my_strcpy(returned, &result[i - 1]);
	} else {
		my_strcpy(returned, &result[i]);
	}
	free(result);
	return (returned);
}
