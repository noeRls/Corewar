/*
** EPITECH PROJECT, 2017
** libmy header
** File description:
** hi
*/

#ifndef LIBHEADER
#define LIBHEADER

#include <stdlib.h>

#define ABS(value) (((value) < 0 ? ((value) * -1) : (value)))

char *my_calloc(int const array_size, char const mem_value);
void *my_malloc(int const size);
int get_nbr_word(const char **array);
char **str_to_word_array(char *str, const char *sep);
char *get_next_line(int fd);
char *my_delete_zero(char *result, int const size);
int my_str_numcmp(char const *nb1, char const *nb2);
char *rminus(char *nb);
int is_neg(char const *nb);
char *its(long long b);
long long is_base_num(char const c, char const *base);
char *add_it(char const *str, char const c, int const pos);
char *remove_it(char* str, int c);
char *convert_base(char const *nbr, char const *base_from, char const *base_to);
long long my_getnbr_base(char const *str, char const *base);
int my_putnbr_base(int nbr, char const *base);
int get_color(unsigned char red, unsigned char green, unsigned char blue);
char *my_strnncpy(char *dest, char const *src, int x, int n);
void my_putchar(char c);
int my_isneg (int nb);
int my_put_nbr(long long nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
long long my_getnbr(char const *str);
int my_compute_power_rec(int nb, int power);
long long my_compute_power_it(long long nb, long long power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
int my_strcmp(char const *s1, char const *s2);
char*my_strupcase(char*str);
char *my_strlowcase(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
char *my_strcat(char const *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
void check_if_changement_signe(int tmp, int *negative);
long long convert_digit_to_int(int *digits, int nb_digit, int negative);
int determine_lenght(long long nb);
int goto_end_string(char const *dest, char *returned, int i);
int goto_end_str(char const *dest, int i);
int my_strncmp(char const *s1, char const *s2, int n);
int count_word(char const *str);
int my_char_isalpha(char const c);
int my_c_isnum(char c);
int my_printf(char const *str, ...);
int is_arg(int *occu, char **flag, int nbr_flag, char *arg);

#endif
