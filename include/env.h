/*
** EPITECH PROJECT, 2017
** env.h
** File description:
** function relative to the virtual environement
*/

#pragma once

#include <unistd.h>

#define CLOSEFD(fd) if ((fd != -1)) close(fd)

void my_setenv_2(char const *command, char **envp);
int my_unsetenv(char **command, char ***envp);
int my_setenv(char **command, char ***envp);
int my_cd_last(char ***envp, int indice);
int my_cd(char **command, char ***envp);
char **cpy_env(char * const *envp);
void set_oldwpd(char ***envp);
int my_env(char **envp);
