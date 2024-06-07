/*
** EPITECH PROJECT, 2024
** my str
** File description:
** to array
*/
#include <stdlib.h>
#include "my.h"

int char_is_delim(char c, char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return 1;
    return 0;
}

int count_n_word(char *str, char *delim)
{
    int nb = 0;

    for (int i = 0; str[i]; i++)
        if (char_is_delim(str[i], delim) &&
        !char_is_delim(str[i + 1], delim))
            nb += 1;
    return nb + 1;
}

void replace_delim(char *str, char *delim)
{
    for (int i = 0; str[i]; i++)
        if (char_is_delim(str[i], delim))
            str[i] = '\0';
}

char **my_str_to_array(char *str, char *delim)
{
    char **tab = malloc(sizeof(char *) * (count_n_word(str, delim) + 1));
    int index = 0;
    char *tmp = my_strdup(str);
    int len = my_strlen(tmp);

    replace_delim(tmp, delim);
    for (int i = 0; i < len;) {
        while (i < len && tmp[i] == '\0')
            i++;
        tab[index] = my_strdup(tmp + i);
        i += my_strlen(tab[index]);
        index++;
        while (i < len && tmp[i] == '\0')
            i++;
    }
    tab[index] = NULL;
    return tab;
}
