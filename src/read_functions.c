/*
** EPITECH PROJECT, 2018
** read_functions.c
** File description:
** read an entire file and put it in an str
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "sokoban.h"
#include "malloc.h"

void my_error(char const *filepath)
{
    write(2, "sokoban: ", 9);
    write(2, filepath, my_strlen(filepath));
    write(2, ": No such file\n", 15);
}

int my_file_size(char const *filepath)
{
    struct stat stat_s;

    stat(filepath, &stat_s);
    return (stat_s.st_size);
}

char *my_file_readall(char const *filepath)
{
    int fd;
    int size = my_file_size(filepath);
    char *buffer = safe_malloc_char(sizeof(char) * (size + 1));

    fd = open(filepath, O_RDONLY);
    if (fd == -1){
        my_error(filepath);
        exit(84);
    }
    read(fd, buffer, size);
    buffer[size] = '\0';
    close(fd);
    return (buffer);
}