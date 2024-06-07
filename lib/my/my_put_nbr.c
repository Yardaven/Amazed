/*
** EPITECH PROJECT, 2023
** MY_PUT_NBR
** File description:
** display number
*/
#include "my.h"

int plus_one(int nb)
{
    if (nb <= 0){
        return 1;
    }
    return 0;
}

int is_nbr_neg(int nb)
{
    if (nb < 0){
        my_putchar('-');
        nb = nb * (-1);
    }
    return (nb);
}

int print_res(int nb, int div, int nbr)
{
    while (div >= 1){
        nbr = nb / div;
        my_putchar(nbr + 48);
        nb = nb % div;
        div = div / 10;
    }
}

int my_put_nbr(int n)
{
    int nbr = n;
    int d = 1;
    int l = -1;
    int tmp = plus_one(n);

    n = is_nbr_neg(n);
    while (nbr != 0) {
        nbr = nbr / 10;
        l = l + 1;
    }
    tmp += l;
    while (l != 0) {
        if (n == 0) {
            break;
        }
        d = d * 10;
        l = l - 1;
    }
    print_res(n, d, nbr);
    return (tmp + 1);
}
