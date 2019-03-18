/*
** EPITECH PROJECT, 2018
** disp_stdarg.c
** File description:
** disp args
*/

#include <stdarg.h>
#include "my_printf.h"
#include "my.h"

int disp_stdarg(char *s, ...)
{
    va_list list;
    int len = my_strlen(s);
    int count = 0;

    va_start(list, s);
    for (; count < len; count++) {
        if (s[count] == 'c')
            my_putchar(va_arg(list, int));
        if (s[count] == 's')
            my_putstr(va_arg(list, char *));
        if (s[count] == 'i')
            my_put_nbr(va_arg(list, int));
        my_putchar('\n');
    }
    va_end(list);
    return (0);
}