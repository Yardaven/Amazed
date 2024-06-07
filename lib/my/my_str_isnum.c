/*
** EPITECH PROJECT, 2023
** isnum
** File description:
** isnum
*/

#include "my.h"
#include <stddef.h>

int my_isnum(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

int my_str_isnum(char *str)
{
    if (my_strlen(str) == 0)
        return 0;
    for (int i = 0; str[i]; i++) {
        if (!my_isnum(str[i]))
            return 0;
    }
    return 1;
}
