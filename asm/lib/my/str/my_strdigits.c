/*
** EPITECH PROJECT, 2017
** my_str_digits
** File description:
** count digits in chars
*/

int my_strdigits(long long nb)
{
	int digits = 0;

	if (nb < 0) {
		digits++;
		nb *= -1;
	}
	while (nb) {
		nb /= 10;
		digits++;
	}
	return (digits);
}
