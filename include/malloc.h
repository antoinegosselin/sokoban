/*
** EPITECH PROJECT, 2018
** malloc.h
** File description:
** safe_malloc functions
*/

#ifndef MALLOC_H
#define MALLOC_H

int *safe_malloc_int(long long size);
int **safe_malloc_int_array(long long size);
char *safe_malloc_char(long long size);
char **safe_malloc_char_array(long long size);

#endif //MALLOC_H