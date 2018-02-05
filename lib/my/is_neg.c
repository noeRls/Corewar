/*
** EPITECH PROJECT, 2017
** is_neg
** File description:
** return 1 if number is positive
*/

int is_neg(char const *nb)
{
	if (nb && nb[0] == '-' && nb[1])
		return (1);
	return (0);
}
