/*
** EPITECH PROJECT, 2023
** PARSING
** File description:
** Parsing functions for my_radar
*/
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include <stdio.h>
#include <sys/stat.h>
#include "path.h"

room_t *get_room_from_id(map_t *map, char *id)
{
    for (int i = 0; map->room[i]; i++){
        if (my_strcmp(id, map->room[i]->id) == 0)
            return map->room[i];
    }
    return NULL;
}

int main(void)
{
    map_t *map = parser();
    bot_t **bots = malloc(sizeof(bot_t *) * map->size);

    if (!error_handling(map))
        return 84;
    display(map);
    if (amazed(map, bots) == 0)
        return 84;
    return map->ret_val;
}
