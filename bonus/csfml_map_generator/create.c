/*
** EPITECH PROJECT, 2024
** create
** File description:
** create
*/

#include "include.h"

sfRenderWindow *window_create(int width, int height, int bPP, int framerate)
{
    sfRenderWindow *w;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = bPP;
    w = sfRenderWindow_create(video_mode, "My Paint", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(w, framerate);
    sfRenderWindow_setVerticalSyncEnabled(w, sfTrue);
    return w;
}

sfRectangleShape *create_rectangle(sfVector2f pos,
    sfVector2f size, sfColor color)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();

    sfRectangleShape_setOutlineThickness(rectangle, 1.0);
    sfRectangleShape_setSize(rectangle, size);
    sfRectangleShape_setFillColor(rectangle, color);
    sfRectangleShape_setOutlineColor(rectangle, sfBlack);
    sfRectangleShape_setPosition(rectangle, pos);
    return rectangle;
}
