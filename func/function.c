/*
** EPITECH PROJECT, 2017
** function.c
** File description:
** contain all rh function for my func_t structure
*/

#include <stdlib.h>
#include "alias.h"
#include "lib_func.h"
#include "lib_my.h"
#include "struct.h"

int get_first_flags(char const *command)
{
	for (int i = 0; command[i] != 0; i = i + 1) {
		if (command[i] == '>' && command[i + 1] == '>')
			return (1);
		else if (command[i] == '>')
			return (2);
		if (command[i] == '<' && command[i + 1] == '<')
			return (3);
		else if (command[i] == '<')
			return (4);
		if (command[i] == '|' && command[i + 1] == '|')
			return (6);
		else if (command[i] == '|')
			return (5);
		if (command[i] == '&' && command[i + 1] == '&')
			return (7);
	}
	return (0);
}

char **get_next_flags(int flags, char const *command)
{
	char **temp = NULL;

	if (flags == 1 || flags == 2)
		temp = split_one(command, '>');
	if (flags == 3 || flags == 4)
		temp = split_one(command, '<');
	if (flags == 5 || flags == 6)
		temp = split_one(command, '|');
	if (flags == 7)
		temp = split_one(command, '&');
	return (temp);
}

func_t *create_function(char const *command, int previous_flags, char **alias)
{
	func_t *result = NULL;
	char **temp = NULL;

	result = my_malloc(sizeof(func_t));
	result->previous_flags = previous_flags;
	result->next_flags = get_first_flags(command);
	temp = get_next_flags(result->next_flags, command);
	result->alias = my_strcpy_array(alias);
	if (result->next_flags != 0) {
		format_str(temp[0]);
		format_str(temp[1]);
		result->function = split(temp[0], ' ');
		result->next = create_function(temp[1], result->next_flags, alias);
		free_double(temp);
	} else
		result->function = split(command, ' ');
	return (result);
}

void destroy_function(func_t *object)
{
	if (object == NULL)
		return;
	if (object->next != NULL)
		destroy_function(object->next);
	free_double(object->alias);
	free_double(object->function);
	free(object);
}
