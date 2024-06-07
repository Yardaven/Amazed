/*
** EPITECH PROJECT, 2023
** MY_PUT_POINTER
** File description:
** print the pointer of a variable
*/
#include "my.h"

int my_put_pointer(unsigned long long pointer)
{
    my_putstr("0x");
    return (conv_hexa(pointer, "0123456789abcdef") + 2);
}
