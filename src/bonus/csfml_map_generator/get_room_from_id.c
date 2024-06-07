/*
** EPITECH PROJECT, 2024
** get room
** File description:
** get room
*/

#include "include.h"

room_t *get_room_from_id(char *id, amazed_t *amazed)
{
    if (amazed->room_info)
        for (int i = 0; amazed->room_info[i]; i++)
            if (strcmp(amazed->room_info[i]->id, id) == 0) {
                return amazed->room_info[i];
            }
    return NULL;
}

room_t *get_room_from_pos(sfVector2i pos, amazed_t *amazed)
{
    sfVector2i room_pos;

    if (amazed->room_info)
        for (int i = 0; amazed->room_info[i]; i++) {
            room_pos = (sfVector2i){amazed->room_info[i]->x, amazed->room_info[i]->y};
            if (get_distance(room_pos, pos) <= 30)
                return amazed->room_info[i];
        }
    return NULL;
}
