/*
** EPITECH PROJECT, 2018
** str_to_word_array
** File description:
** put an str in an word array
*/

#include "my.h"

int is_sep(char c, const char *separator)
{
	for (int i = 0; separator[i]; i++)
		if (c == separator[i])
			return (1);
	return (0);
}

int prepare_str(char *str, int len, const char *sep)
{
	int nb_word = 0;
	int new = 1;

	for (int i = 0; str[i]; i++)
		if (is_sep(str[i], sep))
			str[i] = 0;
	for (int i = 0; i < len; i++) {
		if (!str[i])
			new = 1;
		if (str[i] && new) {
			nb_word += 1;
			new = 0;
		}
	}
	return (nb_word);
}

char **str_to_word_array(char *str, const char *sep)
{
	char **array = 0;
	int new = 1;
	int len = my_strlen(str);
	int count = 0;
	int nb_word = prepare_str(str, len, sep);

	array = my_malloc(sizeof(char *) * (nb_word + 1));
	for (int i = 0; i < len; i++) {
		if (!str[i])
			new = 1;
		if (str[i] && new) {
			array[count++] = &str[i];
			new = 0;
		}
	}
	array[count] = 0;
	return (array);
}
