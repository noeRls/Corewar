/*
** EPITECH PROJECT, 2017
** my_str_to_word_array
** File description:
** generic
*/

#include "my.h"

int my_char_isalpha(char const c)
{
	if (!((c > 96 && c < 123) || (c > 64 && c < 91) || (c > 47 && c < 58)))
			return (0);
	return (1);
}

int count_word(char const *str)
{
	int i = 0;
	int nbr_word = 0;
	int b = 0;

	while (!(my_char_isalpha(str[i])) && str[i] != '\0')
		i++;
	while (str[i] != '\0') {
		if (b == 0) {
			b ++;
			nbr_word ++;
		}
		if (!my_char_isalpha(str[i]) && my_char_isalpha(str[i - 1]))
			nbr_word ++;
		i++;
	}
	return (nbr_word);
}
