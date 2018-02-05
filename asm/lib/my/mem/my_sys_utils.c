/*
** EPITECH PROJECT, 2017
** basic utils
** File description:
** basic tools
*/

void my_memset(void *str, int c, int len)
{
	char *s = (char *) str;

	for (int i = 0; i < len; i++) {
		s[i] = c;
	}
}

void my_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

void my_swap_char(char *a, char *b)
{
	char temp = *a;

	*a = *b;
	*b = temp;
}
