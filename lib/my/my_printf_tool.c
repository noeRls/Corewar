/*
** EPITECH PROJECT, 2017
** my_printf_tool
** File description:
** function needed by print_f
*/

#include "my.h"
#include "my_printf.h"

int padd_it(int len, int *flag, int after)
{
	char data = flag[2] ? '0' : ' ';
	int res = 0;

	if (!flag[4] || after) {
		for (int b = flag[6] - len; b > 0; b--) {
			my_putchar(data);
			res++;
		}
		flag[6] = 0;
	}
	return (res);
}

static int print_signe(int *flag, long long nb)
{
	if (nb >= 0 && flag[1]) {
		my_putchar('+');
		return (1);
	} else if (nb < 0 && flag[1]) {
		my_putchar('-');
		return (1);
	}
	return (0);
}

static int get_print_c(int *flag, long long nb)
{
	if (nb >= 0 && flag[1])
		return (1);
	else if (nb < 0)
		return (1);
	return (0);
}

static int manage_strflag(int *flag, char *specify, char *str)
{
	int res = 0;

	flag[2] && flag[4] ? flag[2] = 0 : 0;
	if (specify != 0 && flag[3]) {
		res += padd_it(my_strlen(specify) + my_strlen(str), \
			flag, 0);
		my_putstr(specify);
		res += my_strlen(specify);
	} else {
		res += padd_it(my_strlen(str), flag, 0);
	}
	return (res);
}

int applying_flag(long long nb, int *flag, char *specify, char *str)
{
	int res = 0;
	int print_c = 0;

	if (str) {
		res += manage_strflag(flag, specify, str);
	} else {
		print_c = get_print_c(flag, nb);
		flag[2] && flag[4] ? flag[2] = 0 : 0;
		if (flag[0] && nb >= 0 && !flag[1]) {
			my_putchar(' ');
			res++;
			print_c++;
		}
		res += flag[2] ? print_signe(flag, nb) : 0;
		if (flag[6])
			res += padd_it(determine_lenght(nb) + print_c, flag, 0);
		res += flag[2] ? 0 : print_signe(flag, nb);
	}
	return (res);
}
