/*
** EPITECH PROJECT, 2017
** lib_func.c
** File description:
** a lib of usefull function
*/

#pragma once

void advance_in_split(int *indice, int *car, int *splited, int *space);
void boucle_split(char const *str, char **result, char split);
void delete_one_case_double(char ***envp, int indice);
int startswith(char const *src, char const *start);
int count_word_split(char const *str, char split);
char *addchar(char *str, int i, char added_char);
int endswith(char const *str, char const *ends);
char **split_one(char const *str, char split);
char **split(char const *str, char split);
int is_alpha_str(char const *str);
void free_double(char **function);
char *get_next_line(int const fd);
void delchar(char *str, int i);
void format_str(char *str);
int int_is_alpha(int ch);
int is_alpha(char c);
void perror_exit(void);
