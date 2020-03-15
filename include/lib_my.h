/*
** EPITECH PROJECT, 2017
** get_var_in_env.c
** File description:
** get a variable indice in the environement.
*/

#ifndef WEAK
#define WEAK __attribute__((weak))
#endif

#ifndef UNUSED
#define UNUSED __attribute__((unused))
#endif

#ifndef _LIB_MY_H_
#define _LIB_MY_H_

#define PS1 "42sh> "

char *my_strconcat(char const *str1, char const *str2);
int my_strcmp(char const *str1, char const *str2);
int my_strstr(char const *str, char const *find);
char *my_strcpy(char *dest, char const *src);
void *my_malloc(unsigned long size);
char **my_realoc_double(char **src);
char *my_strdup(char const *str);
void my_putestr(char const *str);
int my_tablen(char * const *tab);
void my_putstr(char const *str);
int my_strlen(char const *str);
char *my_realoc(char *src);
void my_putchar(char c);

#endif
