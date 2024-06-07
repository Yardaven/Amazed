/*
** EPITECH PROJECT, 2024
** str
** File description:
** str
*/

#include "include.h"

int my_strlen(char *str)
{
    int i = 0;

    if (!str)
        return 0;
    for (; str[i] != '\0'; i++)
        continue;
    return i;
}

int is_str_equal(char *str, char *str1)
{
    if (!str || !str1)
        return 0;
    if (my_strlen(str) != my_strlen(str1))
        return 0;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] != str1[i]) {
            return 0;
            break;
        }
    }
    return 1;
}

int my_tablen(char **tab)
{
    int i = 0;

    if (!tab)
        return 0;
    for (; tab[i] != NULL; i++)
        continue;
    return i;
}

char *my_strdup(char *src)
{
    int i = 0;
    char *str;

    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    while (i < my_strlen(src)) {
        str[i] = src[i];
        i += 1;
    }
    str[i] = '\0';
    return (str);
}
