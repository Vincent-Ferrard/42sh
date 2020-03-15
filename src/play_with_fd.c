/*
** EPITECH PROJECT, 2017
** play_with_fd.c
** File description:
** do a lot of thing with fd, pipe and some amusing thing
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "lib_func.h"
#include "lib_my.h"
#include "struct.h"

char *double_input(func_t *obj)
{
	char *temp = get_next_line(0);
	char *temp2 = NULL;
	char *result = NULL;

	while (!my_strcmp(obj->next->function[0], temp) && temp != NULL) {
		if (result == NULL)
			result = temp;
		else {
			temp2 = result;
			result = my_strconcat(temp2, "\n");
			free(temp2);
			temp2 = result;
			result = my_strconcat(temp2, temp);
			free(temp2);
			free(temp);
		}
		temp = get_next_line(0);
	}
	if (my_strcmp(obj->next->function[0], temp))
		free(temp);
	return (result);
}

int do_something_with_fd_3(func_t *obj, int pipe[2])
{
	if (obj->next_flags == 5) {
		if (dup2(pipe[1], 1) == -1)
			return (1);
	}
	if (obj->previous_flags == 5) {
		if (dup2(pipe[0], 0) == -1)
			return (1);
	}
	return (0);
}

int do_something_with_fd_2(func_t *obj, int pipe[2])
{
	int fd = 0;
	char *temp = NULL;

	if (obj->next_flags == 3) {
		temp = double_input(obj);
		write(pipe[1], temp, my_strlen(temp));
		free(temp);
		if (dup2(pipe[0], 0) == -1)
			return (1);
	} else if (obj->next_flags == 4) {
		fd = open(obj->next->function[0], O_RDONLY);
		if (fd == -1)
			return (1);
		if (dup2(fd, 0) == -1)
			return (1);
	} else
		return (do_something_with_fd_3(obj, pipe));
	return (0);
}

int do_something_with_fd(func_t *obj, int pipe[2])
{
	int fd = 0;
	int flag = O_CREAT | O_WRONLY;

	if (obj->next_flags == 1) {
		fd = open(obj->next->function[0], flag | O_APPEND, 0654);
		if (fd == -1)
			return (1);
		if (dup2(fd, 1) == -1)
			return (1);
	} else if (obj->next_flags == 2) {
		fd = open(obj->next->function[0], flag | O_TRUNC, 0654);
		if (fd == -1)
			return (1);
		if (dup2(fd, 1) == -1)
			return (1);
	} else
		return (do_something_with_fd_2(obj, pipe));
	return (0);
}
