/*
** EPITECH PROJECT, 2018
** alias_exec.c
** File description:
** alias_exec
*/

#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "alias.h"
#include "lib_func.h"
#include "path.h"

void exec_alias(char **alias, char **tab, char **tab_path, char **envp)
{
	char *command = NULL;
	char **n_command = NULL;
	char *temp = NULL;
	int indice = 0;

	for (int i = 0; alias[i]; i += 2) {
		if (my_strcmp(tab[0], alias[i]) == 1) {
			command = my_real_strcpy(alias[i + 1]);
			for (int j = 1; tab[j]; j++) {
				temp = my_strconcat(command, " ");
				free(command);
				command = my_strconcat(temp, tab[j]);
				free(temp);
			}
			n_command = split(command, ' ');
			free(command);
			execve(n_command[0], n_command, envp);
			indice = find_in_list(n_command[0], tab_path);
			if (indice != -1)
				execve(tab_path[indice], n_command, envp);
		}
	}
}

void display_alias(char **alias)
{
	for (int i = 0; alias[i]; i += 2) {
		if (my_strlen(alias[i]) >= 8)
			printf("%s %s\n", alias[i], alias[i + 1]);
		else
			printf("%s\t%s\n", alias[i], alias[i + 1]);
	}
}

char **set_basic_alias2(char **alias, char *s, int *i)
{
	int j = 0;
	int k = 0;

	alias[*i] = my_malloc(sizeof(char) * my_strlen(s));
	for (j = 0; s[j] != ' ' && s[j]; j++)
		alias[*i][j] = s[j];
	alias[*i][j] = '\0';
	alias[*i + 1] = my_malloc(sizeof(char) * my_strlen(s));
	for (j = j + 1; s[j] != '\n' && s[j]; j++) {
		alias[*i + 1][k] = s[j];
		k++;
	}
	alias[*i + 1][k] = '\0';
	return (alias);
}

char **set_basic_alias(void)
{
	char **alias = my_malloc(sizeof(char *) * 30);
	int fd = open("list.alias", O_RDWR | O_CREAT, 0664);
	char *s = NULL;
	int i = 0;

	for (i = 0; i < 28 && fd != -1; i += 2) {
		if ((s = get_next_line(fd)) == NULL)
			break;
		alias = set_basic_alias2(alias, s, &i);
		free(s);
	}
	alias[i] = NULL;
	close(fd);
	return (alias);
}
