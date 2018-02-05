/*
** EPITECH PROJECT, 2017
** get_color
** File description:
** returns the color as an int by handling its three RGB components
*/

#include "my.h"

int get_color(unsigned char red, unsigned char green, unsigned char blue)
{
	int rgb = 0;

	rgb |= red;
	rgb <<= 8;
	rgb |= green;
	rgb <<= 8;
	rgb |= blue;
	return (rgb);
}
