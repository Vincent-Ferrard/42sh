/*
** EPITECH PROJECT, 2017
** next_obj.c
** File description:
** get the next obj
*/

#include <stdlib.h>
#include "struct.h"
#include "lib_my.h"
#include "execution.h"
#include "share.h"

int is_subprocess(char const *str)
{
	static char *subprocess[] = {
		"cd",
		"env",
		"exit",
		"alias",
		"setenv",
		"unsetenv",
		NULL
	};

	for (int i = 0; subprocess[i] != NULL; i = i + 1) {
		if (my_strcmp(str, subprocess[i]))
			return (1);
	}
	return (0);
}

int check_for_execution(func_t **obj, char ***envp, char **list, int fd[2])
{
	int status = 0;

	if ((**obj).function == NULL)
		return (0);
	if (is_subprocess((**obj).function[0]))
		status = exec_sub((**obj).function, envp, &(*obj)->alias);
	else
		status = execution(obj, *envp, list, fd);
	return (status);
}

void check_for_child(func_t **obj, char **envp, char **list, int pipe[2])
{
	int first = 0;
	pid_t temp = 0;
	int waitstatus = 0;

	do {
		first = first + 1;
		if (first == 1) {
			pid_child = fork();
		} else
			temp = fork();
		if ((pid_child == 0 && first == 1) || (temp == 0 && first > 1))
			exec_child(*obj, pipe, list, envp);
		get_next_obj(obj);
	} while ((*obj) != NULL && (**obj).previous_flags == 5);
}

void get_next_obj(func_t **obj)
{
	int range = 0;

	range = ((**obj).next_flags >= 5 && (**obj).next_flags <= 7);
	if ((**obj).next_flags == 0 || range)
		(*obj) = (**obj).next;
	else
		(*obj) = (**obj).next->next;
}
