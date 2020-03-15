/*
** EPITECH PROJECT, 2017
** execution.h
** File description:
** the function for the execution
*/

#pragma once

#include "struct.h"

void exec_child(func_t *obj, int pipe[2], char **list_function, char **envp);
int check_for_execution(func_t **obj, char ***envp, char **list, int fd[2]);
int execution(func_t **obj, char **envp, char **list_function, int pipe[2]);
int process_2(char *command, char ***envp, char **list_function, char ***alias);
int process(char **function, char ***envp, char **list_function, char ***alias);
int exec(func_t *obj, char ***envp, char **list_function);
int exec_sub(char **command, char ***envp, char ***alias);
int do_something_with_fd_2(func_t *obj, int pipe[2]);
int do_something_with_fd(func_t *obj, int pipe[2]);
int get_first_flags(char const *command);
int is_subprocess(char const *str);
char *double_input(func_t *obj);
void get_next_obj(func_t **obj);
