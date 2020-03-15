/*
** EPITECH PROJECT, 2017
** list_dir.c
** File description:
** list all the file in a selected dir
*/

#include <stdlib.h>
#include <dirent.h>
#include "lib_func.h"
#include "lib_my.h"

char **list_dir(char const *dir_path)
{
	char **result = NULL;
	DIR *dir = NULL;
	struct dirent *file = NULL;

	if (dir_path == NULL)
		return (NULL);
	if ((dir = opendir(dir_path)) == NULL)
		return (NULL);
	for (int i = 0; (file = readdir(dir)); i = i + 1) {
		result = my_realoc_double(result);
		result[i] = my_strdup(file->d_name);
	}
	return (result);
}

char **list_dir_startswith(char const *dir_path, char const *dir_name)
{
	char **result = NULL;
	char **temp = NULL;
	int indice = 0;

	if (dir_path == NULL)
		return (NULL);
	if ((temp = list_dir(dir_path)) == NULL)
		return (NULL);
	if (dir_name == NULL)
		return (temp);
	for (int i = 0; temp[i] != NULL; i = i + 1) {
		if (startswith(temp[i], dir_name)) {
			result = my_realoc_double(result);
			result[indice] = my_strdup(temp[i]);
			indice = indice + 1;
		}
	}
	free_double(temp);
	return (result);
}
