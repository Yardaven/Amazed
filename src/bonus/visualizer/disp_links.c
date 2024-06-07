/*
** EPITECH PROJECT, 2024
** links
** File description:
** links
*/

#include "include.h"

void display_links_basic(char *link, gen_t *gen)
{
    room_t *room1;
    room_t *room2;
    sfVector2i pos_room1;
    sfVector2i pos_room2;
    sfRectangleShape *rect;
    char *tmp = strdup(link);
    char **tab = my_str_to_array(tmp, "-");
    room1 = get_room_from_id(tab[0], gen);
    room2 = get_room_from_id(tab[1], gen);
    if (!room1 || !room2)
        return;
    pos_room1 = (sfVector2i){room1->x, room1->y};
    pos_room2 = (sfVector2i){room2->x, room2->y};
    rect = create_rectangle((sfVector2f){room1->x + 10, room1->y + 10}, (sfVector2f){get_distance(pos_room1, pos_room2), 1}, sfBlue);
    sfRectangleShape_setRotation(rect, get_angle(pos_room1, pos_room2));
    sfRenderWindow_drawRectangleShape(gen->window, rect, NULL);
    sfRectangleShape_destroy(rect);
    free(tmp);
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}

void display_links(gen_t *gen)
{
    if (gen->tunnels)
        for (int i = 0; gen->tunnels[i]; i++) {
            display_links_basic(gen->tunnels[i], gen);
        }
}
