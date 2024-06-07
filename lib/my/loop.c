/*
** EPITECH PROJECT, 2023
** LOOP
** File description:
** make the loop of the my_printf function
*/
#include <stdarg.h>
#include "my.h"

int loop(const char *format, va_list ap, int i, int fl_len)
{
    int val = 0;
    int count = 0;

    while (format[i] != '\0') {
        val = print_aux(format, ap, i, count);
        fl_len = (sub_dot(format, ap, i));
        if (fl_len > 0) {
            i += (2 + float_len(format, i));
            count += fl_len - 1;
        }
        if (val > 0) {
            count += val - 1;
            i += 1;
        }
        print_char(val, format, i);
        val = 0;
        i += 1;
        count += 1;
    }
    return (count);
}
