/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** zero
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

char **fill_board_zero(char *str, int nb_line, int *nb_col)
{
    char **map_zero = malloc_char_array(nb_line, nb_col);
    pos_now_t pos = {0, 0, 0, 0, 0};

    for (int count = 0; str[count] != '\0'; count++) {
        if (str[count] == '\n') {
            pos.line++;
            pos.col = -1;
        }
        else if (str[count] == 'O')
            map_zero[pos.line][pos.col] = str[count];
        else
            map_zero[pos.line][pos.col] = ' ';
        pos.col++;
    }
    return (map_zero);
}