/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include "include.h"

int char_is_delim(char c, char *delim)
{
    for (int i = 0; delim[i] != '\0'; i++)
        if (c == delim[i]) {
            return 1;
            break;
        }
    return 0;
}

int str_is_delim(char *str, char *delim)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!char_is_delim(str[i], delim)) {
            return 0;
            break;
        }
    }
    return 1;
}

int count_n_word(char *str, char *delim)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (char_is_delim(str[i], delim) && !char_is_delim(str[i + 1], delim))
            count++;
    }
    return count + 1;
}

char **my_str_to_array(char *str, char *delim)
{
    char *save = NULL;
    char *item;
    char **tab = NULL;
    int n_word = 0;
    int i = 0;

    if (!str)
        return NULL;
    n_word = count_n_word(str, delim);
    tab = malloc(sizeof(char *) * (n_word + 2));
    item = strtok_r(str, delim, &save);
    while (item != NULL) {
        tab[i] = strdup(item);
        i++;
        item = strtok_r(NULL, delim, &save);
    }
    tab[i] = NULL;
    return tab;
}
