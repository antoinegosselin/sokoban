/*
** EPITECH PROJECT, 2018
** my_put_map.c
** File description:
** put the map
*/

#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include "my.h"
#include "sokoban.h"

// -1 -> error
// 0 -> # (wall)
// 1 -> ' ' (nothing)
// 2 -> P (player)
// 3 -> O (stockage)
// 4 −> X (box)
// 5 -> '\n' (end of line)

void my_put_map(board_t *map)
{
    for (int lines = 0; lines < map->nb_line; lines++) {
        for (int col = 0; col <= map->nb_col[lines]; col++) {
            mvprintw(lines, col, "%c", map->board[lines][col]);
        }
    }
}