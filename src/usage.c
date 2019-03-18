/*
** EPITECH PROJECT, 2018
** usage.c
** File description:
** print usage
*/

#include "my.h"

int print_usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map  file representing the warehouse map, containing ‘#");
    my_putstr("’ for walls,\n          ‘P’ for the player");
    my_putstr(", ‘X’ for boxes and ‘O’ for storage locations\n");
    return (0);
}
