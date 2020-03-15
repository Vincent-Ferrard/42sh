/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** the main file for the programme
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "lib_my.h"

char *get_next_line(int const fd)
{
	char c = 0;
	char *result = NULL;
	int ind = 0;

	while (read(fd, &c, 1) && c != '\n' && c != EOF) {
		result = my_realoc(result);
		result[ind] = c;
		ind = ind + 1;
	}
	if (c == '\n' && result == NULL) {
		result = my_malloc(sizeof(char) * 2);
		result[0] = ' ';
		ind = 1;
	}
	if (result == NULL)
		return (result);
	result[ind] = '\0';
	return (result);
}
