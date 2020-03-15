/*
** EPITECH PROJECT, 2017
** format_str.c
** File description:
** the function for the string format
*/

#include <stdlib.h>
#include "lib_my.h"

void delchar(char *str, int i)
{
	if (i >= my_strlen(str) || i < 0)
		return;
	for (; str[i] != 0; i = i + 1)
		str[i] = str[i + 1];
}

char *addchar(char *str, int i, char added_char)
{
	char *result = 0x0;

	if (i > my_strlen(str) || i < 0)
		return (str);
	result = my_realoc(str);
	for (int temp = my_strlen(result); temp >= i; temp = temp - 1) {
		if (temp == 0)
			result[temp] = 0;
		else
			result[temp] = result[temp - 1];
	}
	result[i] = added_char;
	return (result);
}

void dell_fin_space(char *str)
{
	int len = my_strlen(str) - 1;

	if (len < 0)
		return;
	for (; str[len] == ' ' && len != -1; len = len - 1)
		delchar(str, len);
}

void format_str(char *str)
{
	int space = 1;

	if (str == NULL)
		return;
	for (int i = 0; str[i] != 0; i = i + 1) {
		if (str[i] == '\t') {
			delchar(str, i);
			i = i - 1;
		}
	}
	for (int i = 0; str[i] != 0; i = i + 1) {
		if (str[i] == ' ' && space == 1) {
			delchar(str, i);
			i = i - 1;
		} else if (str[i] != ' ')
			space = 0;
	}
	dell_fin_space(str);
}
