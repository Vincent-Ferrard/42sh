/*
** EPITECH PROJECT, 2018
** str_concat.c
** File description:
** str_concat.c
*/

#include <stdlib.h>
#include "lib_my.h"

char *my_strconcat(char const *str1, char const *str2)
{
	char *result = NULL;
	int len = my_strlen(str1) + my_strlen(str2) + 1;
	int indice = 0;

	result = my_malloc(sizeof(char) * len);
	for (int i = 0; str1[i] != 0; i = i + 1) {
		result[indice] = str1[i];
		indice = indice + 1;
	}
	for (int i = 0; str2[i] != 0; i = i + 1) {
		result[indice] = str2[i];
		indice = indice + 1;
	}
	result[indice] = 0;
	return (result);
}

int endswith(char const *str, char const *ends)
{
	int len_str = my_strlen(str);
	int len_ends = my_strlen(ends);

	if (len_str < len_ends)
		return (0);
	while (len_ends != -1) {
		if (str[len_str] != ends[len_ends])
			return (0);
		len_str = len_str - 1;
		len_ends = len_ends - 1;
	}
	return (1);
}
