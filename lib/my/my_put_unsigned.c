/*
** EPITECH PROJECT, 2023
** MY_PUT_NBR
** File description:
** display number
*/
#include "my.h"

void print_unsigned(unsigned int nb, int div, unsigned int nbr)
{
    while (div >= 1){
        nbr = nb / div;
        my_putchar(nbr + 48);
        nb = nb % div;
        div = div / 10;
    }
}

int my_put_unsigned(unsigned int n)
{
    unsigned int nbr = n;
    int d = 1;
    int l = -1;
    int tmp;

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
    print_unsigned(n, d, nbr);
    return (tmp + 1);
}
