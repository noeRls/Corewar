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

int write_instruction(char *cmd, int fd);
void print_tabtab(char **);
char **str_to_av(char *);

#endif
