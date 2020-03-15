/*
** EPITECH PROJECT, 2017
** execution.c
** File description:
** exec the imput command
*/

#include <sys/wait.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include <fcntl.h>
#include "alias.h"
#include "execution.h"
#include "lib_func.h"
#include "struct.h"
#include "lib_my.h"
#include "error.h"
#include "share.h"
#include "path.h"
#include "env.h"

void exec_child(func_t *obj, int pipe[2], char **list_function, char **envp)
{
	int indice = find_in_list(obj->function[0], list_function);
	int fd = 0;

	if (indice == -1) {
		if ((fd = open(obj->function[0], O_DIRECTORY)) != -1) {
			my_putestr(obj->function[0]);
			my_putestr(": Permission denied.\n");
			close(fd);
			exit(1);
		}
	}
	if (do_something_with_fd(obj, pipe))
		perror_exit();
	close(pipe[0]);
	close(pipe[1]);
	exec_alias(obj->alias, obj->function, list_function, envp);
	if (indice != -1)
		execve(list_function[indice], obj->function, envp);
	else
		execve(obj->function[0], obj->function, envp);
	print_error_command(obj->function[0]);
	exit(1);
}

int execution(func_t **obj, char **envp, char **list_function, int pipe[2])
{
	int waitstatus = 0;

	check_for_child(obj, envp, list_function, pipe);
	if (pid_child > 0) {
		do {
			waitpid(pid_child, &waitstatus, WUNTRACED | WCONTINUED);
		} while (!WIFEXITED(waitstatus) && !WIFSIGNALED(waitstatus));
		if (waitstatus == SIGSEGV)
			my_putestr("Segmentation fault");
		else if (waitstatus == 8)
			my_putestr("Floating exception");
		if (WCOREDUMP(waitstatus))
			my_putestr(" (core dumped)\n");
	} else {
		perror("Error");
		return (-1);
	}
	pid_child = 0;
	return (waitstatus);
}

int exec_sub(char **command, char ***envp, char ***alias)
{
	int status = 0;

	if (my_strcmp(command[0], "exit"))
		return (-1);
	if (my_strcmp(command[0], "env"))
		status = my_env(*envp);
	if (my_strcmp(command[0], "setenv"))
		status = my_setenv(command, envp);
	if (my_strcmp(command[0], "unsetenv"))
		status = my_unsetenv(command, envp);
	if (my_strcmp(command[0], "cd"))
		status = my_cd(command, envp);
	if (my_strcmp(command[0], "alias"))
		*alias = alias_command(command, *alias);
	return (status);
}

int exec(func_t *obj, char ***envp, char **list)
{
	int result = 0;
	int status = 0;
	int test_status_yep = 0;
	int test_status_nope = 0;
	int no_test = 0;
	int fd[2];

	if (pipe(fd) == -1)
		return (84);
	while (obj != NULL && result == 0) {
		test_status_yep = obj->previous_flags == 7 && status == 0;
		test_status_nope = obj->previous_flags == 6 && status != 0;
		no_test = obj->previous_flags != 6 && obj->previous_flags != 7;
		if (test_status_nope || test_status_yep || no_test)
			status = check_for_execution(&obj, envp, list, fd);
		result = status == -1 ? 84 : result;
	}
	close(fd[0]);
	close(fd[1]);
	return (result);
}
