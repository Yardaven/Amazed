/*
** EPITECH PROJECT, 2024
** manage
** File description:
** manage
*/

#include "include.h"

void update_pos(amazed_t *amazed, sfRenderWindow *window)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);
    if (amazed->room_info != NULL)
        for (int i = 0; amazed->room_info[i]; i++)
            if (amazed->room_info[i]->drag == 1) {
                amazed->room_info[i]->x = pos.x;
                amazed->room_info[i]->y = pos.y;
            }
}

void avoid_collision(amazed_t *amazed)
{
    sfVector2i pos1;
    sfVector2i pos2;

    if (amazed->room_info) {
        for (int i = 0; amazed->room_info[i + 1]; i++) {
            pos1 = (sfVector2i){amazed->room_info[i]->x, amazed->room_info[i]->y};
            pos2 = (sfVector2i){amazed->room_info[i + 1]->x, amazed->room_info[i + 1]->y};
            if (get_distance(pos1, pos2) < 40)
                amazed->room_info[i + 1]->x += 40;
        }
        for (int i = 0; amazed->room_info[i]; i++) {
            pos1 = (sfVector2i){amazed->room_info[i]->x, amazed->room_info[i]->y};
            if (pos1.x > 1300)
                amazed->room_info[i]->x = 1299;
            if (pos1.x < 20)
                amazed->room_info[i]->x = 21;
            if (pos1.y > 1060)
                amazed->room_info[i]->y = 1599;
            if (pos1.y < 20)
                amazed->room_info[i]->y = 21;
        }
    }
}

int check_existing_link(room_t *room1, room_t *room2, amazed_t *amazed)
{
    char *tmp;
    char **tab;
    int nb = 0;
    room_t *tmp_room;
    room_t *tmp_room2;

    if (amazed->tunnels)
        for (int i = 0; amazed->tunnels[i]; i++) {
            nb = 0;
            tmp = strdup(amazed->tunnels[i]);
            tab = my_str_to_array(tmp, "-");
            tmp_room = get_room_from_id(tab[0], amazed);
            tmp_room2 = get_room_from_id(tab[1], amazed);
            if (!tmp_room || !tmp_room2)
                continue;
            if (strcmp(room1->id, tmp_room->id) == 0 || strcmp(room1->id, tmp_room2->id) == 0)
                nb += 1;
            if (strcmp(room2->id, tmp_room->id) == 0 || strcmp(room2->id, tmp_room2->id) == 0)
                nb += 1;
            if (nb == 2)
                return 1;
        }
    return 0;
}

void create_link(amazed_t *amazed, gen_t *gen)
{
    char *res = NULL;
    room_t *room1 = get_room_from_pos(gen->pressed_pos, amazed);
    room_t *room2 = get_room_from_pos(gen->release_pos, amazed);
    if (!room1 || !room2)
        return;
    res = my_strcat(room1->id, room2->id, "-");
    if (check_existing_link(room1, room2, amazed) == 0)
        push_to_tunnel(res, amazed);
    gen->released = 0;
    return;
}

void display_links_basic(char *link, amazed_t *amazed, gen_t *gen)
{
    room_t *room1;
    room_t *room2;
    sfVector2i pos_room1;
    sfVector2i pos_room2;
    sfRectangleShape *rect;
    char *tmp = strdup(link);
    char **tab = my_str_to_array(tmp, "-");
    room1 = get_room_from_id(tab[0], amazed);
    room2 = get_room_from_id(tab[1], amazed);
    if (!room1 || !room2)
        return;
    pos_room1 = (sfVector2i){room1->x, room1->y};
    pos_room2 = (sfVector2i){room2->x, room2->y};
    rect = create_rectangle((sfVector2f){room1->x, room1->y}, (sfVector2f){get_distance(pos_room1, pos_room2), 2}, sfBlue);
    sfRectangleShape_setRotation(rect, get_angle(pos_room1, pos_room2));
    sfRenderWindow_drawRectangleShape(gen->window, rect, NULL);
    sfRectangleShape_destroy(rect);
    free(tmp);
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}

void display_links(amazed_t *amazed, gen_t *gen)
{
    if (amazed->tunnels)
        for (int i = 0; amazed->tunnels[i]; i++) {
            display_links_basic(amazed->tunnels[i], amazed, gen);
        }
}