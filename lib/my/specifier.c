/*
** EPITECH PROJECT, 2017
** specifier fct
** File description:
** part 1
*/

#include "my.h"
#include "my_printf.h"

int spe_d_i(va_list *ap, int *flag)
{
	long long t = 0;
	int res = 0;

	t = flag[5] ? va_arg(*ap, long int) : va_arg(*ap, int);
	res += applying_flag(t, flag, 0, 0);
	t < 0 && flag[1] ? t = t * -1 : 0;
	my_put_nbr(t);
	res += determine_lenght(t);
	t < 0 ? res++ : 0;
	res += padd_it(res, flag, 1);
	return (res);
}

int spe_u(va_list *ap, int *flag)
{
	long long t = 0;
	int res = 0;

	t = flag[5] ? va_arg(*ap, unsigned long int) : \
		va_arg(*ap, unsigned int);
	res += padd_it(determine_lenght(t), flag, 0);
	my_put_nbr(t);
	res += determine_lenght(t);
	res += padd_it(res, flag, 1);
	return (res);
}

int spe_b(va_list *ap, int *flag)
{
	long long t = 0;
	char *str = 0;
	char *tmp = 0;
	int res = 0;

	t = flag[5] ? va_arg(*ap, unsigned long int) : \
		va_arg(*ap, unsigned int);
	str = convert_base((tmp = its(t)), "0123456789", "01");
	free(tmp);
	res += applying_flag(0, flag, 0, str);
	res += my_strlen(str);
	my_putstr(str);
	res += padd_it(res, flag, 1);
	free(str);
	return (res);
}

int spe_o(va_list *ap, int *flag)
{
	long long t = 0;
	char *str = 0;
	int res = 0;
	char *tmp = 0;

	t = flag[5] ? va_arg(*ap, unsigned long int) : \
		va_arg(*ap, unsigned int);
	str = convert_base((tmp = its(t)), "0123456789", "01234567");
	free(tmp);
	if (ZERO(str))
		res += applying_flag(0, flag, 0, str);
	else
		res += applying_flag(0, flag, "0", str);
	my_putstr(str);
	res += my_strlen(str);
	free(str);
	return (res);
}

int spe_x(va_list *ap, int *flag)
{
	long long t = 0;
	char *str = 0;
	int res = 0;
	char *tmp = 0;

	t = flag[5] ? va_arg(*ap, unsigned long int) : \
		va_arg(*ap, unsigned int);
	str = convert_base((tmp = its(t)), "0123456789", "0123456789abcdef");
	free(tmp);
	if (ZERO(str))
		res += applying_flag(0, flag, 0, str);
	else
		res += applying_flag(0, flag, "0x", str);
	my_putstr(str);
	res += my_strlen(str);
	res += padd_it(res, flag, 1);
	free(str);
	return (res);
}
