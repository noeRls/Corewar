/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** header file for corewar
*/

#include "display_f.h"
#include "get_next_line.h"
#include "my.h"

typedef struct program_s {
	int id;
	int fd;
	int prog_nb;
	int pc;
	int carry;
	int fork;
	int last_live_signal;
	int reg[REG_NUMBER];
	struct program_s *next;
} program_t;

typedef struct env_s {
	char memory[MEM_SIZE];
	int cycle;
	int cycle_to_die;
	program_t *prgm;
} env_t;
