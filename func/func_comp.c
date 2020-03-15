/*
** EPITECH PROJECT, 2017
** my_putchar.c
** File description:
** a function that write a character
*/

#include <stdlib.h>
#include "lib_my.h"

int my_strcmp(char const *str1, char const *str2)
{
	if (my_strlen(str1) != my_strlen(str2))
		return (0);
	for (int i = 0; str1[i] != 0; i = i + 1) {
		if (str1[i] != str2[i])
			return (0);
	}
	return (1);
}

char *my_strcpy(char *dest, char const *src)
{
	if (dest == NULL || src == NULL)
		return (dest);
	for (int i = 0; src[i] != 0; i = i + 1) {
		dest[i] = src[i];
		dest[i + 1] = 0;
	}
	return (dest);
}

char *my_strdup(char const *str)
{
	char *result = NULL;

	if (str == NULL)
		return (NULL);
	result = my_malloc(sizeof(char) * (my_strlen(str) + 1));
	my_strcpy(result, str);
	return (result);
}

int startswith(char const *src, char const *start)
{
	if (my_strlen(src) < my_strlen(start))
		return (0);
	for (int i = 0; start[i] != 0; i = i + 1) {
		if (src[i] != start[i])
			return (0);
	}
	return (1);
}

int my_strstr(char const *str, char const *find)
{
	int indice = 0;

	if (str == NULL || find == NULL)
		return (0);
	if (my_strlen(str) < my_strlen(find))
		return (0);
	else if (my_strlen(str) == my_strlen(find))
		return (my_strcmp(str, find));
	for (int i = 0; str[i] != 0 && find[indice] != 0; i = i + 1) {
		if (str[i] == find[indice])
			indice = indice + 1;
		else if (str[i] != find[indice] && indice != 0) {
			i = i - indice;
			indice = 0;
		}
	}
	if (indice == 0)
		return (0);
	return (1);
}
