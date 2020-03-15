/*
** EPITECH PROJECT, 2017
** find_in_list.c
** File description:
** fint the indice of a function in a array
*/

#include <stdlib.h>
#include "lib_func.h"
#include "lib_my.h"

int find_in_list(char *command, char **list_function)
{
	char *temp = NULL;

	temp = my_strconcat("/", command);
	for (int i = 0; list_function[i] != NULL; i = i + 1) {
		if (endswith(list_function[i], temp)) {
			free(temp);
			return (i);
		}
	}
	free(temp);
	return (-1);
}
