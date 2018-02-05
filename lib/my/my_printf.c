/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** same function as printf
*/

#include "my.h"
#include "my_printf.h"

static int *finalize_flag(int *occ, int *i, int backup, char const *str)
{
	if (str[*i] == 'l') {
		occ[5] = 1;
		*i = *i + 1;
	}
	if (!is_specifier(str[*i])) {
		reset_flag(occ);
		*i = backup - 1;
	}
	return (occ);
}

static int *manage_flag(char const *str, int *i, int occ[7], va_list *ap)
{
	char *data[] = {" ", "+", "0", "#", "-", "l", "*"};
	int backup = *i;

	for (int nb = bad_getnb(str, i); nb || s_eq ' ' || s_eq '+' \
		|| s_eq '0' || s_eq '#' || s_eq '-' || s_eq '*'; \
	nb = bad_getnb(str, i)) {
		for (int b = 0; b < 5; b++)
			data[b][0] == str[*i] ? ++occ[b] : 0;
		if (nb || s_eq '*') {
			occ[6] = s_eq '*' ? va_arg(*ap, int) : nb;
			s_eq '*' ? *i = *i + 1 : 0;
			break;
		}
		*i = *i + 1;
	}
	return (finalize_flag(occ, i, backup, str));
}

static void ini_fct(int (*fct[13])(va_list *ap, int *flag))
{
	fct[0] = &spe_d_i;
	fct[1] = &spe_u;
	fct[2] = &spe_b;
	fct[3] = &spe_o;
	fct[4] = &spe_x;
	fct[5] = &spe_p;
	fct[6] = &spe_xx;
	fct[7] = &spe_c;
	fct[8] = &spe_ss;
	fct[9] = &spe_cc;
	fct[10] = &spe_modulo;
	fct[11] = &spe_s;
	fct[12] = &spe_d_i;
}

static int manage_specifier(int *flag, char specifier, va_list *ap, \
			int (*fct[13])(va_list *ap, int *flag))
{
	char *data = "duboxpXcSC%si";

	for (int b = 0; data[b]; b++)
		if (data[b] == specifier)
			return ((*fct[b])(ap, flag));
	my_putchar(specifier);
	return (1);
}

int my_printf(char const *str, ...)
{
	va_list ap;
	int (*fct[13])(va_list *ap, int *flag);
	int result = 0;
	int flag[7] = {0};

	ini_fct(fct);
	va_start(ap, str);
	for (int i = 0; str[i]; i++) {
		if (str[i] == '%') {
			i++;
			reset_flag(flag);
			manage_flag(str, &i, flag, &ap);
			result += manage_specifier(flag, str[i], &ap, fct);
		} else {
			my_putchar(str[i]);
			result++;
		}
	}
	va_end(ap);
	return (0);
}
