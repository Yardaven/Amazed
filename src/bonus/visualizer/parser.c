/*
** EPITECH PROJECT, 2024
** parser
** File description:
** parser
*/

#include "include.h"

char **get_content()
{
    char *str = NULL;
    size_t size = 0;
    char *res = "";
    char **content = NULL;

    while (getline(&str, &size, stdin) != -1)
        res = my_strcat(res, str, "");
    return my_str_to_array(res, "\n");
}

void mini_cleaner(char **tab, char *str)
{
    for (int i = 0; tab[i]; free(tab[i++]));
    free(str);
    free(tab);
}

room_t **get_rooms(gen_t *gen, char **content)
{
    int len = 0;
    int i = 0;
    int j = 0;
    char **tab = NULL;
    int index = 0;
    room_t **rooms;
    char *line;
    sfVector2f pos;
    room_t *start_room;
    char **tmp_tab;

    while(strcmp(content[i], "#rooms") != 0)
        i++;
    j = i + 1;
    for (i; content[i]; i++) {
        if (strcmp("##end", content[i]) == 0 || strcmp("##start", content[i]) == 0)
            continue;
        if (strcmp("#tunnels", content[i]) == 0)
            break;
        len++;
    }
    rooms = malloc(sizeof(room_t *) * len);
    for (;content[j]; j++) {
        if (strcmp("#tunnels", content[j]) == 0)
            break;
        if (strcmp("##end", content[j]) == 0)
            continue;
        if (strcmp("##start", content[j]) == 0) {
            line = strdup(content[j + 1]);
            tmp_tab = my_str_to_array(line, " ");
            gen->id_start = strdup(tmp_tab[0]);
            pos.x = atoi(tmp_tab[1]);
            pos.y = atoi(tmp_tab[2]);
            gen->start_pos = pos;
            continue;
        }
        line = strdup(content[j]);
        tmp_tab = my_str_to_array(line, " ");
        rooms[index] = malloc(sizeof(room_t));
        rooms[index]->id = strdup(tmp_tab[0]);
        rooms[index]->x = atoi(tmp_tab[1]);
        rooms[index]->y = atoi(tmp_tab[2]);
        index++;
        mini_cleaner(tmp_tab, line);
    }
    rooms[index] = NULL;
    return rooms;
}

int get_nb_robots(char **content)
{
    int nb = 0;

    for (int i = 0; content[i + 1]; i++)
        if (strcmp("#number_of_robots", content[i]) == 0)
            return atoi(content[i + 1]);
    return 0;
}

char **get_moves(char **content)
{
    int i = 0;
    int j = 0;
    int len = 0;
    int index = 0;
    char **tab = NULL;

    for (; content[i]; i++)
        if (strcmp(content[i], "#moves") == 0)
            break;
    i++;
    j = i;
    for (i; content[i]; i++) {
        len++;
    }
    tab = malloc(sizeof(char *) * len);
    for (;content[j]; j++) {
        tab[index++] = strdup(content[j]);
    }
    tab[index] = NULL;
    return tab;
}

char **get_tunnels(char **content)
{
    int len = 0;
    int i = 0;
    int j = 0;
    char **tab = NULL;
    int index = 0;

    while(strcmp(content[i], "#tunnels") != 0)
        i++;
    j = i + 1;
    for (i; content[i]; i++) {
        if (strcmp("#moves", content[i]) == 0)
            break;
        len++;
    }
    tab = malloc(sizeof(char *) * len);
    for (;content[j]; j++) {
        if (strcmp("#moves", content[j]) == 0)
            break;
        tab[index++] = strdup(content[j]);
    }
    tab[index] = NULL;
    return tab;
}

void parser(gen_t *gen, char **content)
{    
    gen->nb_robots = get_nb_robots(content);
    gen->tunnels = get_tunnels(content);
    gen->moves = get_moves(content);
    gen->rooms = get_rooms(gen, content);
    return;
}
