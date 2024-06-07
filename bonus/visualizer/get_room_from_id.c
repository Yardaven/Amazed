/*
** EPITECH PROJECT, 2024
** get room
** File description:
** get room
*/

#include "include.h"

room_t *get_room_from_id(char *id, gen_t *gen)
{
    if (gen->rooms)
        for (int i = 0; gen->rooms[i]; i++)
            if (strcmp(gen->rooms[i]->id, id) == 0) {
                return gen->rooms[i];
            }
    return NULL;
}

room_t *get_room_from_pos(sfVector2i pos, gen_t *gen)
{
    sfVector2i room_pos;

    if (gen->rooms)
        for (int i = 0; gen->rooms[i]; i++) {
            room_pos = (sfVector2i){gen->rooms[i]->x, gen->rooms[i]->y};
            if (get_distance(room_pos, pos) <= 30)
                return gen->rooms[i];
        }
    return NULL;
}
