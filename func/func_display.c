/*
** EPITECH PROJECT, 2017
** my_putchar.c
** File description:
** a function that write a character
*/

#include <stdlib.h>
#include <unistd.h>
#include "lib_my.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}

void my_putstr(char const *str)
{
	write(1, str, my_strlen(str));
}

void my_putestr(char const *str)
{
	if (str == NULL)
		return;
	write(2, str, my_strlen(str));
}

void print_error_command(char const *str)
{
	my_putestr(str);
	my_putestr(": Command not found.\n");
}
