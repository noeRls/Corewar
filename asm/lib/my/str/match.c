/*
** EPITECH PROJECT, 2017
** match rec
** File description:
** match
*/

int match(char const *s1, char const *s2)
{
	int suc = 0;

	if ((*s2 == '\0' && *s1 == '\0') || (*s2 == '*' && s2[1] == '\0'))
		return (1);
	else if ((!*s1 && *s2 && s2[1] != '*') || (*s1 && !*s2) ||
		(*s1 != *s2 && *s2 != '*'))
		return (0);
	if (*s1 == *s2)
		return (match(s1 + 1, s2 + 1));
	else if ((*s2 == '*' && s2[1] == '*') || match(s1, s2 + 1))
		return (match(s1, s2 + 1));
	if (*s1 != *s2 && *s2 == '*')
		return (match(s1 + 1, s2));
	return (0);
}
