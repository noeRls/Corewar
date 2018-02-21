/*
** EPITECH PROJECT, 2017
** display functiions
** File description:
** disp functions
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"
#include "display_f.h"

int d_cnp(va_list *ap, char *fl)
{
	int c = va_arg(*ap, int);

	if (my_char_isprintable(c)) {
		my_putchar(c);
		return (1);
	} else {
		my_putchar('\\');
		for (int i = 0; i < 3 - digits(c); i++) {
			my_putchar('0');
		}
		my_put_nbr(c);
		return (4);
	}
}

int d_mod(va_list *ap, char *fl)
{
	my_putchar('%');
	return (1);
}

int d_snp(va_list *ap, char *fl)
{
	char *str = va_arg(*ap, char *);
	int count = 0;
	int indent = 0;

	str = check_null(str);
	for (int i = 0; fl[i] && indent == 0; i++)
		if (my_char_isnum(fl[i]) && !contains(fl, '-'))
			indent = getnbr(&fl[i]);
	count += my_putchars(' ', indent - my_strlen(str));
	for (int i = 0; str[i]; i++) {
		if (str[i] >= 32 && str[i] != 127) {
			my_putchar(str[i]);
		} else {
			my_putchar('\\');
			my_putchars('0', 3 - b_digits(str[i], 8));
			my_putstr(get_nbr_base((int) str[i], "01234567"));
		}
	}
	return (my_strlen(str) + 3 * count_np(str));
}

int d_char(va_list *ap, char *fl)
{
	char c = (char) va_arg(*ap, int);
	char *tmp = MALLOC(2);

	tmp[0] = c;
	tmp[1] = 0;
	display_str(tmp, fl);
	FREE(tmp);
	return (1);
}

int d_str(va_list *ap, char *fl)
{
	char *str = va_arg(*ap, char *);
	int count = 0;
	int indent = 0;
	int len = my_strlen(fl);

	str = check_null(str);
	display_str(str, fl);
	return (count + my_strlen(str));
}
