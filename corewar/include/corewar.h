/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** header file for corewar
*/

#include "display_f.h"
#include "get_next_line.h"
#include "my.h"

typedef struct player_s {
	int fd;
	int pc;
	int carry;
	cmd_t *cmds;
	int cycle;
	int forked;
} player_t;

typedef struct env_s {
	char *memory;
	player_t *players;
} env_t;
