/*
** EPITECH PROJECT, 2023
** my_strncmp
** File description:
** compares the value of two strings
*/
#include "my.h"

int nanagram(char const *s1, char const *s2, int limit)
{
    for (int i = 0; i <= limit; i++){
        if (s1[i] != s2[i])
            return 1;
    }
    return 0;
}

int my_strncmp(char const *s1, char const *s2, int limit)
{
    int i = 0;
    int val1 = 0;
    int val2 = 0;

    if (limit > my_strlen(s1) || limit > my_strlen(s2))
        return 84;
    while (i <= limit){
        val1 += s1[i];
        i += 1;
    }
    i = 0;
    while (i <= limit){
        val2 += s2[i];
        i += 1;
    }
    i = val1 - val2;
    if (i == 0)
        i = nanagram(s1, s2, limit);
    return (i);
}
