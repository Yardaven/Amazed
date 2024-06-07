/*
** EPITECH PROJECT, 2024
** push to room
** File description:
** push to room
*/

#include "include.h"

void push_to_room(room_t *room, amazed_t *amazed)
{
    int len = 0;
    if (amazed->room_info != NULL)
        for (int i = 0; amazed->room_info[i]; i++)
            len++;
    room_t **room_info = malloc(sizeof(room_t *) * (len + 2));
    if (amazed->room_info != NULL) {
        for (int i = 0; i < len; i++)
            room_info[i] = amazed->room_info[i];
        room_info[len++] = room;
        room_info[len] = NULL;
    } else {
        room_info[0] = room;
        room_info[1] = NULL;
    }
    amazed->room_info = room_info;
}

void push_to_tunnel(char *link, amazed_t *amazed)
{
    int len = 0;
    if (amazed->tunnels != NULL)
        for (int i = 0; amazed->tunnels[i]; i++)
            len++;
    char **new = malloc(sizeof(char *) * (len + 2));
    if (amazed->tunnels != NULL) {
        for (int i = 0; i < len; i++)
            new[i] = amazed->tunnels[i];
        new[len++] = strdup(link);
        new[len] = NULL;
    } else {
        new[0] = strdup(link);
        new[1] = NULL;
    }
    amazed->tunnels = new;
}
