/*
** EPITECH PROJECT, 2018
** CPE_corewar_2017
** File description:
** main
*/

void print_help()
{
}

int main(int ac, char **av)
{
	if (ac == 1 && !my_strcmp()) {
		print_help();
		return (0);
	}
	if (ac != 2)
		return (84);
	return (0);
}
