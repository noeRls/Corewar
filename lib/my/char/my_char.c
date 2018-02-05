/*
** EPITECH PROJECT, 2017
** my_char
** File description:
** char analyses
*/

int my_strlen(char const *);

int my_char_isalpha(char c)
{
	if ((c > 47 && c < 58) || (c > 64 && c < 91) || (c > 96 && c < 123)) {
		return (1);
	} else {
		return (0);
	}
}

int isonlychar(char *str, char c)
{
	for (int i = 0; i < my_strlen(str); i++) {
		if (str[i] != c)
			return (0);
	}
	return (1);
}

int my_char_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char upchar(char c)
{
	if (c >= 'a' && c <= 'z') {
		return (c - 32);
	} else {
		return (c);
	}
}

char lowchar(char c)
{
	if (c >= 'A' && c <= 'Z') {
		return (c + 32);
	} else {
		return (c);
	}
}
