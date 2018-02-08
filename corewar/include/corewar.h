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
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define PC reg[0]

typedef struct instr_s {
	char code;
	char desc;
} instr_t;

typedef enum type_s {
	NONE = 0,
	DIR = 2,
	IND = 3,
	REG = 1
} type_arg_t;

typedef struct program_s {
	int *reg;
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

/*	src/main.c	*/

program_t *start_prog(char *path);
static void magic_reverse(void *x);
void ini_prog_memory(env_t *env);
void init(int ac, char **av, env_t *env);
int main(int ac, char **av);

/*	src/read_from_mem.c	*/

void read_from_mem(char *memory, void *data, int size);

/*	src/run.c	*/

int nbr_prog_alive(env_t *env);
void manage_cycle(env_t *env);
int execute_prog(env_t *env, program_t *p);
int run(env_t *env);

/*	src/opcodes	*/

type_arg_t get_arg_type(char desc, int arg_nbr);
int setup_arg(int *arg, program_t *p, char desc);
void set_cycle(program_t *p, char code);
int get_arg_value(program_t *p, type_arg_t type);
int up_pc(program_t *p, int size);
type_arg_t get_arg_type(char desc, int arg_nbr);

void add(env_t *env, program_t *p, instr_t info);
void aff(env_t *env, program_t *p, instr_t info);
void and(env_t *env, program_t *p, instr_t info);
void fork_op(env_t *env, program_t *p, instr_t info);
void ld(env_t *env, program_t *p, instr_t info);
void ldi(env_t *env, program_t *p, instr_t info);
void lfork(env_t *env, program_t *p, instr_t info);
void live(env_t *env, program_t *p, instr_t info);
void lld(env_t *env, program_t *p, instr_t info);
void lldi(env_t *env, program_t *p, instr_t info);
void or(env_t *env, program_t *p, instr_t info);
void st(env_t *env, program_t *p, instr_t info);
void sti(env_t *env, program_t *p, instr_t info);
void sub(env_t *env, program_t *p, instr_t info);
void xor(env_t *env, program_t *p, instr_t info);
void zjmp(env_t *env, program_t *p, instr_t info);
