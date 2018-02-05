/*
** EPITECH PROJECT, 2017
** specifier fct
** File description:
** part 2
*/

#include "my.h"
#include "my_printf.h"
#include <stdio.h>

int spe_p(va_list *ap, int *flag)
{
	long long t = 0;
	char *str = 0;
	char *tmp = 0;
	int res = 0;

	t = va_arg(*ap, long long);
	str = convert_base((tmp = its(t)), "0123456789", "0123456789abcdef");
	free(tmp);
	res += padd_it(my_strlen(str) + 2, flag, 0);
	my_putstr("0x");
	res = my_strlen(str) + 2;
	my_putstr(str);
	res += padd_it(res, flag, 1);
	free(str);
	return (res);
}

int spe_xx(va_list *ap, int *flag)
{
	long long t = 0;
	char *str = 0;
	char *tmp = 0;
	int res = 0;

	t = flag[5] ? va_arg(*ap, unsigned long int) : \
		va_arg(*ap, unsigned int);
	t < 0 && flag[1] ? t *= -1 : 0;
	str = convert_base((tmp = its(t)), "0123456789", "0123456789ABCDEF");
	free(tmp);
	if (ZERO(str))
		res += applying_flag(0, flag, 0, str);
	else
		res += applying_flag(0, flag, "0X", str);
	my_putstr(str);
	res += my_strlen(str);
	res += padd_it(res, flag, 1);
	free(str);
	return (res);
}

int spe_c(va_list *ap, int *flag)
{
	int res = 0;
	long long t = 0;

	flag[2] = 0;
	t = va_arg(*ap, int);
	res += padd_it(1, flag, 0);
	my_putchar(t);
	res += 1;
	res += padd_it(res, flag, 1);
	return (res);
}

int spe_s(va_list *ap, int *flag)
{
	char *str = 0;
	int res = 0;
	int to_free = 0;

	flag[2] = 0;
	str = va_arg(*ap, char *);
	if (str == 0) {
		str = my_strdup("(null)");
		to_free = 1;
	}
	res += padd_it(my_strlen(str), flag, 0);
	my_putstr(str);
	res += my_strlen(str);
	res += padd_it(res, flag, 1);
	if (to_free)
		free(str);
	return (res);
}

int spe_ss(va_list *ap, int *flag)
{
	char *str = 0;
	int printed = 0;
	int to_free = 0;

	flag[2] = 0;
	str = va_arg(*ap, char*);
	if (str == 0) {
		str = my_strdup("(null)");
		to_free = 1;
	}
	printed = print_this_str(str, 0, 0);
	printed += padd_it(printed, flag, 1);
	if (to_free)
		free(str);
	return (printed);
}
