/*
** EPITECH PROJECT, 2017
** get_function_list.c
** File description:
** get the function from the path
*/

#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include "lib_func.h"
#include "lib_my.h"
#include "path.h"
#include "env.h"

int exeucatble(char *filepath)
{
	int result = 0;
	int test = 0;

	test = open(filepath, O_DIRECTORY);
	if (test == -1) {
		if (access(filepath, X_OK) == 0)
			result = 1;
	} else
		close(test);
	return (result);
}

char **get_in_dir(char **src, DIR *dir, char *path, int *count)
{
	struct dirent *file = NULL;
	char *temp = NULL;

	while ((file = readdir(dir))) {
		temp = my_strconcat(path, file->d_name);
		if (exeucatble(temp)) {
			src = my_realoc_double(src);
			src[*count] = temp;
			*count = *count + 1;
		} else
			free(temp);
	}
	return (src);
}

char **get_function_in_path(char **path)
{
	char **result = NULL;
	DIR *dir = NULL;
	int count = 0;
	char *temp = NULL;

	result = my_malloc(sizeof(char *) * 1);
	result[0] = NULL;
	for (int i = 0; path[i] != NULL; i = i + 1) {
		if ((dir = opendir(path[i])) != NULL) {
			temp = my_strconcat(path[i], "/");
			result = get_in_dir(result, dir, temp, &count);
			free(temp);
			closedir(dir);
		}
	}
	return (result);
}

char **get_path(char *path)
{
	char **result = NULL;
	char **temp = NULL;

	temp = split(path, '=');
	result = split(temp[1], ':');
	for (int i = 0; temp[i] != NULL; i = i + 1)
		free(temp[i]);
	free(temp);
	return (result);
}

char **get_function_list(char ***envp)
{
	int indice = -1;
	char **result = NULL;
	char **path = NULL;

	indice = get_var_in_env("PATH", *envp);
	if (indice == -1) {
		my_setenv((char *[]) {"setenv", "PATH", "/bin", NULL}, envp);
		return (get_function_list(envp));
	}
	path = get_path((*envp)[indice]);
	result = get_function_in_path(path);
	for (int i = 0; path[i] != NULL; i = i + 1)
		free(path[i]);
	free(path);
	return (result);
}
