/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** Concatenates two strings
*/
#include "my.h"

char *my_strcat(char *dest, char const *src, char *sep)
{
    char *res = malloc(sizeof(char) * (my_strlen(dest) +
    my_strlen(src) + 1 + my_strlen(sep)));
    int i = 0;
    int j = 0;

    for (i = 0; dest[i]; i++)
        res[i] = dest[i];
    j = i;
    if (sep != NULL)
        for (i = 0; sep[i]; i++) {
            res[j] = sep[i];
            j++;
        }
    for (i = 0; src[i]; i++) {
        res[j] = src[i];
        j++;
    }
    res[j] = '\0';
    return (res);
}
