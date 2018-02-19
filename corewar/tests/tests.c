/*
** EPITECH PROJECT, 2018
** tests
** File description:
** tests
*/

typedef struct d_int {
	int a;
	int b;
} d_int_t;

Test(read_from_mem, 1)
{
	char memory[1000] = {0};
	int fd = open("test", O_RDWR | O_CREAT, 0666);
	int a = 12;
	int b = 26;
	d_int_t *data = my_malloc(sizeof(d_int_t));

	memory[0] = 1;
	memory[4] = 2;
	read_from_mem(memory, data, sizeof(d_int_t));
	cr_assert_eq(data->a, 1);
	cr_assert_eq(data->b, 2);
}
