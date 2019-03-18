/*
** EPITECH PROJECT, 2018
** check_malloc.c
** File description:
** Malloc our string, check the return of the malloc, and return the string
*/

#include <stdlib.h>
#include "my.h"
#include "sokoban.h"

char *safe_malloc_char(long long size)
{
    char *var = malloc(sizeof(char) * size);

    if (var == 0)
        exit(84);
    return (var);
}

int *safe_malloc_int(long long size)
{
    int *var = malloc(sizeof(int) * size);

    if (var == 0)
        exit(84);
    return (var);
}

char **safe_malloc_char_array(long long size)
{
    char **var = malloc(sizeof(char *) * size);

    if (var == 0)
        exit(84);
    return (var);
}

int **safe_malloc_int_array(long long size)
{
    int **var = malloc(sizeof(int *) * size);

    if (var == 0)
        exit(84);
    return (var);
}