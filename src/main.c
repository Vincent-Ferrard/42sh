/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** the main of the file
*/

#include <stdlib.h>
#include <signal.h>
#include <dirent.h>
#include "alias.h"
#include "execution.h"
#include "lib_func.h"
#include "lib_my.h"
#include "struct.h"
#include "path.h"
#include "main.h"

void free_double(char **function)
{
	if (function == NULL)
		return;
	for (int i = 0; function[i] != NULL; i = i + 1) {
		free(function[i]);
	}
	free(function);
}

void sign_handler(int sign)
{
	if (sign == SIGINT) {
		if (pid_child != 0)
			kill(pid_child, SIGINT);
		else {
			my_putchar('\n');
			my_putstr(PS1);
		}
	}
}

char **cpy_env(char * const *envp)
{
	char **result = NULL;

	result = my_malloc(sizeof(char *) * (my_tablen(envp) + 1));
	for (int i = 0; envp[i] != NULL; i = i + 1)
		result[i] = my_strdup(envp[i]);
	return (result);
}

WEAK int main(UNUSED int argc, UNUSED char **argv, char **envp)
{
	char **function = NULL;
	char **list_function = NULL;
	char **env = cpy_env(envp);
	int test_boucle = 0;
	char **alias = NULL;

	signal(SIGINT, sign_handler);
	list_function = get_function_list(&env);
	alias = set_basic_alias();
	while (!test_boucle) {
		function = get_function();
		test_boucle = process(function, &env, list_function, &alias);
		free_double(function);
	}
	free_double(alias);
	free_double(env);
	free_double(list_function);
	return (0);
}
