/*
** EPITECH PROJECT, 2024
** cursor
** File description:
** cursor
*/

#include "include.h"

cursor_t *create_cursor(sfVector2i pos, sfVector2i size, int len, int x_min, int x_max)
{
    cursor_t *cursor = malloc(sizeof(cursor_t));

    cursor->len = len;
    cursor->pos = pos;
    cursor->size = size;
    cursor->x_min = x_min;
    cursor->x_min = x_max;
    cursor->rect = create_rectangle((sfVector2f){pos.x, pos.y}, (sfVector2f){size.x, size.y}, sfColor_fromRGB(200, 200, 200));
    cursor->hold = 0;
    cursor->bar_pos = (sfVector2i){pos.x + (size.x / 2), pos.y + (size.y / 2)};
    return cursor;
}

void manage_cursor(gen_t *gen, amazed_t *amazed)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(gen->window);
    int res = 0;

    if (gen->pressed == 1)
        if (mouse_in_rect(gen->window, gen->cursor->size, gen->cursor->pos)) {
            gen->pressed = 0;
            gen->cursor->hold = 1;
        }
    if (gen->cursor->hold == 1 && gen->hold == 1)
        if (mouse_pos.x > 1335 + (gen->cursor->size.x / 2) && mouse_pos.x <= 1830 + (gen->cursor->size.x / 2)) {
            gen->cursor->pos.x = mouse_pos.x - (gen->cursor->size.x / 2);
        }
    if (gen->released == 1)
        gen->cursor->hold = 0;
    res = gen->cursor->pos.x - 1330;
    amazed->nb_robots = res / 5;
    sfRectangleShape_setPosition(gen->cursor->rect, (sfVector2f){gen->cursor->pos.x, gen->cursor->pos.y});
    show_rect(gen->window, (sfVector2f){gen->cursor->len, 2}, gen->cursor->bar_pos, sfRed, sfBlack, 1);
    sfRenderWindow_drawRectangleShape(gen->window, gen->cursor->rect, NULL);
}