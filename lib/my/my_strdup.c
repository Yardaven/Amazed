/*
** EPITECH PROJECT, 2023
** Strdup
** File description:
** duplicates a string
*/
#include <stdlib.h>
#include "../../my.h"

char *my_strdup(const char *src)
{
    char *dest = malloc(sizeof(char) * my_strlen(src) + 1);

    if (dest != NULL)
        my_strcpy(dest, src);
    return dest;
}
