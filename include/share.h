/*
** EPITECH PROJECT, 2017
** share.h
** File description:
** just for a global variable
*/

#include <unistd.h>

#ifdef SHARED
pid_t pid_child;
#else
extern pid_t pid_child;
#endif
