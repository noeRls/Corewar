/*
** EPITECH PROJECT, 2017
** write functions
** File description:
** functions to display
*/

void write(int, char const *, int);

void my_putchar(char c)
{
	write(1, &c, 1);
}

void my_putstr(char const *str)
{
	for (int i = 0; str[i]; i++) {
		my_putchar(str[i]);
	}
}

void my_putstr_err(char const *str)
{
	for (int i = 0; str[i]; i++) {
		write(2, &str[i], 1);
	}
}
