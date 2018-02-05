/*
** EPITECH PROJECT, 2017
** str words
** File description:
** str to word array
*/

#include "my.h"
#include <stdlib.h>

static int remains(char const *str)
{
	for (int i = 0; str[i]; i++) {
		if (my_char_isnum(str[i]) || my_char_isalpha(str[i])) {
			return (1);
		}
	}
	return (0);
}

static int count_words(char const *str)
{
	int wasw = 0;
	int count = 0;

	for (int i = 0; str[i]; i++) {
		if (wasw && remains(&str[i]) && (!my_char_isnum(str[i])	\
						&& !my_char_isalpha(str[i]))) {
			wasw = 0;
			count++;
		} else if (my_char_isnum(str[i]) || my_char_isalpha(str[i])) {
			wasw = 1;
		}
	}
	return (count + 1);
}

char **str_words(char *str)
{
	int words = count_words(str);
	char **res = my_malloc(sizeof (char *) * (words + 1));
	int wasw = 0;
	int ind = 0;

	for (int i = 0; str[i]; i++) {
		if (!my_char_isnum(str[i]) && !my_char_isalpha(str[i])) {
			str[i] = 0;
			wasw = 0;
		} else if (!wasw && (my_char_isnum(str[i]) ||		\
			my_char_isalpha(str[i]))) {
			res[ind++] = &str[i];
			wasw = 1;
		}
	}
	res[ind] = NULL;
	return (res);
}
