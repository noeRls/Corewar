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

int write_instruction(char *cmd, int fd);
void print_tabtab(char **);
char **str_to_av(char *);
char *file_to_core(char *);
void verif_syntax(int, char **);
void write_coding_byte(char **, int);
arg_type get_arg_type(char *);
void arg_encoder(char **, int);

#endif
