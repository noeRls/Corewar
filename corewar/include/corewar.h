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
#include <sys/types.h>
#include <unistd.h>

#define PC reg[0]

typedef struct instr_s {
	char code;
	char desc;
} instr_t;

typedef struct program_s {
	char *reg;
	int id;
	int fd;
	int prog_nb;
	int carry;
	int fork;
	int live_signal;
	int cycle;
	int mem_start; //index of it allowed space
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
