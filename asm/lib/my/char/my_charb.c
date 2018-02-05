/*
** EPITECH PROJECT, 2017
** my_char 2
** File description:
** my_char 2
*/

int my_char_isprintable(char c)
{
	if (c <= 31 || c == 127)
		return (0);
	return (1);
}
