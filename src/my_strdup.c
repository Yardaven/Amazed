/*
** EPITECH PROJECT, 2023
** Strdup
** File description:
** duplicates a string
*/
#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    char *str;
    int l = my_strlen(src);

    str = malloc(sizeof(char) * l + 1);
    my_strcpy(str, src);
    return (str);
}
