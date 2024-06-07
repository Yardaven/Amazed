/*
** EPITECH PROJECT, 2023
** Parser.c
** File description:
** sucreeeh et parsing
*/

#include "path.h"

int get_dist(room_t *p1, room_t *p2)
{
    int a = p2->x - p1->x;
    int b = p2->y - p1->y;

    if (a < 0)
        a = a * -1;
    if (b < 0)
        b = b * -1;
    return a + b;
}

void mininit(map_t *map)
{
    map->nb_end = 0;
    map->nb_start = 0;
    map->inc = 0;
    map->num = 1;
    map->ret_val = 0;
    map->size = -1;
}

void get_end_and_start(map_t *map, char **content)
{
    char *line = NULL;
    char **tab = NULL;

    for (int i = 0; content[i + 1]; i++) {
        line = my_strdup(content[i + 1]);
        tab = my_str_to_array(line, " \t");
        if (my_strcmp(content[i], "##start") == 0) {
            map->id_start = my_strdup(tab[0]);
            map->nb_start += 1;
        }
        if (my_strcmp(content[i], "##end") == 0) {
            map->id_end = my_strdup(tab[0]);
            map->nb_end += 1;
        }
    }
    map->ret_val = map->nb_start == 1 ? map->ret_val : 84;
    map->ret_val = map->nb_end == 1 ? map->ret_val : 84;
}

int get_room_total_number(char **content)
{
    char *line = NULL;
    char **tab = NULL;
    int nb = 0;

    for (int i = 0; content[i]; i++) {
        line = my_strdup(content[i]);
        tab = my_str_to_array(line, " \t");
        if (tab_len(tab) < 3) {
            mini_cleaner(tab, line);
            continue;
        }
        nb++;
        mini_cleaner(tab, line);
    }
    return nb;
}

static char *get_line_wo_comment(char **tab)
{
    char *res = "";

    res = my_strcat(res, tab[0], "");
    for (int i = 0; tab[i + 1]; i++) {
        if (tab[i + 1][0] == '#')
            return res;
        res = my_strcat(res, tab[i + 1], " ");
    }
    return res;
}

static char **clean_content(char **content)
{
    char **new = malloc(sizeof(char *) * (tab_len(content) + 1));
    int index = 0;
    char *tmp = NULL;
    char **tmp_tab = NULL;
    char *res = NULL;

    for (int i = 0; content[i]; i++) {
        tmp = my_strdup(content[i]);
        tmp_tab = my_str_to_array(tmp, " ");
        res = get_line_wo_comment(tmp_tab);
        if (res[0] == '#' && res[1] != '#')
            continue;
        new[index] = my_strdup(res);
        index++;
        free(res);
        mini_cleaner(tmp_tab, tmp);
    }
    new[index] = NULL;
    return new;
}

map_t *parser(void)
{
    char *line = NULL;
    size_t size = 0;
    char *file_content = "";
    char **content = NULL;

    while (getline(&line, &size, stdin) >= 0){
        file_content = my_strcat(file_content, line, "");
    }
    content = my_str_to_array(file_content, "\n");
    content = clean_content(content);
    return parser_aux(content);
}
