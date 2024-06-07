/*
** EPITECH PROJECT, 2024
** cleaner
** File description:
** cleaner
*/

#include "include.h"

void clean_all(amazed_t *amazed, gen_t *gen)
{
    free(amazed->start_id);
    free(amazed->end_id);
    if (amazed->tunnels) {
        for (int i = 0; amazed->tunnels[i]; i++)
            free(amazed->tunnels[i]);
        free(amazed->tunnels);
    }
    if (amazed->room_info) {
        for (int i = 0; amazed->room_info[i]; i++) {
            free(amazed->room_info[i]->id);
            free(amazed->room_info[i]);
        }
        free(amazed->room_info);
    }
    sfRenderWindow_destroy(gen->window);
    for (int i = 0; gen->buttons[i]; i++) {
        free(gen->buttons[i]->button_name);
        sfRectangleShape_destroy(gen->buttons[i]->rect);
        free(gen->buttons[i]);
    }
    free(gen->buttons);
    sfRectangleShape_destroy(gen->cursor->rect);
    free(gen->cursor);
    free(amazed);
}
