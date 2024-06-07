/*
** EPITECH PROJECT, 2023
** my_putchar
** File description:
** print a char without the use of print
*/
#include <unistd.h>
#include "my.h"

int my_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}
