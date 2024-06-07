/*
** EPITECH PROJECT, 2023
** IS_N
** File description:
** test if the format is %n
*/
#include <stdarg.h>
#include "my.h"

void is_n(char const *format, int count, int i, va_list ap)
{
    if (format[i] == '%' && format[i + 1] == 'n')
        *va_arg(ap, int *) = count;
}
