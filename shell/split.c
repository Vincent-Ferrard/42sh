/*
** EPITECH PROJECT, 2017
** split.c
** File description:
** a function that split a string into many string
*/

#include <stdlib.h>
#include "lib_my.h"

int count_word_split(char const *str, char split)
{
	int space = 1;
	int len = 0;

	for (int i = 0; str[i] != 0; i = i + 1) {
		if (str[i] != split && space == 1) {
			space = 0;
			len = len + 1;
		} else if (str[i] == split)
			space = 1;
	}
	return (len);
}

void boucle_split(char const *str, char **result, char split)
{
	int w = 0;
	int chara = 0;
	int space = 1;

	for (int i = 0; str[i] != 0; i = i + 1) {
		if (str[i] == split && space == 0) {
			result[w][chara] = 0;
			space = 1;
			chara = 0;
			w = w + 1;
		} else if (str[i] != split) {
			space = 0;
			result[w] = my_realoc(result[w]);
			result[w][chara] = str[i];
			result[w][chara + 1] = 0;
			chara = chara + 1;
		}
	}
}

char **split(char const *str, char split)
{
	char **result = NULL;
	int len = 0;

	if (str == NULL)
		return (NULL);
	len = count_word_split(str, split);
	if (len == 0)
		return (NULL);
	result = my_malloc(sizeof(char *) * (len + 1));
	for (int i = 0; i < len; i = i + 1)
		result[i] = my_malloc(sizeof(char));
	result[len] = NULL;
	boucle_split(str, result, split);
	return (result);
}

void advance_in_split(int *indice, int *car, int *splited, int *space)
{
	*car = 0;
	*splited = 1;
	*indice = *indice + 1;
	*space = 1;
}

char **split_one(char const *str, char split)
{
	char **result = my_malloc(sizeof(char *) * 3);
	int indice = 0;
	int car = 0;
	int splited = 0;
	int space = 1;

	for (int i = 0; str[i] != 0; i = i + 1) {
		if (str[i] == split && !splited && space == 0)
			advance_in_split(&indice, &car, &splited, &space);
		else if (str[i] != split || splited) {
			result[indice] = my_realoc(result[indice]);
			result[indice][car] = str[i];
			car = car + 1;
			result[indice][car] = 0;
			space = 0;
		}
	}
	result[2] = NULL;
	return (result);
}
