/*
** EPITECH PROJECT, 2017
** process.c
** File description:
** process the func_t structure for executing command
*/

#include <stdlib.h>
#include "alias.h"
#include "execution.h"
#include "lib_func.h"
#include "lib_my.h"
#include "struct.h"

int process_2(char *command, char ***envp, char **list_function, char ***alias)
{
	func_t *function = NULL;
	int result = 0;

	function = create_function(command, 0, *alias);
	result = exec(function, envp, list_function);
	free_double(*alias);
	*alias = my_strcpy_array(function->alias);
	destroy_function(function);
	return (result);
}

int process(char **function, char ***envp, char **list_function, char ***alias)
{
	int result = 0;

	if (function == NULL)
		return (1);
	for (int i = 0; function[i] != NULL && result == 0; i = i + 1)
		result = process_2(function[i], envp, list_function, alias);
	return (result);
}
