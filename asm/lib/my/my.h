/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** header for "my" lib
*/

#include <stdarg.h>
#include <unistd.h>
#include "freezer.h"

void *my_malloc(int size);

/*	char/my_charb.c	*/

int my_char_isprintable(char c);

/*	char/my_char.c	*/

int my_char_isalpha(char c);
int isonlychar(char *str, char c);
int my_char_isnum(char c);
char upchar(char c);
char lowchar(char c);

/*	int/getnbr.c	*/

int getnbr(char *str);

/*	int/my_compute.c	*/

int my_compute_power(int nb, int p);
int my_compute_square_root(int nb);

/*	int/my_maths.c	*/

int digits(int a);
int my_find_prime_sup(int nb);
int my_is_prime(int nb);
int min(int a, int b);
int max(int a, int b);

/*	int/my_sort_int_array.c	*/

void my_sort_int_array(int *array, int size);

/*	mem/my_sys_utils.c	*/

void my_memset(char *str, char c, int len);
void my_swap(int *a, int *b);
void my_swap_char(char *a, char *b);

/*	put/my_put.c	*/

void my_putchar(char c);
void my_putstr(char const *str);
void my_putstr_err(char const *str);

/*	put/my_put_nbr.c	*/

void my_put_nbr(int nb);

/*	str/get_nbr_base.c	*/

char *get_nbr_base(long long nb, char const *base);

/*	str/intochar.c	*/

char *my_intochar(int base);

/*	str/my_show_word_array.c	*/

void my_show_word_array(char * const *tab);

/*	str/my_strcmps.c	*/

int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
int my_supercmp(char const *s1, char const *s2);

/*	str/my_strdigits.c	*/

int my_strdigits(long long nb);

/*	str/my_str_is.c	*/

int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);

/*	str/my_str_utilsb.c	*/

int my_strlen(char const *str);
int my_strlento(char const *str, char c);
char *my_strlowcase(char *str);
char *my_strupcase(char *str);
char *my_revstr(char *str);

/*	str/my_str_utils.c	*/

char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);

/*	str/str_words.c	*/

char **str_words(char *str);
char **str_words_adv(char *str, char const *allowed);
char **str_words_forb(char const *str, char const *forb);
char **str_words_param(char const *str, char const *forb);

/*	str/match.c	*/

int match(char const *str, char const *str1);
