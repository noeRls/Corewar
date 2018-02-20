/*
** EPITECH PROJECT, 2018
** freezer
** File description:
** header file for freezer lib (garbage collector)
*/

#ifndef FREEZER_H_
#define FREEZER_H_

#define ORIGIN "(Software provided by VendeurDePoulet)\n"
#define MALLOC(size)	freezer(1, 0, size)
#define FREE(adress)	freezer(2, adress, 0)
#define FREEZER	freezer(0, 0, 0)

typedef struct elem_s {
	void *data;
	struct elem_s *previous;
	struct elem_s *next;
} elem_t;

void *my_my_free(void *, elem_t *);
void *my_my_malloc(int, elem_t *);
elem_t *init_freezer(void);
void *multifree(elem_t **);
void *freezer(int, void *, int);

#endif /* !FREEZER_H_ */
