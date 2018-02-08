/*
** EPITECH PROJECT, 2018
** asm
** File description:
** header file for asm
*/

#ifndef ASM_H
#define ASM_H

#include "display_f.h"
#include "get_next_line.h"
#include "my.h"
#include "op.h"

typedef enum {
	REGISTER,
	DIRECT,
	INDIRECT,
	LABEL
} arg_type;

typedef struct label_call_s {
	int abs_pos;
	int rel_pos;
	int nb_bytes;
	char *label;
	struct label_call_s *next;
} label_call_t;

typedef struct label_declaration_s {
	int pos;
	char *label;
	struct label_declaration_s *next;
} label_declaration_t;

int write_instruction(char *cmd, int fd);
void print_tabtab(char **);
char **str_to_av(char *);
char *file_to_cor(char *);
void verif_syntax(int, char **);
void write_coding_byte(char **, int);
arg_type get_arg_type(char *);
void arg_encoder(char **, int, int);
int fill_header(char **, header_t *);
void rewrite(int, header_t *);
void *my_super_memset(void *, int, size_t);
void write_indirect_arg(char *, int);

#endif
