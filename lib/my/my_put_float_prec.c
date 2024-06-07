/*
** EPITECH PROJECT, 2023
** MY_PUT_FLOAT
** File description:
** display a float number
*/
#include <stdio.h>
#include "my.h"

long multiply(long nb)
{
    long res = 1;

    while (nb != 0) {
        res *= 10;
        nb -= 1;
    }
    return res;
}

int nbr_len_prec(int nb)
{
    int l = 0;

    while (nb != 0) {
        nb /= 10;
        l += 1;
    }
    return l;
}

unsigned long long is_nbr_neg_prec(unsigned long long nb)
{
    if (nb < 0){
        my_putchar('-');
        nb = nb * (-1);
    }
    return (nb);
}

int print_res_prec(long nb, long div, int len, int tmp)
{
    int i = 0;
    long nbr = 0;
    int last = nb % 10;

    if (last > 5) {
        nb -= last;
        nb += 10;
    }
    while (div >= 1 && tmp != 0){
        nbr = nb / div;
        if (i == len)
            my_putchar('.');
        my_put_nbr(nbr);
        nb = nb % div;
        div = div / 10;
        i += 1;
        tmp -= 1;
    }
}

int my_put_float_prec(int prec, double n)
{
    long nbr = n * (multiply(prec + 1));
    long cpy = nbr;
    long d = 1;
    int l = -1;
    int tmp;

    cpy = is_nbr_neg_prec(cpy);
    while (nbr != 0) {
        nbr = nbr / 10;
        l = l + 1;
    }
    tmp = l;
    while (l != 0 && n != 0) {
        d = d * 10;
        l = l - 1;
    }
    print_res_prec(cpy, d, nbr_len_prec((int)n), tmp);
    if (prec > 0)
        tmp += 1;
    return (tmp);
}
