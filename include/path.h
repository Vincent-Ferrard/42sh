/*
** EPITECH PROJECT, 2017
** path.h
** File description:
** gestion of the path
*/

#pragma once

#include "struct.h"

char **get_in_dir(char **src, DIR *dir, char *path, int *count);
int get_var_in_env(char const *var_name, char * const *envp);
int find_in_list(char *command, char **list_function);
char **get_function_in_path(char **path);
char **get_function_list(char ***envp);
int exeucatble(char *filepath);
char **get_path(char *path);
char **get_function(void);
