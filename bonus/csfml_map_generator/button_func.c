/*
** EPITECH PROJECT, 2024
** func
** File description:
** func
*/

#include "include.h"

void set_cursor_mode(gen_t *gen, amazed_t *amazed)
{
    gen->mode = 1;
}

void set_link_mode(gen_t *gen, amazed_t *amazed)
{
    gen->mode = 2;
}

void set_erase_mode(gen_t *gen, amazed_t *amazed)
{
    gen->mode = 3;
}

void add_new_room(gen_t *gen, amazed_t *amazed)
{
    room_t *room = init_new_room(0, amazed->room_info);
    push_to_room(room, amazed);
}

void done_func(gen_t *gen, amazed_t *amazed)
{
    sfRenderWindow_close(gen->window);
}
