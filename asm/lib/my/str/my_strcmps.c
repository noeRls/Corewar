/*
** EPITECH PROJECT, 2017
** my_strcmps
** File description:
** str compare functions
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
	int lena = my_strlen(s1);
	int lenb = my_strlen(s2);
	int index = 0;
	int minindex;

	if (lena <= lenb) {
		minindex = lena;
	} else {
		minindex = lenb;
	}
	while (index < minindex) {
		if (s1[index] == s2[index]) {
			index = index + 1;
		} else {
			return (s1[index] - s2[index]);
		}
	}
	return (lena - lenb);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
	int index = 0;

	while (s1[index] == s2[index] && index < n && s1[index] && s2[index]) {
		index++;
		if (index == n) {
			if (s1[index] == s2[index])
				return (0);
		}
	}
	if (s1[index] != s2[index] && index != n)
		return (s1[index] - s2[index]);
	else
		return (0);
}

int my_supercmp(char const *s1, char const *s2)
{
	if (my_strlen(s1) != my_strlen(s2)) {
		return (my_strlen(s1) - my_strlen(s2));
	}
	return (my_strcmp(s1, s2));
}
