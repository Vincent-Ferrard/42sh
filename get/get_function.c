/*
** EPITECH PROJECT, 2017
** get_function.c
** File description:
** get the function from the shell
*/

#include <stdlib.h>
#include <stdio.h>
#include "lib_func.h"
#include "lib_my.h"

WEAK char *get_prompt(void)
{
	my_putstr(PS1);
	return (get_next_line(0));
}

char **get_function(void)
{
	char *function = NULL;
	char **result = NULL;

	function = get_prompt();
	if (function == NULL) {
		my_putchar('\n');
		return (NULL);
	} else if (my_strcmp(function, " ") || my_strlen(function) == 0) {
		free(function);
		return (get_function());
	}
	for (int i = 0; function[i] != 0; i = i + 1) {
		if (function[i] == '\t')
			function[i] = ' ';
	}
	result = split(function, ';');
	free(function);
	return (result);
}
