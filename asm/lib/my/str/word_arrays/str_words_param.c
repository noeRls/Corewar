/*
** EPITECH PROJECT, 2017
** str words
** File description:
** str to word array
*/

#include "my.h"
#include "display_f.h"
#include <stdlib.h>

static int remains(char const *str, char const *forb)
{
	for (int i = 0; str[i]; i++)
		if (!contains(forb, str[i]))
			return (1);
	return (0);
}

static int count_words(char const *str, char const *forb)
{
	int wasw = 0;
	int count = 0;
	int in_quotes = 0;

	for (int i = 0; str[i]; i++) {
		if (str[i] == '"')
			in_quotes = !in_quotes;
		if (wasw && remains(&str[i], forb) &&
		contains(forb, str[i]) && !in_quotes) {
			wasw = 0;
			count++;
		} else if (!contains(forb, str[i]))
			wasw = 1;
	}
	return (count + 1);
}

char **manage_return(char **res, int inq)
{
	if (inq) {
		FREE(*res);
		FREE(res);
		return ((char **) -1);
	}
	return (res);
}

char **str_words_param(char const *src, char const *forb)
{
	char *str = my_strdup(src);
	int words = count_words(str, forb);
	char **res = MALLOC(sizeof (char *) * (words + 1));
	int wasw = 0;
	int ind = 0;
	int in_quotes = 0;

	for (int i = 0; str[i]; i++) {
		if (str[i] == '"' && (str[i] = ' '))
			in_quotes = !in_quotes;
		if (contains(forb, str[i]) && !in_quotes) {
			str[i] = 0;
			wasw = 0;
		} else if (!wasw && !contains(forb, str[i])) {
			res[ind++] = &str[i];
			wasw = 1;
		}
	}
	res[ind++] = NULL;
	return (manage_return(res, in_quotes));
}
