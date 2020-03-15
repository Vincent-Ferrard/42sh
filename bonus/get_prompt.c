/*
** EPITECH PROJECT, 2017
** get_prompt.c
** File description:
** a bonus to get a clean prompt
*/


#include <stdlib.h>
#include <stdio.h>
#include "lib_func.h"
#include "lib_my.h"
#include "cursor.h"

char getche(void)
{
	int ch = -1;

	system("stty -echo");
	system("stty raw");
	ch = getchar();
	if (ch == '\033') {
		getchar();
		ch = getchar();
		if (ch == 'A' || ch == 'B' || ch == 'C' || ch == 'D')
			ch = -ch;
		else if (ch == 53 || ch == 54 || ch == 51)
			ch = getchar() * -1;
		else
			ch = -1;
	}
	system("stty echo");
	system("stty cooked");
	return (ch);
}

int character_test(char *result, int slot, int ch)
{
	switch (ch) {
		case 3:
			free(result);
			printf("\n");
			slot = -2;
			break;
		case 4:
			slot = -1;
			break;
		case 'A':
			break;
		case 'B':
			break;
		case -126:
			delchar(result, slot);
			break;
	}
	return (slot);
}

int slot_test(char *result, int *slot, int ch)
{
	int i = 0;

	if (ch == 127 && *slot > 0) {
		*slot = *slot <= 0 ? 0 : *slot - 1;
		delchar(result, *slot);
		i = 1;
	} else if (ch == - 'C' && *slot <= my_strlen(result)) {
		*slot = *slot + 1;
		i = 1;
	}
	if (ch == - 'D' && *slot > 0) {
		*slot = *slot - 1;
		i = 1;
	}
	return (i);
}

char *line_mod(char *result, int *slot, int ch)
{
	if (slot_test(result, slot, ch));
	else if (ch >= 0) {
		result = addchar(result, *slot, ch);
		*slot = *slot + 1;
	}
	return (result);
}

char *get_prompt(void)
{
	int ch = 0;
	char *result = my_malloc(sizeof(char));
	int slot = 0;

	printf("\r%*c\r%s", my_strlen(result) + my_strlen(PS1) + 1, ' ', PS1);
	while (1) {
		if ((ch = getche()) == 13) {
			printf("\n");
			return (result);
		} else if (ch == -1)
			continue;
		result = line_mod(result, &slot, ch);
		if ((slot = character_test(result, slot, ch)) == -2)
			return (my_strdup(" "));
		else if (slot == -1)
			return (NULL);
		printf("\r%*c\r", my_strlen(result) + my_strlen(PS1) + 1, ' ');
		printf("%s%s", PS1, result);
		moveto(0, 0, 0, my_strlen(result) - slot);
		fflush(stdout);
	}
}
