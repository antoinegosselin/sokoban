/*
** EPITECH PROJECT, 2018
** my_len.c
** File description:
** length calculators
*/

#include "my.h"
#include "sokoban.h"
#include "malloc.h"

int check_max_col(int nb_col, int max_col)
{
    if (nb_col > max_col)
        return (nb_col);
    else
        return (max_col);
}

void map_lines(char *str, board_t *map)
{
    int len = 0;
    int col = 0;

    map->max_col = 0;
    for (int count = 0; str[count] != '\0'; count++) {
        if (str[count] == '\n')
            len++;
    }
    map->nb_line = len;
    map->nb_col = safe_malloc_int(sizeof(int) * map->nb_line);
    len = 0;
    for (int count = 0; str[count] != '\0'; count++) {
        if (str[count] == '\n') {
            map->nb_col[len] = col;
            map->max_col = check_max_col(map->nb_col[len], map->max_col);
            len++;
            col = -1;
        }
        col++;
    }
}