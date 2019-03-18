/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main of sokoban
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

void wait_event(board_t *board, pos_now_t *player, char *str, char **map_zero)
{
    int event = getch();

    if (event == 27 || event == 32) {
        clear();
        endwin();
        if (event == 32)
            exit(my_sokoban(str));
        exit(0);
    }
    if (event == KEY_UP)
        move_up(board, player, player->stockage, map_zero);
    if (event == KEY_DOWN)
        move_down(board, player, player->stockage, map_zero);
    if (event == KEY_LEFT)
        move_left(board, player, player->stockage, map_zero);
    if (event == KEY_RIGHT)
        move_right(board, player, player->stockage, map_zero);
}

void check_size_window(board_t *map)
{
    int x;
    int y;

    while (COLS < map->max_col || LINES < map->nb_line) {
        x = LINES / 2;
        y = (COLS - 18) / 2;
        clear();
        mvprintw(x, y, "Window too small!");
        refresh();
    }
}

int window_loop(board_t *map, pos_now_t *player, char *str, char **map_zero)
{
    int ret_val = 0;

    initscr();
    keypad(stdscr, TRUE);
    curs_set(0);
    while (1) {
        check_size_window(map);
        clear();
        my_put_map(map);
        refresh();
        if (player->stocks == 0)
            break;
        if (moves_possible(map) == 0) {
            ret_val = 1;
            break;
        }
        wait_event(map, player, str, map_zero);
    }
    endwin();
    return (ret_val);
}

int my_sokoban(char *str)
{
    board_t *map = malloc(sizeof(board_t) * 1);
    pos_now_t *player = malloc(sizeof(pos_now_t) * 1);
    char **map_zero;

    map_lines(str, map);
    map->board = fill_board(str, map->nb_line, map->nb_col, player);
    map_zero = fill_board_zero(str, map->nb_line, map->nb_col);
    return (window_loop(map, player, str, map_zero));
}

int main(int ac, char **av)
{
    char *str;

    if (ac != 2) {
        write(2, "Wrong number of arguments\n", 26);
        exit(84);
    }
    if (my_strlen(av[1]) == 2 && av[1][0] == '-' && av[1][1] == 'h')
        return (print_usage());
    str = my_file_readall(av[1]);
    return (my_sokoban(str));
}