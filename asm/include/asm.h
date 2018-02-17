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
	LABEL_CALL,
	LABEL_DECLARATION
} arg_type;

typedef struct label_call_s {
	size_t abs_pos;
	size_t rel_pos;
	int nb_bytes;
	arg_type type;
	char *name;
	struct label_call_s *next;
} call_t;

typedef struct label_declaration_s {
	size_t pos;
	char *name;
	struct label_declaration_s *next;
} decla_t;

typedef struct label_list_s {
	decla_t *decla;
	call_t *call;
	size_t current_pos;
	size_t tmp_pos;
} label_t;

/*ERROR_HANDLING*/
int verif(char *);
void verif_nb_arg(int, char **);
void verif_arg_type(int, char **);
void verif_gram(char **);
void check_label_gram(char *);
void check_gram(char *);
void verif_header(int);

/*WRITE_FILE*/
int write_instruction(char *cmd, int fd, label_t *);
void write_coding_byte(char **, int, label_t *);
void arg_encoder(char **, int, int, label_t *);
void write_indirect_arg(char *, int, label_t *);
void write_direct_arg(char *, int, int, label_t *);

/*TOOLS*/
int get_mnemonique(char *);
void clear_comment(char *);
void print_tabtab(char **);
char **str_to_av(char *);
char *file_to_cor(char *);
arg_type get_arg_type(char *);
void *my_super_memset(void *, int, size_t);
void printf_linked_list(call_t *, decla_t *);
int check_mnemonique_case(int);
char *int_to_str(long int, char *);
void magic_reverse(void *);
void short_magic_reverse(void *);
char **shift_tab(char **);

/*LABELS*/
label_t *init_label(void);
void reinit_pos(label_t *);
void fill_label_call(char *, int, int, label_t *);
char **fill_label_decla(char **, label_t *);
void rewrite_label(int, label_t *);

/*HEADER*/
void init_header(header_t *);
int fill_header(char **, header_t *);
void rewrite_header(int, header_t *);

/*MAIN*/
int check_main(int, char **);
void loop(label_t *, header_t *, int, int);

#endif
