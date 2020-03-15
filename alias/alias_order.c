/*
** EPITECH PROJECT, 2018
** get_tetriminos.c
** File description:
** get_tetriminos
*/

#include "alias.h"

int check_switch(char *s, char *s2)
{
	int i;

	for (i = 0; s[i] && s2[i]; i++) {
		if (s[i] > s2[i])
			return (1);
		else if (s[i] < s2[i])
			return (0);
	}
	return (0);
}

int order_tab2(char **tab, int i, int check)
{
	char *s = NULL;

	if (check_switch(tab[i - 2], tab[i]) == 1) {
		s = my_real_strcpy(tab[i - 2]);
		tab[i - 2] = my_real_strcpy(tab[i]);
		tab[i] = my_real_strcpy(s);
		free(s);
		s = my_real_strcpy(tab[i - 1]);
		tab[i - 1] = my_real_strcpy(tab[i + 1]);
		tab[i + 1] = my_real_strcpy(s);
		check = 1;
		free(s);
	}
	return (check);
}

char **order_tab(char **tab)
{
	int i;
	int check = 1;

	while (check == 1) {
		check = 0;
		for (i = 2; tab[i]; i += 2)
			check = order_tab2(tab, i, check);
	}
	return (tab);
}

char *my_real_strcpy(char *s)
{
	char *n_s = my_malloc(sizeof(char) * (my_strlen(s) + 1));
	int i = 0;

	for (i = 0; s[i]; i++)
		n_s[i] = s[i];
	return (n_s);
}

char **my_strcpy_array(char **tab)
{
	char **n_tab = NULL;
	int i = 0;

	for (i = 0; tab[i]; i++);
	n_tab = my_malloc(sizeof(char *) * (i + 3));
	for (i = 0; tab[i]; i++)
		n_tab[i] = my_real_strcpy(tab[i]);
	return (n_tab);
}
