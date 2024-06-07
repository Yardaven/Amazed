/*
** EPITECH PROJECT, 2023
** Decioctal
** File description:
** Decimal to octal conversion
*/
#include "my.h"
#include <stdlib.h>

int decioctal(unsigned long nb)
{
    int i = 0;
    unsigned long copy = nb;
    char *oct = "01234567";
    char *res;

    while (nb != 0){
        nb = nb / 10;
        i += 1;
    }
    res = malloc(sizeof(char *) * (i + 1));
    i = 0;
    do {
        nb = copy % 8;
        copy = copy / 8;
        res[i] = oct[nb];
        i += 1;
    }while (copy != 0);
    my_revstr(res);
    my_putstr(res);
    return (i);
}
