/*
** EPITECH PROJECT, 2024
** show
** File description:
** show
*/

#include "include.h"

void show_text(sfRenderWindow *window, char *str, sfVector2f pos, int size, char *font_name)
{
    sfFont *font = sfFont_createFromFile(font_name);
    sfText *text = sfText_create();

    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, pos);
    sfText_setColor(text, sfBlack);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

void show_rect(sfRenderWindow *window, sfVector2f size, sfVector2i pos, sfColor color_in, sfColor color_out, float thickness)
{
    sfRectangleShape *rectangle = create_rectangle((sfVector2f){pos.x, pos.y}, size, color_in);
    
    sfRectangleShape_setOutlineColor(rectangle, color_out);
    sfRectangleShape_setOutlineThickness(rectangle, thickness);
    sfRectangleShape_setFillColor(rectangle, color_in);
    sfRenderWindow_drawRectangleShape(window, rectangle, NULL);
    sfRectangleShape_destroy(rectangle);
}

void show_circle(sfRenderWindow *w, sfVector2f pos, float rad, sfColor color)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setFillColor(circle, color);
    sfCircleShape_setPosition(circle, pos);
    sfCircleShape_setRadius(circle, rad);
    sfCircleShape_setOutlineColor(circle, color);
    sfRenderWindow_drawCircleShape(w, circle, NULL);
    sfCircleShape_destroy(circle);
}

void show_trace(gen_t *gen)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(gen->window);
    sfRectangleShape *rect = create_rectangle((sfVector2f){gen->pressed_pos.x, gen->pressed_pos.y}, (sfVector2f){get_distance(mouse_pos, gen->pressed_pos), 2}, sfBlue);
    sfRectangleShape_setRotation(rect, get_angle(gen->pressed_pos, mouse_pos));
    sfRenderWindow_drawRectangleShape(gen->window, rect, NULL);
    sfRectangleShape_destroy(rect);
}