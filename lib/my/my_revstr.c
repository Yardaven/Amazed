/*
** EPITECH PROJECT, 2023
** MY_REV_STR
** File description:
** return the string in parameter reversed
*/
#include "my.h"

char *my_revstr(char *str)
{
    char temp;
    int s = 0;
    int e = my_strlen(str) - 1;

    while (s < e) {
        temp = str[s];
        str[s] = str[e];
        str[e] = temp;
        s = s + 1;
        e = e - 1;
    }
    return (str);
}
