/*
** EPITECH PROJECT, 2017
** my_char_isnum
** File description:
** return 1 if it's a num or 0 if not
*/

int my_c_isnum(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}
