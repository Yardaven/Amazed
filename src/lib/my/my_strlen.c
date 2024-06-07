/*
** EPITECH PROJECT, 2023
** MY_STRLEN
** File description:
** counts the the number of character of a string
*/
#include "my.h"
#include <stdlib.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    for (; str[i] != '\0'; i++);
    return (i);
}
