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
#include <stdio.h>

#define PC reg[0]
#define READ_SIZE_BINARY_OP 1

#define TRUE 1
#define FALSE 0

typedef struct instr_s {
	char code;
	char desc;
} instr_t;

typedef enum type_s {
	NONE = 0,
	DIR = 2,
	IND = 4,
	REG = 1
} type_arg_t;

typedef struct program_s {
	int pc_backup;
	instr_t *info;
	int id;
	int reg[REG_NUMBER + 1];
	int fd;
	int carry;
	int live_signal;
	int cycle;
	int mem_start; //index of it allowed space
	char name[PROG_NAME_LENGTH + 1];
	struct program_s *next;
} program_t;

typedef struct args_s {
	int curr;
	char **prog_paths;
	int dump_cycle;
	int nb_prog;
	int *prog_ids;
	int *mem_start;
	int not_mem_default;
} args_t;

typedef struct env_s {
	unsigned char memory[MEM_SIZE];
	program_t *prgm;

	int dump_cycle;
	int nbr_player;
	int cycle;
	int live_counter;
	int cycle_to_die;
	int end;
	int last_id;
	char last_name[PROG_NAME_LENGTH + 1];
} env_t;

/*	src/main.c	*/

void add_prog(program_t **start, program_t *to_add);
program_t *prog_dup(program_t *prog);
program_t *start_prog(char *path);
void ini_prog_memory(env_t *env);
void init(args_t *arg, env_t *env);
int main(int ac, char **av);

/*	src/read_from_mem.c	*/

void read_from_mem(unsigned char *memory, void *data, int size, int start);
void write_to_mem(unsigned char *memory, void *data, int size, int start);
void print_hexa_mem(unsigned char *mem);
void swap(void *data, int size);

/*	src/run.c	*/

int nbr_prog_alive(env_t *env);
void manage_cycle(env_t *env);
int run(env_t *env);

/*	src/opcodes	*/

int do_idx_mod(int value, program_t *p);
type_arg_t get_arg_type(char desc, int arg_nbr);
int setup_arg(int *arg, program_t *p, env_t *env, int idx_mod_ind);
void set_cycle(program_t *p, char code);
int get_arg_data(env_t *env, program_t *p, type_arg_t type);
int up_pc(program_t *p, int size);
void set_pc(program_t *p, int value);

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
