/*
** EPITECH PROJECT, 2018
** move.c
** File description:
** all the move functions
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

int movable(board_t *map, next_pos_t n, pos_now_t *player)
{
    if (map->board[n.x][n.y] == '#')
        return (0);
    player->stockage = (map->board[n.x][n.y] == 'O') ? 1 : 0;
    if (map->board[n.x][n.y] == 'X') {
        if (map->board[n.x2][n.y2] == '#' || map->board[n.x2][n.y2] == 'X')
            return (0);
        else if (map->board[n.x2][n.y2] == 'O')
            return (3);
        else
            return (2);
    }
    return (1);
}

void move_up(board_t *board, pos_now_t *p, int stockage, char **map_zero)
{
    next_pos_t next_pos = init_npos(p->line - 1, p->col, p->line - 2, p->col);
    int move_possible = movable(board, next_pos, p);

    if (move_possible != 0) {
        board->board[p->line - 1][p->col] = 'P';
        if (move_possible == 3) {
            board->board[p->line - 2][p->col] = 'X';
            p->stocks--;
        }
        if (move_possible == 2)
            board->board[p->line - 2][p->col] = 'X';
        board->board[p->line][p->col] = (stockage == 1) ? 'O' : ' ';
        if (first_cond && map_zero[p->line][p->col] == 'O') {
            board->board[p->line][p->col] = 'O';
            p->stocks++;
        }
        p->line--;
    }
}

void move_down(board_t *board, pos_now_t *p, int stockage, char **map_zero)
{
    next_pos_t next_pos = init_npos(p->line + 1, p->col, p->line + 2, p->col);
    int move_possible = movable(board, next_pos, p);

    if (move_possible != 0) {
        board->board[p->line + 1][p->col] = 'P';
        if (move_possible == 3) {
            board->board[p->line + 2][p->col] = 'X';
            p->stocks--;
        }
        if (move_possible == 2)
            board->board[p->line + 2][p->col] = 'X';
        board->board[p->line][p->col] = (stockage == 1) ? 'O' : ' ';
        if (first_cond && map_zero[p->line][p->col] == 'O') {
            board->board[p->line][p->col] = 'O';
            p->stocks++;
        }
        p->line++;
    }
}

void move_left(board_t *board, pos_now_t *p, int stockage, char **map_zero)
{
    next_pos_t next_pos = init_npos(p->line, p->col - 1, p->line, p->col - 2);
    int move_possible = movable(board, next_pos, p);

    if (move_possible != 0) {
        board->board[p->line][p->col - 1] = 'P';
        if (move_possible == 3) {
            board->board[p->line][p->col - 2] = 'X';
            p->stocks--;
        }
        if (move_possible == 2)
            board->board[p->line][p->col - 2] = 'X';
        board->board[p->line][p->col] = (stockage == 1) ? 'O' : ' ';
        if (first_cond && map_zero[p->line][p->col] == 'O') {
            board->board[p->line][p->col] = 'O';
            p->stocks++;
        }
        p->col--;
    }
}

void move_right(board_t *board, pos_now_t *p, int stockage, char **map_zero)
{
    next_pos_t next_pos = init_npos(p->line, p->col + 1, p->line, p->col + 2);
    int move_possible = movable(board, next_pos, p);

    if (move_possible != 0) {
        board->board[p->line][p->col + 1] = 'P';
        if (move_possible == 3) {
            board->board[p->line][p->col + 2] = 'X';
            p->stocks--;
        }
        if (move_possible == 2)
            board->board[p->line][p->col + 2] = 'X';
        board->board[p->line][p->col] = (stockage == 1) ? 'O' : ' ';
        if (first_cond && map_zero[p->line][p->col] == 'O') {
            board->board[p->line][p->col] = 'O';
            p->stocks++;
        }
        p->col++;
    }
}