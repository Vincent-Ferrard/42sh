/*
** EPITECH PROJECT, 2017
** my_strlen.c
** File description:
** a function that count the length of a string
*/

#include <stdlib.h>

int my_strlen(char const *str)
{
	int len = 0;

	if (str == NULL)
		return (0);
	for (len = 0; str[len] != 0; len = len + 1);
	return (len);
}

int my_tablen(char * const *tab)
{
	int count = 0;

	if (tab == NULL)
		return (0);
	for (count = 0; tab[count] != NULL; count = count + 1);
	return (count);
}
