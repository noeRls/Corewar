/*
** EPITECH PROJECT, 2017
** super_arg_management
** File description:
** fct used to made eazy to manage arg
*/

#include "my.h"

int is_arg(int *occu, char **flag, int nbr_flag, char *arg)
{
	int tmp = 0;
	int a =	0;
	int ret = 0;

	for (int i = 0; i < nbr_flag; i++) {
		for (a = 0; flag[i][a] && arg[a]; a++)
			flag[i][a] == arg[a] ? tmp++ : 0;
		if (tmp == my_strlen(flag[i]) && arg[a] == 0) {
			occu[i] += 1;
			ret += 1;
		}
		tmp = 0;
	}
	return (ret);
}
