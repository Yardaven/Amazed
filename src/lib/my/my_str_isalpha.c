/*
** EPITECH PROJECT, 2023
** my_strncmp
** File description:
** compares the value of two strings
*/
#include <unistd.h>
#include <stdlib.h>
#include "my.h"


int test_firt_char(char c)
{
    if (!(c == '.' || (c >= 'a'
        && c <= 'z') || (c >= 'A'
        && c <= 'Z') || (c >= '0'
        && c <= '9') || c == '_'))
        return 1;
    return 0;
}

int my_str_isalpha(char const *str)
{
    if (my_strlen(str) == 0)
        return 1;
    if (test_firt_char(str[0])) {
        write(2, "setenv: Variable name must begin with a letter.\n", 49);
        return 1;
    }
    for (int i = 0; str[i]; i++) {
        if (!(str[i] == '.' || (str[i] >= 'a'
        && str[i] <= 'z') || (str[i] >= 'A'
        && str[i] <= 'Z') || (str[1] >= '0'
        && str[1] <= '9') || str[i] == '_')) {
            write(2, "setenv: Variable name must ", 27);
            write(2, "contain alphanumeric characters.\n", 33);
            return 1;
        }
    }
    return 0;
}
