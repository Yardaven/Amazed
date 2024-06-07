/*
** EPITECH PROJECT, 2023
** MY_PUT_FLOAT
** File description:
** display a float number
*/
#include <stdio.h>
#include "my.h"

int nbr_len(int nb)
{
    int l = 0;

    while (nb != 0) {
        nb /= 10;
        l += 1;
    }
    return l;
}

double is_nbr_neg_fl(double nb)
{
    if (nb < 0){
        my_putchar('-');
        nb = nb * (-1);
    }
    return (nb);
}

int print_res_fl(long nb, long div, int len, int tmp)
{
    int i = 0;
    int last = nb % 10;
    long nbr = 0;
    int is_dot = 0;

    if (last > 5)
        nb += 10;
    while (div >= 1 && tmp != 0){
        nbr = nb / div;
        if (i == len) {
            my_putchar('.');
            is_dot += 1;
        }
        my_putchar(nbr + 48);
        nb = nb % div;
        div = div / 10;
        i += 1;
        tmp -= 1;
    }
    return (is_dot);
}

int my_put_float(double n)
{
    int len = nbr_len((int)n);
    long nbr = n * 10000000;
    long cpy = nbr;
    long d = 1;
    int l = -1;
    int tmp;

    cpy = is_nbr_neg_fl(cpy);
    while (nbr != 0) {
        nbr = nbr / 10;
        l = l + 1;
    }
    tmp = l;
    while (l != 0) {
        if (n == 0)
            break;
        d = d * 10;
        l = l - 1;
    }
    return (print_res_fl(cpy, d, len, tmp) + tmp);
}
