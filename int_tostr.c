/*
** EPITECH PROJECT, 2023
** Int_tostr
** File description:
** transform an int into an str
*/
#include <stdio.h>
#include <stdlib.h>

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i += 1;
    }
    return i;
}

int count_digits(int n)
{
    int count = 0;

    while (n != 0) {
        n /= 10;
        count += 1;
    }
    return count;
}

char *int_to_str(int n)
{
    int num_len = count_digits(n);
    char *str = (char *)malloc(num_len + 1);

    if (n == 0)
        return "0";
    for (int i = num_len - 1; i >= 0; i -= 1) {
        str[i] = '0' + n % 10;
        n /= 10;
    }
    str[num_len] = '\0';
    return str;
}
