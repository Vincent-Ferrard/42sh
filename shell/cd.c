/*
** EPITECH PROJECT, 2017
** cd.c
** File description:
** cd
*/

#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include "lib_func.h"
#include "lib_my.h"
#include "path.h"
#include "env.h"

void print_error_cd(char const *command)
{
	int fd = 0;

	my_putestr(command);
	if ((fd = open(command, O_RDONLY)) == -1)
		my_putestr(": No such file or directory.\n");
	else {
		my_putestr(": Not a directory.\n");
		close(fd);
	}
}

void set_oldwpd(char ***envp)
{
	char *temp = getcwd(NULL, 0);
	char *setenv_temp[] = {
		"setenv",
		"OLDPWD",
		temp,
		NULL
	};

	my_setenv(setenv_temp, envp);
	free(temp);
}

int my_cd_last(char ***envp, int indice)
{
	char *temp = getcwd(NULL, 0);
	char **splited = NULL;
	char *setenv_temp[] = {
		"setenv",
		"OLDPWD",
		temp,
		NULL
	};

	if (indice == -1) {
		free(temp);
		my_putestr("cd: OLDPWD not set.\n");
		return (1);
	}
	splited = split((*envp)[indice], '=');
	chdir(splited[1]);
	my_setenv(setenv_temp, envp);
	free_double(splited);
	free(temp);
	return (0);
}

int my_cd(char **command, char ***envp)
{
	int fd = -1;
	int indice = 0;

	if (command[1] == NULL)
		return (1);
	if (command[2] != NULL) {
		my_putestr("cd: Too many arguments.");
		return (1);
	}
	indice = get_var_in_env("OLDPWD", *envp);
	if (my_strcmp(command[1], "-")) {
		return (my_cd_last(envp, indice));
	} else if ((fd = open(command[1], O_DIRECTORY)) == -1) {
		print_error_cd(command[1]);
		return (1);
	}
	CLOSEFD(fd);
	set_oldwpd(envp);
	chdir(command[1]);
	return (0);
}
