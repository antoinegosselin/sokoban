/*
** EPITECH PROJECT, 2018
** fill_board.c
** File description:
** fill the first board
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

char const CHARS[6] = "# POX";

int check_char(char c, errors_t *errors)
{
    int value = -1;

    for (int count = 0; CHARS[count] != '\0'; count++) {
        if (c == CHARS[count])
            value = count;
    }
    if (value == 2)
        errors->nb_player++;
    if (value == 3)
        errors->nb_stockage++;
    if (value == 4)
        errors->nb_box++;
    if (c == '\n')
        value = 5;
    return (value);
}

char **malloc_char_array(int nb_line, int *nb_col)
{
    char **str = safe_malloc_char_array(nb_line);

    for (int count = 0; count < nb_line; count++)
        str[count] = safe_malloc_char(nb_col[count]);
    return (str);
}

void init_player(pos_now_t *player, pos_now_t pos)
{
    player->line = pos.line;
    player->col = pos.col;
    player->value = 2;
    player->stockage = 0;
}

char **check_error(errors_t errors, char **map, pos_now_t *player)
{
    int count = 0;

    if (errors.nb_player != 1)
        count++;
    if (errors.nb_box != errors.nb_stockage)
        count++;
    if (count != 0) {
        write(2, "error: invalid map\n", 19);
        exit(84);
    } else {
        player->stocks = errors.nb_stockage;
        return (map);
    }
}

char **fill_board(char *str, int nb_line, int *nb_col, pos_now_t *player)
{
    char **map = malloc_char_array(nb_line, nb_col);
    pos_now_t pos = {0, 0, 0, 0, 0};
    errors_t errors = {0, 0, 0};

    for (int count = 0; str[count] != '\0'; count++) {
        pos.value = check_char(str[count], &errors);
        if (pos.value == -1) {
            write(2, "error: invalid map\n", 19);
            exit(84);
        }
        if (pos.value == 2)
            init_player(player, pos);
        map[pos.line][pos.col] = str[count];
        if (pos.value == 5) {
            pos.line++;
            pos.col = -1;
        }
        pos.col++;
    }
    return (check_error(errors, map, player));
}