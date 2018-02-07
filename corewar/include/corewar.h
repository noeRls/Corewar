/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** header file for corewar
*/

#include "display_f.h"
#include "get_next_line.h"
#include "my.h"
#include "op.h"

typedef struct program_s {
	int id;
	int fd;
	int prog_nb;
	int carry;
	int fork;
	int live_signal;
	int cycle;
	int mem_start; //index of it allowed space
	//currently it's r0
	struct program_s *next;
} program_t;

typedef struct env_s {
	char memory[MEM_SIZE];
	program_t *prgm;

	int nbr_player;
	int cycle;
	int live_counter;
	int cycle_to_die;
} env_t;
