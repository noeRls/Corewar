/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** printf
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"
#include "display_f.h"

int contains(char const *str, char c)
{
	int count = 0;

	for (int i = 0; str[i]; i++) {
		if (str[i] == c)
			count++;
	}
	return (count);
}

char *flags_manager(char *str)
{
	char *fl = "#0- +'Il";
	char *res = 0;
	int i = 0;
	char *flags = "diouxXcsCSpm%b";

	for (i = 0; str[i] && (contains(fl, str[i]) || my_char_isnum(str[i]))
		&& !contains(flags, str[i]); i++) {}
	res = MALLOC(sizeof(char) * (i + 1));
	for (i = 0; str[i] && (contains(fl, str[i]) || my_char_isnum(str[i]))
		&& !contains(flags, str[i]); i++) {
		if (i > 0 && my_char_isnum(str[i - 1])
		&& !my_char_isnum(str[i]))
			break;
		res[i] = str[i];
	}
	res[i] = 0;
	return (res);
}

int print(char **str, int (**fctns)(va_list *, char *), va_list *ap)
{
	char *args = 0;
	static char *flags = "diouxXcsCSpm%b";

	args = flags_manager(*str + 1);
	if (!contains(flags, (*str)[1 + my_strlen(args)])) {
		my_putchar('%');
		FREE(args);
		return (1);
	}
	*str = *str + 1;
	*str = *str + my_strlen(args);
	for (int i = 0; flags[i]; i++) {
		if (**str == flags[i]) {
			fctns[i](ap, args);
			FREE(args);
			return (0);
		}
	}
}

int my_rec(char *str, int count, va_list *ap, int (**fctns)(va_list *, char *))
{
	static char *flags = "diouxXcsCSpm%b";
	static char *fl = "#0- +'Il";
	char *args = "";

	if (!*str || (str[0] == '%' && !str[1]))
		return (count);
	if (*str != '%') {
		my_putchar(*str);
		return (my_rec(str + 1, ++count, ap, fctns));
	}
	if (str[1] && !contains(flags, str[1]) &&
	!my_char_isnum(str[1]) && !contains(fl, str[1])) {
		my_putchar('%');
		return (my_rec(str + 1, ++count, ap, fctns));
	}
	count += print(&str, fctns, ap);
	return (my_rec(str + 1, count, ap, fctns));
}

int my_printf(char *str, ...)
{
	va_list ap;
	int result = 0;
	int (*fctns[14])(va_list *, char *) = {&d_int, &d_int, &d_oct, &d_u,
					&d_hexa, &d_bhexa, &d_char,
					&d_str, &d_cnp, &d_snp, &d_p,
					&d_mod, &d_mod, &d_bin};

	va_start(ap, str);
	result = my_rec(str, 0, &ap, fctns);
	va_end(ap);
	return (result);
}
