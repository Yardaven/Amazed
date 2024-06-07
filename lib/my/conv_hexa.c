/*
** EPITECH PROJECT, 2023
** convert an interger into hexadecimal
** File description:
** CONV_HEXA
*/
#include <stdlib.h>
#include "my.h"

char *rem_zero(char *tab)
{
    int i = 0;

    while (tab[i] == '0') {
        tab[i] = 127;
        i += 1;
    }
    return (tab);
}

int nbr_zero(char *tab)
{
    int i = 0;

    my_revstr(tab);
    while (tab[i] == '0') {
        i += 1;
    }
    return (i);
}

int d_len(unsigned long nb)
{
    int l;

    while (nb != 0) {
        nb = nb / 10;
        l += 1;
    }
    return (l);
}

int conv_hexa(unsigned long nb, char const *hex)
{
    char *tab;
    int i = 0;
    int l = d_len(nb);
    unsigned long reste = 0;

    tab = malloc(sizeof(char *) * (l + 1));
    do {
        reste = nb % 16;
        nb = nb / 16;
        tab[i] = hex[reste];
        l -= 1;
        i += 1;
    } while (l > 0);
    tab[i] = '\0';
    l = i - nbr_zero(tab);
    my_putstr(rem_zero(tab));
    return (l);
}
