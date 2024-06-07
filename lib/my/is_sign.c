/*
** EPITECH PROJECT, 2023
** My_sign.c
** File description:
** My_sign.c
*/
#include <stdio.h>
#include "my.h"

int is_sign(int nb)
{
    int len = 0;

    if (nb > 0){
        my_putchar('+');
        len += 1;
    }
    len += my_put_nbr(nb);
    return len;
}
