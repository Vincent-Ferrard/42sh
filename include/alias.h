/*
** EPITECH PROJECT, 2018
** alias.h
** File description:
** alias header
*/

#ifndef ALIAS_H_
#define ALIAS_H_

#include <stdio.h>
#include <stdlib.h>
#include "lib_my.h"
#include "main.h"

char **exec_alias2(char **, char *);
void exec_alias(char **, char **, char **, char **);
void display_alias(char **);

void set_new_value_alias(char **, char **, int);
char **set_alias_command(char **, char **, int);
char **alias_command(char **, char **);
char *read_only(int);
char **set_basic_alias(void);

int check_switch(char *, char *);
int order_tab2(char **, int, int);
char **order_tab(char **);
char *my_real_strcpy(char *);
char **my_strcpy_array(char **);

#endif
