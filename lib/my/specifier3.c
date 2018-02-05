/*
** EPITECH PROJECT, 2017
** specifier fct
** File description:
** part 3
*/

#include "my.h"
#include "my_printf.h"

int spe_cc(va_list *ap, int *flag)
{
	char str[2] = {0};
	int printed = 0;

	flag[2] = 0;
	str[0] = va_arg(*ap, int);
	printed = print_this_str(str, 0, 0);
	printed += padd_it(printed, flag, 1);
	return (printed);
}

int spe_modulo(va_list *ap, int *flag)
{
	my_putchar('%');
	return (1);
}
