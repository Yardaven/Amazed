/*
** EPITECH PROJECT, 2024
** remove room
** File description:
** remove room
*/

#include "include.h"

void free_room(room_t *room)
{
    free(room->id);
    free(room);
}

void remove_room(gen_t *gen, amazed_t *amazed)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(gen->window);
    room_t *room = get_room_from_pos(pos, amazed);
    int len = 0;
    int index = 0;

    if (!room)
        return;
    if (strcmp(room->id, amazed->start_id) == 0 || strcmp(room->id, amazed->end_id) == 0)
        return;
    gen->released = 0;
    if (amazed->room_info != NULL)
        for (int i = 0; amazed->room_info[i]; i++)
            if (strcmp(amazed->room_info[i]->id, room->id) != 0)
                len++;
    room_t **room_info = malloc(sizeof(room_t *) * (len + 2));
    if (amazed->room_info != NULL) {
        for (int i = 0; amazed->room_info[i]; i++) {
            if (strcmp(amazed->room_info[i]->id, room->id) == 0)
                continue;
            room_info[index] = amazed->room_info[i];
            index++;
        }
        room_info[index] = NULL;
    }
    free_room(room);
    amazed->room_info = room_info;
}