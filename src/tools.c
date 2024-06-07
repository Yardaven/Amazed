/*
** EPITECH PROJECT, 2023
** Parser.c
** File description:
** sucreeeh et parsing
*/

int tab_len(char **tab)
{
    int i = 0;

    for (; tab[i]; i++);
    return i;
}
