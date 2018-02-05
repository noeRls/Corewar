/*
** EPITECH PROJECT, 2017
** my_str_numcmp
** File description:
** compare the value pf two str nbr
*/

#include "my.h"

int my_str_numcmp(char const *nb1, char const *nb2)
{
	int list[2] = {0};
	int c[2];
	char const *n[2] = {nb1, nb2};

	for (int i = 0; i < 2; i++)
		if (n[i][0] == '-') {
			list[i] = my_strlen(&n[i][1]);
			c[i] = 1;
		}
		else {
			list[i] = my_strlen(n[i]);
			c[i] = 0;
		}
	if (list[0] > list[1])
		return (1);
	else if (list[1] > list[0])
		return (-1);
	else
		return (my_strcmp(&nb1[c[0]], &nb2[c[1]]));
}
