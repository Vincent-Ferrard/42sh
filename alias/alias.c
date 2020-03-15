/*
** EPITECH PROJECT, 2018
** alias_command.c
** File description:
** alias_command
*/

#include "main.h"
#include "alias.h"
#include "lib_func.h"

void set_new_value_alias(char **alias, char **tab, int i)
{
	if (alias[i] != NULL)
		free(alias[i]);
	if (alias[i + 1] != NULL)
		free(alias[i + 1]);
	alias[i] = my_real_strcpy(tab[1]);
	alias[i + 1] = my_real_strcpy(tab[2]);
	for (int j = 3; tab[j]; j++) {
		alias[i + 1] = my_strconcat(alias[i + 1], " ");
		alias[i + 1] = my_strconcat(alias[i + 1], tab[j]);
	}
}

char **set_alias_command(char **tab, char **alias, int i)
{
	int j = 0;
	int len = 0;
	int len2 = my_strlen(tab[2]);
	char **temp = NULL;

	for (j = 3; tab[j]; j++)
		len2 += my_strlen(tab[j]);
	for (len = 0; alias[len]; len++);
	if (alias[i] == NULL) {
		temp = my_strcpy_array(alias);
		free_double(alias);
		alias = temp;
		set_new_value_alias(temp, tab, i);
		alias[i + 2] = NULL;
	} else
		set_new_value_alias(alias, tab, i);
	return (alias);
}

int alias_command2(char **alias, char **tab, int *i)
{
	for (*i = 0; alias[*i]; *i += 2) {
		if (my_strcmp(alias[*i], tab[1]) == 1) {
			alias = set_alias_command(tab, alias, *i);
			return (1);
		}
	}
	return (0);
}

char **alias_command(char **tab, char **alias)
{
	int i;
	int check = 0;

	if (tab[1] == NULL) {
		alias = order_tab(alias);
		display_alias(alias);
	} else if (tab[2] != NULL) {
		check = alias_command2(alias, tab, &i);
		if (check != 1)
			alias = set_alias_command(tab, alias, i);
	}
	return (alias);
}
