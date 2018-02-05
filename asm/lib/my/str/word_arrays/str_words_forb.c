/*
** EPITECH PROJECT, 2017
** str words
** File description:
** str to word array
*/

#include "my.h"
#include <stdlib.h>
#include "display_f.h"

static int remains(char const *str, char const *forb)
{
	for (int i = 0; str[i]; i++) {
		if (!contains(forb, str[i])) {
			return (1);
		}
	}
	return (0);
}

static int count_words(char const *str, char const *forb)
{
	int wasw = 0;
	int count = 0;

	for (int i = 0; str[i]; i++) {
		if (wasw && remains(&str[i], forb) &&	\
		contains(forb, str[i])) {
			wasw = 0;
			count++;
		} else if (!contains(forb, str[i])) {
			wasw = 1;
		}
	}
	return (count + 1);
}

char **str_words_forb(char const *src, char const *forb)
{
	char *str = my_strdup(src);
	int words = count_words(str, forb);
	char **res = my_malloc(sizeof (char *) * (words + 1));
	int wasw = 0;
	int ind = 0;

	for (int i = 0; str[i]; i++) {
		if (contains(forb, str[i])) {
			str[i] = 0;
			wasw = 0;
		} else if (!wasw && !contains(forb, str[i])) {
			res[ind++] = &str[i];
			wasw = 1;
		}
	}
	res[ind++] = NULL;
	return (res);
}
