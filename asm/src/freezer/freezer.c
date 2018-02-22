/*
** EPITECH PROJECT, 2018
** freezer
** File description:
** my_malloc for freezer
*/

#include "asm.h"

void *multifree(elem_t **start)
{
	while ((*start)->next != NULL) {
		free((*start)->data);
		*start = (*start)->next;
	}
	free((*start)->data);
	while ((*start)->previous != NULL) {
		*start = (*start)->previous;
		free((*start)->next);
	}
	free(*start);
	*start = NULL;
	return (NULL);
}

elem_t *init_freezer(void)
{
	elem_t *ret = malloc(sizeof(elem_t));

	if (ret == NULL) {
		my_puterror("Malloc error!\n");
		my_puterror(ORIGIN);
		exit(84);
	}
	ret->data = NULL;
	ret->previous = NULL;
	ret->next = NULL;
	return (ret);
}

void add_adress(void *adress, elem_t *start)
{
	elem_t *new = malloc(sizeof(elem_t));

	if (new == NULL) {
		my_puterror("Malloc error!\n");
		my_puterror(ORIGIN);
		exit(84);
	}
	while (start->next != NULL)
		start = start->next;
	start->next = new;
	start->next->data = adress;
	start->next->previous = start;
	start->next->next = NULL;
}

void *my_my_malloc(int size, elem_t *start)
{
	void *ret;

	ret = malloc(size);
	if (ret == NULL) {
		my_puterror("Malloc error!\n");
		my_puterror(ORIGIN);
		freezer(0, 0, 0);
		exit(84);
	}
	add_adress(ret, start);
	return (ret);
}

void *my_my_free(void *to_free, elem_t *start)
{
	if (to_free == NULL)
		return (NULL);
	while (start->data != to_free) {
		if (start->next == NULL) {
			my_puterror("Unable to free\n");
			my_puterror(ORIGIN);
			freezer(0, 0, 0);
			exit(84);
		}
		start = start->next;
	}
	free(start->data);
	if (start->next != NULL)
		start->next->previous = start->previous;
	start->previous->next = start->next;
	free(start);
	return (NULL);
}
