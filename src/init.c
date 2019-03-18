/*
** EPITECH PROJECT, 2018
** init.c
** File description:
** init my things
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

next_pos_t init_npos(int x, int y, int x2, int y2)
{
    next_pos_t next_pos;

    next_pos.x = x;
    next_pos.y = y;
    next_pos.x2 = x2;
    next_pos.y2 = y2;
    return (next_pos);
}