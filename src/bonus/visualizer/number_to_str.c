/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "include.h"

void boucle(int m, int p, char *str)
{
    int diff = m - p;
    int temp1;
    int temp2;

    while (diff >= 1) {
        temp1 = str[m];
        temp2 = str[p];
        str[m] = temp2;
        str[p] = temp1;
        m -= 1;
        p += 1;
        diff = m - p;
    }
}

char *my_revstr(char *str)
{
    int m = 0;
    int p = 0;

    while (str[m] != '\0') {
        m += 1;
    }
    m -= 1;
    boucle(m, p, str);
    return (str);
}

int my_nb_digits(long long int nb)
{
    long long int nb1 = nb;
    long long int div = 1;
    int counter = 0;

    if (nb1 < 0) {
        nb1 = nb1 * (-1);
        nb = nb * (-1);
    }
    while (nb1 > 9) {
        nb1 /= 10;
        div *= 10;
    }
    while (div >= 1) {
        nb1 = nb / div;
        counter += 1;
        nb %= div;
        div /= 10;
    }
    return (counter);
}

char *my_number_to_str(int nb)
{
    int i = 0;
    char *str;
    int loop = my_nb_digits(nb);

    str = malloc(sizeof(char) * (my_nb_digits(nb) + 1));
    while (loop > 0) {
        str[i] = nb % 10 + '0';
        i += 1;
        nb /= 10;
        loop -= 1;
    }
    str[i] = '\0';
    my_revstr(str);
    return str;
}
