/*
** EPITECH PROJECT, 2017
** moveto.c
** File description:
** a function that move the cursor
*/

#include <stdio.h>

void moveto(int haut, int bas, int droite, int gauche)
{
	if (haut > 0)
		printf("\033[%dA", haut);
	if (bas > 0)
		printf("\033[%dB", bas);
	if (droite > 0)
		printf("\033[%dC", droite);
	if (gauche > 0)
		printf("\033[%dD", gauche);
}
