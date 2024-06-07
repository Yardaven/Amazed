/*
** EPITECH PROJECT, 2023
** EXPONANT
** File description:
** write a double in scientific writing
*/
#include "my.h"
#include <stdarg.h>

int nb_len(int nb)
{
    int l = 0;

    if (nb < 0)
        nb *= -1;
    while (nb > 0) {
        l += 1;
        nb /= 10;
    }
    return l;
}

int exponant(double fl, char c)
{
    int int_len = nb_len((int)fl);
    int i = 0;
    int length = 1;

    if (fl == 0)
        return (my_printf("0.000000%c+00", c));
    while (int_len > 1) {
        fl /= 10.0;
        int_len = nb_len((int)fl);
        i += 1;
    }
    length += my_put_float(fl);
    my_putchar(c);
    my_putstr("+");
    if (i < 10) {
        my_putchar('0');
        length += 1;
    }
    length += my_put_nbr(i);
    return length + 1;
}
