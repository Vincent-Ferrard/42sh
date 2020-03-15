/*
** EPITECH PROJECT, 2017
** subcommand.c
** File description:
** all the subcommand
*/

#include <stdlib.h>
#include <dirent.h>
#include "lib_my.h"
#include "path.h"

int my_env(char **envp)
{
	for (int i = 0; envp[i] != NULL; i = i + 1) {
		my_putstr(envp[i]);
		my_putchar('\n');
	}
	return (0);
}

void delete_one_case_double(char ***envp, int indice)
{
	char **result = NULL;
	int c = 0;

	if (*envp[0] == NULL || indice == -1)
		return;
	result = my_malloc(sizeof(char *) * my_tablen(*envp));
	for (int i = 0; (*envp)[i] != NULL; i = i + 1) {
		if (i != indice) {
			result[c] = (*envp)[i];
			c = c + 1;
		}
	}
	free((*envp)[indice]);
	free(*envp);
	*envp = result;
}

int my_unsetenv(char **command, char ***envp)
{
	int indice = 0;

	if (command[1] == NULL) {
		my_putestr("unsetenv: Too few arguments.\n");
		return (1);
	}
	for (int i = 1; command[i] != NULL; i = i + 1) {
		if ((indice = get_var_in_env(command[i], *envp)) != -1)
			delete_one_case_double(envp, indice);
	}
	return (0);
}
