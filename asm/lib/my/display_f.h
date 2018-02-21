/*
** EPITECH PROJECT, 2017
** header
** File description:
** header for my_printf
*/

#include <stdarg.h>
#include "my.h"

/*	display_basenb.c	*/

int d_bhexa(va_list *ap, char *fl);
int d_oct(va_list *ap, char *fl);
void disp_ptr(char *str, char *fl);
int d_p(va_list *ap, char *fl);
int d_bin(va_list *ap, char *fl);

/*	display_f.c	*/

int d_cnp(va_list *ap, char *fl);
int d_mod(va_list *ap, char *fl);
int d_snp(va_list *ap, char *fl);
int d_char(va_list *ap, char *fl);
int d_str(va_list *ap, char *fl);

/*	display_nb.c	*/

int print_nb(char *nb, int indent, char indentc, char *fl);
int display_nb(char *nb, char *fl, int indentmod);
int d_int(va_list *ap, char *fl);
int d_u(va_list *ap, char *fl);
int d_hexa(va_list *ap, char *fl);

/*	display_tools.c	*/

void replace(char *str, char tf, char tr);
void *check_null(void *ptr);
int my_putchars(char c, int times);
int count_np(char *str);
int b_digits(int nb, int b);

/*	indent.c	*/

int print_str(char *nb, int indent, char indentc, char *fl);
int display_str(char *nb, char *fl);
void indent_nb(char *fl, int indent, char indentc, int len);
void manage_ind(char const *fl, char const *nb, int *indent);
void indent_str(char *fl, int indent, char indentc, int len);

/*	my_printf.c	*/

int contains(char const *str, char c);
char *flags_manager(char *str);
int print(char **str, int (**fctns)(va_list *, char *), va_list *ap);
int my_rec(char *str, int count, va_list *ap, int (**fctns)(va_list *, char *));
int my_printf(char *str, ...);
