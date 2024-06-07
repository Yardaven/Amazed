/*
** EPITECH PROJECT, 2023
** is_s_prec
** File description:
** is_s_prec
*/
#include "my.h"

int is_s_prec(char *str, int prec)
{
    int i = 0;

    if (my_strlen(str) < prec){
        my_putchar('\0');
        return (0);
    }
    while (i < prec){
        my_putchar(str[i]);
        i += 1;
    }
    return (i);
}
