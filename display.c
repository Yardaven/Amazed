/*
** EPITECH PROJECT, 2023
** AMAZED
** File description:
** Pathfinding functions, moving robots
*/
#include "my.h"
#include "path.h"

void disp_rooms(map_t *map)
{
    my_printf("#number_of_robots\n%d\n", map->size);
    my_printf("#rooms\n");
    for (int i = 0; map->room[i]; i++){
        if (my_strcmp(map->room[i]->id, map->id_start) == 0) {
            my_printf("##start\n");
        }
        if (my_strcmp(map->room[i]->id, map->id_end) == 0) {
            my_printf("##end\n");
        }
        my_printf("%s %d %d\n", map->room[i]->id,
            map->room[i]->x, map->room[i]->y);
    }
    my_printf("#tunnels\n");
    for (int i = 0; map->tunnels[i]; i++){
        my_printf("%s\n", map->tunnels[i]);
    }
    my_printf("#moves\n");
}

void display(map_t *map)
{
    disp_rooms(map);
}
