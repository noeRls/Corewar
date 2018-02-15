/*
** EPITECH PROJECT, 2018
** programs tools
** File description:
** prog tools
*/

#include "corewar.h"

void add_prog(program_t **start, program_t *to_add)
{
	program_t *last = 0;

	if (!(*start))
		*start = to_add;
	for (last = (*start); last->next; last = last->next);
	last->next = to_add;
	to_add->next = 0;
}

program_t *prog_dup(program_t *prog)
{
	program_t *prgm = my_malloc(sizeof(program_t));

	for (int i = 0; i < REG_NUMBER + 1; i++) {
		prgm->reg[i] = prog->reg[i];
	}
	prgm->PC = prog->PC;
	prgm->pc_backup = prog->pc_backup;
	prgm->info = prog->info;
	prgm->id = prog->id;
	prgm->fd = prog->fd;
	prgm->live_signal = prog->live_signal;
	prgm->cycle = prog->cycle;
	prgm->carry = 0;
	prgm->mem_start = prog->mem_start;
	my_memset(prgm->name, 0, PROG_NAME_LENGTH + 1);
	my_strcpy(prgm->name, prog->name);
	prgm->next = 0;
	return (prgm);
}

program_t *start_prog(char *path)
{
	int fd = open(path, O_RDONLY);
	program_t *prgm = my_malloc(sizeof(program_t));

	if (!fd)
		exit(84);
	my_memset(prgm->reg, 0, sizeof(int) * (REG_NUMBER + 1));
	prgm->cycle = 0;
	prgm->fd = fd;
	prgm->carry = 0;
	prgm->live_signal = 0;
	prgm->cycle = 0;
	prgm->PC = 0;
	prgm->pc_backup = 0;
	return (prgm);
}
