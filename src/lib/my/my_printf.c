/*
** EPITECH PROJECT, 2023
** MINI_PRINTF
** File description:
** reproduce the behavior of simpler printf
*/
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int sub_dot(const char *format, va_list ap, int i)
{
    if (format[i] == '%' && format[i + 1] == '.'
        && format[i + (1 + float_len(format, i))] == 'f') {
        return my_put_float_prec
            (re_value(format, float_len(format, i), i), va_arg(ap, double));
    }
    if (format[i] == '%' && format[i + 1] == '.'
        && format[i + (1 + float_len(format, i))] == 's') {
        return is_s_prec
            (va_arg(ap, char *), re_value(format, float_len(format, i), i));
    }
    return (0);
}

int sub_condition(const char *format, va_list ap, int i)
{
    if (format[i] == '%' && format[i + 1] == 'X')
        return (conv_hexa(va_arg(ap, int), "0123456789ABCDEF"));
    if (format[i] == '%' && format[i + 1] == 'x')
        return (conv_hexa(va_arg(ap, int), "0123456789abcdef"));
    if (format[i] == '%' && format[i + 1] == 'p')
        return (my_put_pointer(va_arg(ap, unsigned long)));
    if (format[i] == '%' && format[i + 1] == 'o')
        return (decioctal(va_arg(ap, unsigned long)));
    if (format[i] == '%' && format[i + 1] == 'f')
        return (my_put_float(va_arg(ap, double)));
    if (format[i] == '%' && format[i + 1] == '+')
        return (is_sign(va_arg(ap, int)));
    if (format[i] == '%' &&
        (format[i + 1] == 'e' || format[i + 1] == 'E'))
        return exponant(va_arg(ap, double), format[i + 1]);
    if (format[i] == '%' && format[i + 1] == 'u')
        return (my_put_unsigned(va_arg(ap, unsigned int)));
    return 0;
}

int print_aux(const char *format, va_list ap, int i, int count)
{
    if (format[i] == '%' && format[i + 1] == 'c')
        return (my_putchar(va_arg(ap, int)));
    if (format[i] == '%' &&
        (format[i + 1] == 'i' || format[i + 1] == 'd'))
        return (my_put_nbr(va_arg(ap, int)));
    if (format[i] == '%' && format[i + 1] == 's')
        return (my_putstr(va_arg(ap, char *)));
    if (format[i] == '%' && format[i + 1] == '%')
        return (my_putchar('%'));
    return (sub_condition(format, ap, i));
}

void print_char(int val, char const *format, int i)
{
    if (val == 0) {
        my_putchar(format[i]);
    }
}

int my_printf(const char *format, ...)
{
    va_list ap;
    int count;

    va_start(ap, format);
    count = loop(format, ap, 0, 0);
    va_end(ap);
    return (count);
}
