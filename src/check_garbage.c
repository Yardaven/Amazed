/*
** EPITECH PROJECT, 2024
** check garbage
** File description:
** check garbage
*/

#include "path.h"

int check_room_entry(char **tab, map_t *map)
{
    int current_ret_val = map->ret_val;

    map->ret_val = 84;
    if (my_strlen(tab[0]) == 0)
        return 0;
    if (tab_len(tab) != 1 && tab_len(tab) != 3)
        return 0;
    if (tab_len(tab) == 3)
        if (!my_str_isnum(tab[1]) || !my_str_isnum(tab[1]))
            return 0;
    map->ret_val = current_ret_val;
    return 1;
}

int check_pipe_entry(char **tab, map_t *map)
{
    int current_ret_val = map->ret_val;

    map->ret_val = 84;
    if (tab_len(tab) == 1) {
        if (my_strcmp(tab[0], "##end") != 0 &&
        my_strcmp(tab[0], "##start") != 0)
            return 0;
    }
    if (tab_len(tab) > 2)
        return 0;
    map->ret_val = current_ret_val;
    return 1;
}

int is_garbage(char *line, map_t *map)
{
    char **tab = my_str_to_array(line, " \t\n");
    char *tmp2;
    char **tab2;

    if (tab_len(tab) == 0)
        return 1;
    tmp2 = my_strdup(tab[0]);
    tab2 = my_str_to_array(tmp2, "-");
    if (line[0] == '#' && line[1] != '#')
        return 0;
    if (!check_room_entry(tab, map))
        return 1;
    if (tab_len(tab) == 1) {
        if (my_str_isnum(tab[0]))
            return 0;
        if (!check_pipe_entry(tab2, map))
            return 1;
    }
    return 0;
}
