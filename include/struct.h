/*
** EPITECH PROJECT, 2017
** struct.h
** File description:
** contain my structure function and all related function
*/

#ifndef _STRUCT_H_
#define _STRUCT_H_

typedef struct function func_t;
struct function {
	char **alias;
	char **function;
	int next_flags;
	int previous_flags;
	func_t *next;
};

func_t *create_function(char const *command, int previous_flags, char **alias);
void destroy_function(func_t *object);

#endif
