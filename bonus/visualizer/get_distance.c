/*
** EPITECH PROJECT, 2024
** dist
** File description:
** dist
*/

#include "include.h"

int mouse_in_rect(sfRenderWindow *window, sfVector2i size, sfVector2i pos)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    if (mouse_pos.x >= pos.x && mouse_pos.x < pos.x + size.x)
        if (mouse_pos.y >= pos.y && mouse_pos.y < pos.y + size.y)
            return 1;
    return 0;
}

double get_distance(sfVector2i posA, sfVector2i posB)
{
    return sqrt(pow(posB.y - posA.y, 2) + pow(posB.x - posA.x, 2));
}

float get_angle(sfVector2i start, sfVector2i finish)
{
    int diff_x = finish.x - start.x;
    int diff_y = finish.y - start.y;
    float angle = atan2f(diff_y, diff_x) * 180 / M_PI;

    return angle;
}

float get_a(sfVector2f pos1, sfVector2f pos2)
{
    float a;
    return ((pos2.y - pos1.y) / (pos2.x - pos1.x));
}