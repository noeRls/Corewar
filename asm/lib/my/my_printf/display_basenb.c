/*
** EPITECH PROJECT, 2017
** display nb base
** File description:
** display functions to display bases in my_printf
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"
#include "display_f.h"

int d_bhexa(va_list *ap, char *fl)
{
	char *str = get_nbr_base(va_arg(*ap, long long), "0123456789ABCDEF");
	char *tmp = my_malloc(sizeof (char) * (my_strlen(str) + 3));
	int count = 0;

	replace(fl, '+', 'A');
	replace(fl, ' ', 'A');
	if (contains(fl, '#') && *str != '0') {
		count = 2;
		tmp[0] = '0';
		tmp[1] = 'X';
	}
	for (int i = 0; i < my_strlen(str); i++)
		tmp[i + count] = str[i];
	count += display_nb(tmp, fl, 0);
	free(str);
	free(tmp);
	return (count);
}

int d_oct(va_list *ap, char *fl)
{
	char *str = get_nbr_base(va_arg(*ap, long long), "01234567");
	char *tmp = my_malloc(sizeof (char) * (my_strlen(str) + 3));
	int count = 0;

	replace(fl, '+', 'A');
	if (contains(fl, '#') && *str != '0') {
		count = 1;
		tmp[0] = '0';
	}
	replace(fl, ' ', 'A');
	for (int i = 0; i < my_strlen(str); i++)
		tmp[i + count] = str[i];
	count += display_nb(tmp, fl, 0);
	free(str);
	free(tmp);
	return (count);
}

void disp_ptr(char *str, char *fl)
{
	char indentc = ' ';
	char *tmp = my_malloc(sizeof (char) * (my_strlen(str) + 3));

	replace(fl, '#', 'A');
	for (int i = 0; fl[i] && indentc != '0'; i++) {
		if (fl[i] == '0' &&\
		((i > 0 && !my_char_isnum(fl[i - 1])) || !i)) {
			indentc = '0';
		}
	}
	contains(fl, '+') ? my_putchar('+') : 0;
	replace(fl, '+', 'A');
	if (indentc == '0' && !contains(fl, ' ')) {
		my_putstr("0x");
		display_nb(str, fl, -2);
	} else {
		my_strcpy(tmp, "0x");
		my_strcpy(&tmp[2], str);
		display_nb(tmp, fl, 0);
	}
}

int d_p(va_list *ap, char *fl)
{
	int count = 0;
	long long nb = va_arg(*ap, long long);
	char *str = get_nbr_base(nb, "0123456789abcdef");

	if (contains(fl, '+'))
		replace(fl, ' ', 'A');
	disp_ptr(str, fl);
	free(str);
	return (count);
}

int d_bin(va_list *ap, char *fl)
{
	char *str = get_nbr_base(va_arg(*ap, unsigned int), "01");
	int count = 0;

	replace(fl, ' ', 'A');
	replace(fl, '+', 'A');
	count = display_nb(str, fl, 0);
	free(str);
	return (count);
}
