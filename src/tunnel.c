/*
** EPITECH PROJECT, 2023
** tunnel.c
** File description:
** sucreeeh et parsing
*/

#include "path.h"

void connect_room(room_t *room_1, room_t *room_2)
{
    int i = 0;

    if (my_strcmp(room_1->id, room_2->id) == 0)
        return;
    for (i = 0; room_1->next[i]; i++);
    room_1->next[i] = room_2;
    for (i = 0; room_2->next[i]; i++);
    room_2->next[i] = room_1;
}

void connect_all_rooms(map_t *map)
{
    room_t *room_1 = NULL;
    room_t *room_2 = NULL;
    char *line = NULL;
    char **tab = NULL;

    for (int i = 0; map->tunnels[i]; i++) {
        line = my_strdup(map->tunnels[i]);
        tab = my_str_to_array(line, "-");
        room_1 = get_room_from_id(map, tab[0]);
        room_2 = get_room_from_id(map, tab[1]);
        if (!room_1 || !room_2)
            continue;
        connect_room(room_1, room_2);
    }
}

static int is_correct_tunnel(char *line)
{
    char *tunnel_line = NULL;
    char **tunnel_tab = NULL;
    int nb = 0;

    tunnel_line = my_strdup(line);
    tunnel_tab = my_str_to_array(tunnel_line, "-");
    if (tab_len(tunnel_tab) == 2)
        nb++;
    mini_cleaner(tunnel_tab, tunnel_line);
    return nb;
}

int get_nb_tunnel(char **content)
{
    char *line = NULL;
    char **tab = NULL;
    int nb = 0;

    for (int i = 0; content[i]; i++) {
        line = my_strdup(content[i]);
        tab = my_str_to_array(line, " \t");
        if (tab_len(tab) != 1) {
            mini_cleaner(tab, line);
            continue;
        }
        nb += is_correct_tunnel(tab[0]);
        mini_cleaner(tab, line);
    }
    return nb;
}

static int get_tunnel_bis(map_t *map, char *content, char *line, int index)
{
    char *tunnel_line = NULL;
    char **tunnel_tab = NULL;

    tunnel_line = my_strdup(content);
    tunnel_tab = my_str_to_array(tunnel_line, "-");
    if (tab_len(tunnel_tab) == 2) {
        map->tunnels[index] = my_strdup(line);
        index++;
    }
    mini_cleaner(tunnel_tab, tunnel_line);
    return index;
}

void get_tunnel(map_t *map, char **content)
{
    char *line = NULL;
    char **tab = NULL;
    int index = 0;

    if (get_nb_tunnel(content) == 0) {
        map->tunnels = NULL;
        return;
    }
    map->tunnels = malloc(sizeof(char *) * (get_nb_tunnel(content) + 1));
    for (int i = 0; content[i]; i++) {
        line = my_strdup(content[i]);
        tab = my_str_to_array(line, " \t");
        if (tab_len(tab) != 1) {
            mini_cleaner(tab, line);
            continue;
        }
        index = get_tunnel_bis(map, tab[0], content[i], index);
        mini_cleaner(tab, line);
    }
}
