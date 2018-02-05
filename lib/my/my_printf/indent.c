/*
** EPITECH PROJECT, 2017
** indent functions
** File description:
** indent
*/

#include "my.h"
#include "display_f.h"

int print_str(char *nb, int indent, char indentc, char *fl)
{
	if (contains(fl, '+') && !indent) {
		indent--;
	}
	manage_ind(fl, nb, &indent);
	!contains(fl, '-') ? indent_str(fl, indent, indentc, my_strlen(nb)) : 0;
	my_putstr(nb);
	contains(fl, '-') ? indent_str(fl, indent, indentc, my_strlen(nb)) : 0;
	return (1);
}

int display_str(char *nb, char *fl)
{
	int indent = 0;
	char indentc = ' ';

	for (int i = 0; fl[i]; i++)
		if (my_char_isnum(fl[i])) {
			indent = getnbr(&fl[i]);
			break;
		}
	return (print_str(nb, indent, indentc, fl)  + my_strlen(nb));
}

void indent_nb(char *fl, int indent, char indentc, int len)
{
	for (int i = 0; i < indent - len - (contains(fl, '+') && indent); i++) {
		my_putchar(indentc);
	}
}

void manage_ind(char const *fl, char const *nb, int *indent)
{
	if (contains(fl, '+') && *nb == '-')
		(*indent)++;
}

void indent_str(char *fl, int indent, char indentc, int len)
{
	for (int i = 0; i < indent - len; i++) {
		my_putchar(indentc);
	}
}
