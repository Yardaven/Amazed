/*
** EPITECH PROJECT, 2023
** getnbr
** File description:
** skibidibob hmdadap
*/
#include "my.h"

int my_getnbr(char const *str)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0'){
        if (str[i] >= '0' && str[i] <= '9')
            nb = nb * 10 + (str[i] - 48);
        i += 1;
    }
    if (str[0] == '-')
        nb *= -1;
    return (nb);
}
