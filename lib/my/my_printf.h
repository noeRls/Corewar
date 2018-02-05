/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** header
*/

#ifndef MY_PRINTF
#define MY_PRINTF

#define ZERO(str) str[0] == '0' && str[1] == 0
#define s_eq str[*i] ==

#include <stdarg.h>
#include <stdlib.h>

int my_printf(char const *str, ...);
int print_this_str(char *str, int i, int result);
int applying_flag(long long nb, int *flag, char *specify, char *str);
int padd_it(int len, int *flag, int after);
int is_specifier(char specifier);
int bad_getnb(char const *str, int *i);
void reset_flag(int flag[7]);

int spe_d_i(va_list *ap, int *flag);
int spe_u(va_list *ap, int *flag);
int spe_b(va_list *ap, int *flag);
int spe_o(va_list *ap, int *flag);
int spe_x(va_list *ap, int *flag);
int spe_p(va_list *ap, int *flag);
int spe_xx(va_list *ap, int *flag);
int spe_c(va_list *ap, int *flag);
int spe_ss(va_list *ap, int *flag);
int spe_cc(va_list *ap, int *flag);
int spe_modulo(va_list *ap, int *flag);
int spe_s(va_list *ap, int *flag);

#endif
