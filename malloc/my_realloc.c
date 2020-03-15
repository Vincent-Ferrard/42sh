/*
** EPITECH PROJECT, 2017
** my_realloc.c
** File description:
** realloc my variable with one more size
*/

#include <stdlib.h>
#include "lib_my.h"

char *my_realoc(char *src)
{
	char *result = NULL;

	if (src == NULL)
		result = my_malloc(sizeof(char) * 2);
	else
		result = my_malloc(sizeof(char) * (my_strlen(src) + 2));
	my_strcpy(result, src);
	if (src != NULL)
		free(src);
	return (result);
}

char **my_realoc_double(char **src)
{
	char **result = NULL;
	int len = 0;

	if (src == NULL)
		len = 2;
	else
		for (len = 0; src[len] != NULL; len = len + 1);
	result = my_malloc(sizeof(char *) * (len + 2));
	if (src != NULL) {
		for (int i = 0; src[i] != NULL; i = i + 1)
			result[i] = src[i];
		free(src);
	}
	result[len] = NULL;
	result[len + 1] = NULL;
	return (result);
}
