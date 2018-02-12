/*
** EPITECH PROJECT, 2017
** display nb
** File description:
** disp numbers
*/

#include "my.h"
#include "display_f.h"
#include <stdarg.h>
#include <stdlib.h>

int print_nb(char *nb, int indent, char indentc, char *fl)
{
	if (contains(fl, '+') && !indent) {
		indent--;
	} else if (contains(fl, ' ') && *nb != '-' && !contains(fl, '+')) {
		my_putchar(' ');
		indent--;
	}
	manage_ind(fl, nb, &indent);
	if (*nb == '-' && indentc == '0')
		my_putchar('-');
	!contains(fl, '-') ? indent_nb(fl, indent, indentc, my_strlen(nb)) : 0;
	if (contains(fl, '+') && *nb != '-')
		my_putchar('+');
	my_putstr(*nb == '-' && indentc == '0' ? nb + 1 : nb);
	contains(fl, '-') ? indent_nb(fl, indent, indentc, my_strlen(nb)) : 0;
	return (1);
}

int display_nb(char *nb, char *fl, int indentmod)
{
	int indent = 0;
	char indentc = ' ';

	for (int i = 0; fl[i]; i++)
		if (my_char_isnum(fl[i]) && fl[i] != '0') {
			indent = getnbr(&fl[i]);
			break;
		}
	for (int i = 0; fl[i]; i++)
		if (my_char_isnum(fl[i]) && fl[i] == '0' && !contains(fl, '-'))
			indentc = '0';
		else if (my_char_isnum(fl[i]) && fl[i] != '0')
			break;
	indent += indentmod;
	return (print_nb(nb, indent, indentc, fl)  + my_strlen(nb));
}

int d_int(va_list *ap, char *fl)
{
	char *str = 0;
	int count = 0;
	int tmp = 0;

	tmp = contains(fl, 'l');
	if (tmp == 1)
		str = get_nbr_base(va_arg(*ap, long), "0123456789");
	else if (tmp == 2)
		str = get_nbr_base(va_arg(*ap, long long), "0123456789");
	else
		str = get_nbr_base(va_arg(*ap, int), "0123456789");
	count = display_nb(str, fl, 0);
	free(str);
	return (count);
}

int d_u(va_list *ap, char *fl)
{
	char *str = get_nbr_base(va_arg(*ap, unsigned int), "0123456789");

	replace(fl, '+', 'A');
	replace(fl, ' ', 'A');
	display_nb(str, fl, 0);
	free(str);
	return (1);
}

int d_hexa(va_list *ap, char *fl)
{
	char *str = get_nbr_base(va_arg(*ap, long long), "0123456789abcdef");
	char *tmp = my_malloc(sizeof (char) * (my_strlen(str) + 3));
	int count = 0;

	my_memset(tmp, 0, my_strlen(str) + 3);
	replace(fl, '+', 'A');
	replace(fl, ' ', 'A');
	if (contains(fl, '#') && *str != '0') {
		count = 2;
		tmp[0] = '0';
		tmp[1] = 'x';
	}
	for (int i = 0; i < my_strlen(str); i++)
		tmp[i + count] = str[i];
	count += display_nb(tmp, fl, 0);
	free(str);
	free(tmp);
	return (count);
}
