/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** compares the value of two strings
*/
#include "my.h"

int anagram(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] != '\0'; i++){
        if (s1[i] != s2[i])
            return 1;
    }
    return 0;
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int val1 = 0;
    int val2 = 0;

    while (s1[i] != '\0'){
        val1 += s1[i];
        i += 1;
    }
    i = 0;
    while (s2[i] != '\0'){
        val2 += s2[i];
        i += 1;
    }
    i = val1 - val2;
    if (i == 0)
        i = anagram(s1, s2);
    return (i);
}
