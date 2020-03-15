/*
** EPITECH PROJECT, 2017
** get_var_in_env.c
** File description:
** get a variable indice in the environement.
*/

#include <stdlib.h>
#include "lib_func.h"
#include "lib_my.h"

int get_var_in_env(char const *var_name, char * const *envp)
{
	int indice = -1;
	char *temp = NULL;

	temp = my_strconcat(var_name, "=");
	for (int i = 0; envp[i] != NULL; i = i + 1) {
		if (startswith(envp[i], temp))
			indice = i;
	}
	free(temp);
	return (indice);
}
