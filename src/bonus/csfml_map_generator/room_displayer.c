/*
** EPITECH PROJECT, 2024
** room displayer
** File description:
** room risplayer
*/

#include "include.h"

void show_a_room(room_t *room, sfRenderWindow *window)
{
    char *x_pos = my_number_to_str(room->x);
    char *y_pos = my_number_to_str(room->y);
    show_circle(window, (sfVector2f){room->x - 20, room->y - 20}, 20, sfBlue);
    show_text(window, x_pos, (sfVector2f){room->x - 50, room->y + 25}, 25, "rs/regular.ttf");
    show_text(window, y_pos, (sfVector2f){room->x + 15, room->y + 25}, 25, "rs/regular.ttf");
    show_text(window, room->id, (sfVector2f){room->x - 35, room->y - 50}, 25, "rs/regular.ttf");
    free(x_pos);
    free(y_pos);
}

void room_displayer(amazed_t *amazed, gen_t *gen)
{
    sfVector2i room_pos;
    sfVector2i mouse_pos;

    if (amazed->room_info == NULL)
        return;
    for (int i = 0; amazed->room_info[i]; i++) {
        if (gen->mode == 1)
            if (gen->pressed == 1) {
                mouse_pos = sfMouse_getPositionRenderWindow(gen->window);
                room_pos = (sfVector2i){amazed->room_info[i]->x, amazed->room_info[i]->y};
                if (get_distance(room_pos, mouse_pos) < 20)
                    amazed->room_info[i]->drag = 1;
            }
        show_a_room(amazed->room_info[i], gen->window);
    }
}