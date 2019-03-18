/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** loose
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include "my.h"
#include "malloc.h"
#include "sokoban.h"

int box_block(board_t *map, int x, int y)
{
    if (map->board[x][y] == 'X') {
        if (map->board[x + 1][y] == '#' && map->board[x][y + 1] == '#')
            return (1);
        if (map->board[x + 1][y] == '#' && map->board[x][y - 1] == '#')
            return (1);
        if (map->board[x - 1][y] == '#' && map->board[x][y + 1] == '#')
            return (1);
        if (map->board[x - 1][y] == '#' && map->board[x][y - 1] == '#')
            return (1);
    }
    return (0);
}

int is_a_box(board_t *map, int lines, int col)
{
    if (map->board[lines][col] == 'X')
        return (1);
    return (0);
}

int moves_possible(board_t *map)
{
    int box_count = 0;
    int box_blocked = 0;

    for (int lines = 0; lines < map->nb_line; lines++) {
        for (int col = 0; col < map->nb_col[lines]; col++)
            box_count = box_count + is_a_box(map, lines, col);
    }
    for (int lines = 0; lines < map->nb_line; lines++) {
        for (int col = 0; col < map->nb_col[lines]; col++)
            box_blocked = box_blocked + box_block(map, lines, col);
    }
    if (box_blocked == box_count)
        return (0);
    return (1);
}