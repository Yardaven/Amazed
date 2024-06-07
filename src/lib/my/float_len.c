/*
** EPITECH PROJECT, 2023
** float_nbr
** File description:
** count the nbr between % and f
*/
#include "my.h"

int float_len(char const *format, int i)
{
    int len = 1;

    i += 2;
    while (format[i] != 'f' && format[i] != 's') {
        len += 1;
        i += 1;
    }
    return len;
}

int re_value(char const *format, int len, int i)
{
    int nbr = 0;
    int multi = 1;

    i += 2;
    len -= 2;
    while (len > 0) {
        multi *= 10;
        len -= 1;
    }
    while (format[i] != 'f' && format[i] != 's') {
        nbr += (format[i] - 48) * multi;
        multi /= 10;
        i += 1;
    }
    return nbr;
}
