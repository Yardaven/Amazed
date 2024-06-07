/*
** EPITECH PROJECT, 2024
** error
** File description:
** error
*/

#include "path.h"

void mini_cleaner(char **tab, char *str)
{
    for (int j = 0; tab[j]; j++)
        free(tab[j]);
    free(tab);
    free(str);
}

static int check_if_room_has_twin_pos(map_t *map, int index)
{
    for (int j = 0; map->room[j]; j++) {
        if (index == j)
            continue;
        if ((map->room[j]->x == map->room[index]->x) &&
        (map->room[j]->y == map->room[index]->y))
            return 0;
    }
    return 1;
}

static int check_if_room_has_twin_id(map_t *map, int index)
{
    for (int j = 0; map->room[j]; j++) {
        if (index == j)
            continue;
        if (my_strcmp(map->room[j]->id, map->room[index]->id) == 0)
            return 0;
    }
    return 1;
}

int check_twins(map_t *map)
{
    if (map->room == NULL)
        return 0;
    for (int i = 0; map->room[i]; i++) {
        if (!check_if_room_has_twin_id(map, i))
            return 0;
        if (!check_if_room_has_twin_pos(map, i))
            return 0;
    }
    return 1;
}

int check_primary_room(map_t *map)
{
    int len = 0;

    if (map->ret_val != 0)
        return 0;
    if (!map->id_start || !map->id_end)
        return 0;
    if (map->nb_start != 1 || map->nb_end != 1)
        return 0;
    if (map->room[map->start]->next)
        for (int i = 0; map->room[map->start]->next[i]; i++) {
            len++;
        }
    if (len == 0)
        return 0;
    return 1;
}

int error_handling(map_t *map)
{
    char *tmp = malloc(sizeof(char) * 1);
    char **tmp_tab = malloc(sizeof(char *) * 1);

    if (!check_primary_room(map) || !check_twins(map))
        return 0;
    if (map->tunnels == NULL)
        return 0;
    for (int i = 0; map->tunnels[i]; i++) {
        mini_cleaner(tmp_tab, tmp);
        tmp = my_strdup(map->tunnels[i]);
        tmp_tab = my_str_to_array(tmp, "-");
        if (!get_room_from_id(map, tmp_tab[0]))
            return 0;
        if (!get_room_from_id(map, tmp_tab[1]))
            return 0;
    }
    mini_cleaner(tmp_tab, tmp);
    return 1;
}
