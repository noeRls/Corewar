/*
** EPITECH PROJECT, 2018
** my_puterror
** File description:
** put a message on the standard error output
*/

#include "my.h"

void my_puterror(char *str)
{
	write(2, str, my_strlen(str));
}
