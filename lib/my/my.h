/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** header for printf
*/
#include <stdarg.h>

#ifndef MY_H_
    #define MY_H_

int my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int n);
int my_strlen(char const *str);
void is_n(char const *format, int count, int i, va_list ap);
char *my_revstr(char *str);
int my_put_pointer(unsigned long long pointer);
int my_put_float(double n);
int my_put_float_prec(int fl, double nb);
int conv_hexa(unsigned long nb, char const *hex);
int is_sign(int nb);
int decioctal(unsigned long nb);
int float_len(char const *format, int i);
int re_value(char const *format, int len, int i);
int exponant(double fl, char c);
int loop(const char *format, va_list ap, int i, int fl_len);
int my_printf(const char *format, ...);
int print_aux(char const *format, va_list ap, int i, int count);
int sub_dot(char const *format, va_list ap, int i);
void print_char(int val, char const *format, int i);
int is_s_prec(char *str, int prec);
int my_put_unsigned(unsigned int n);

#endif /* MY_H_ */
