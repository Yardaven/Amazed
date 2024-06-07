/*
** EPITECH PROJECT, 2024
** fileread
** File description:
** fileread
*/

#include "include.h"

char *fileread(char *filepath)
{
    struct stat s;
    int fd = open(filepath, O_RDONLY);
    char *str;

    stat(filepath, &s);
    str = malloc(sizeof(char) * s.st_size);
    read(fd, str, s.st_size);
    str[s.st_size] = '\0';
    close(fd);
    return str;
}
