/*
** EPITECH PROJECT, 2024
** parser setup
** File description:
** parser setup
*/

#include "path.h"


room_t *init_room(map_t *map, char **tab)
{
    room_t *room = malloc(sizeof(room_t));

    if (!my_str_isnum(tab[1]) || !my_str_isnum(tab[2]))
        map->ret_val = 84;
    room->id = my_strdup(tab[0]);
    room->x = my_getnbr(tab[1]);
    room->y = my_getnbr(tab[2]);
    room->next = NULL;
    room->busy = 0;
    return room;
}

void get_basic_room_info(map_t *map, char **content)
{
    char *line = NULL;
    char **tab = NULL;
    int index = 0;

    map->room = malloc(sizeof(room_t *) *
    (get_room_total_number(content) + 1));
    for (int i = 0; content[i]; i++) {
        line = my_strdup(content[i]);
        tab = my_str_to_array(line, " \t");
        if (tab_len(tab) == 3) {
            map->room[index] = init_room(map, tab);
            mini_cleaner(tab, line);
            index++;
        } else
            mini_cleaner(tab, line);
    }
    map->room[index] = NULL;
}

void get_robot_nb(map_t *map, char **content)
{
    char *line = NULL;
    char **tab = NULL;
    int nb = 0;

    for (int i = 0; content[i]; i++) {
        line = my_strdup(content[i]);
        tab = my_str_to_array(line, " \t-");
        if (tab_len(tab) != 1)
            continue;
        if (!my_str_isnum(tab[0]))
            continue;
        map->size = my_getnbr(tab[0]);
        nb++;
    }
    map->ret_val = nb == 1 ? map->ret_val : 84;
}

static int get_nb_connections(map_t *map, char *room_id)
{
    char *line = NULL;
    char **tab = NULL;
    int nb = 0;

    for (int i = 0; map->tunnels[i]; i++) {
        line = my_strdup(map->tunnels[i]);
        tab = my_str_to_array(line, "-");
        if (my_strcmp(tab[0], room_id) == 0 ||
        my_strcmp(tab[1], room_id) == 0)
            nb++;
    }
    return nb;
}

static void get_advanced_room_info(map_t *map)
{
    if (map->tunnels == NULL)
        return;
    for (int i = 0; map->room[i]; i++) {
        map->room[i]->next = malloc(sizeof(room_t *) *
        (get_nb_connections(map, map->room[i]->id) + 1));
    }
    connect_all_rooms(map);
}

static void setup_start_end_index(map_t *map)
{
    if (!map->id_end || !map->id_start)
        return;
    for (int i = 0; map->room[i]; i++) {
        if (my_strcmp(map->room[i]->id, map->id_start) == 0)
            map->start = i;
        if (my_strcmp(map->room[i]->id, map->id_end) == 0)
            map->end = i;
    }
}

static void setup_dist(map_t *map)
{
    for (int i = 0; map->room[i]; i++) {
        map->room[i]->room_i = i;
        map->room[i]->dist = get_dist(map->room[i], map->room[map->end]);
        map->room[i]->s_dist = get_dist(map->room[i], map->room[map->start]);
        map->room[i]->tot = map->room[i]->dist + map->room[i]->s_dist;
    }
}

map_t *parser_aux(char **content)
{
    map_t *map = malloc(sizeof(map_t));

    for (int i = 0; content[i]; i++)
        if (is_garbage(content[i], map))
            return map;
    mininit(map);
    get_end_and_start(map, content);
    get_basic_room_info(map, content);
    get_tunnel(map, content);
    get_robot_nb(map, content);
    get_advanced_room_info(map);
    setup_start_end_index(map);
    setup_dist(map);
    return map;
}
