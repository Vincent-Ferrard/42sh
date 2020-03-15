/*
** EPITECH PROJECT, 2017
** setenv.c
** File description:
** setenv
*/

#include <stdlib.h>
#include <dirent.h>
#include "lib_func.h"
#include "lib_my.h"
#include "path.h"
#include "env.h"

void my_setenv_2(char const *command, char **envp)
{
	int len = my_strlen(*envp);

	for (int i = 0; command[i] != 0; i = i + 1) {
		*envp = my_realoc(*envp);
		(*envp)[len] = command[i];
		len = len + 1;
	}
}

int my_setenv(char **command, char ***envp)
{
	int indice = -1;

	if (command[1] == NULL) {
		my_env(*envp);
		return (0);
	} else if (!is_alpha_str(command[1])) {
		my_putestr("setenv: Variable name must contain alphanumeric c");
		my_putestr("haracters.\n");
		return (1);
	}
	if ((indice = get_var_in_env(command[1], *envp)) == -1) {
		*envp = my_realoc_double(*envp);
		indice = my_tablen(*envp);
	} else
		free((*envp)[indice]);
	(*envp)[indice] = my_strconcat(command[1], "=");
	if (command[2] == NULL)
		return (0);
	my_setenv_2(command[2], &((*envp)[indice]));
	return (0);
}
