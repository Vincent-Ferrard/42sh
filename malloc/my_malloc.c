/*
** EPITECH PROJECT, 2017
** my_malloc.c
** File description:
** a function that malloc and do a memeset.
*/

#include <stdlib.h>
#include <stdio.h>

void *my_malloc(unsigned long size)
{
	char *result = NULL;

	result = malloc(size);
	if (result == NULL) {
		perror("malloc");
		exit(84);
	}
	for (unsigned long i = 0; i < size; i = i + 1)
		result[i] = 0x0;
	return ((void *) result);
}
