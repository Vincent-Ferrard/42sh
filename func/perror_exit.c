/*
** EPITECH PROJECT, 2018
** perror_exit.c
** File description:
** perror_exit.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "lib_func.h"

void perror_exit(void)
{
	perror("Error");
	exit(1);
}
