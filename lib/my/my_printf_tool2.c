/*
** EPITECH PROJECT, 2017
** my_printf_tool2
** File description:
** function needed by printf
*/

#include "my.h"
#include "my_printf.h"

int is_specifier(char specifier)
{
	char *data = "duboxpXcSC%si";
	for (int b = 0; data[b]; b++)
		if (data[b] == specifier)
			return (1);
	return (0);
}

int bad_getnb(char const *str, int *i)
{
	char digit[100] = {0};
	int a = *i;
	int nb = 0;

	if (str[*i] == '0' || !my_c_isnum(str[*i]))
		return (0);
	for (*i = *i; my_c_isnum(str[*i]); *i = *i + 1)
		digit[*i - a] = str[*i];
	for (int b = *i - 1; b - a >= 0; b--)
		nb += (digit[b - a] - 48) * my_compute_power_it(10, *i - b - 1);
	return (nb);
}

static void print_ascii_nb(char c)
{
	int i = 0;
	char tmp[3] = {48, 48, 48};
	char *tmp3 = 0;
	char *tmp2 = 0;

	c = my_getnbr((tmp2 = convert_base((tmp3 = its(c)), \
		"0123456789", "01234567")));
	free(tmp3);
	free(tmp2);
	for (i = 0; c; i++) {
		tmp[2 - i] = c % 10 + 48;
		c /= 10;
	}
	my_putchar('\\');
	for (i = 0; i < 3; i++)
		my_putchar(tmp[i]);
}

int print_this_str(char *str, int i, int result)
{
	char c[2] = {str[i], 0};

	if (c[0] == 0)
		return (result);
	if (my_str_isprintable(c)) {
		my_putchar(c[0]);
		result++;
	} else {
		print_ascii_nb(c[0]);
		result += 4;
	}
	return (print_this_str(str, ++i, 0));
}

void reset_flag(int flag[7])
{
	for (int i = 0; i < 7; i++)
		flag[i] = 0;
}
