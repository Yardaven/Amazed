/*
** EPITECH PROJECT, 2024
** put
** File description:
** put
*/
#include "include.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

void my_putnbr(int nb)
{
    if (nb <= 9)
        my_putchar(nb + '0');
    else {
        my_putnbr(nb / 10);
        my_putchar(nb % 10 + '0');
    }
}

void my_put(void *pointer, char type, int nb)
{
    char **tab = pointer;
    char *c = pointer;

    if (type == 'c')
        my_putchar(*c);
    if (type == 's')
        my_putstr((char *)pointer);
    if (type == 'd')
        my_putnbr(nb);
    if (type == 'S')
        for (int i = 0; tab[i] != NULL; i++){
            my_put(tab[i], 's', 0);
            my_put("\n", 'c', 0);
        }
}
