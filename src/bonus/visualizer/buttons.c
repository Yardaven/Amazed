/*
** EPITECH PROJECT, 2024
** buttons
** File description:
** buttons
*/

#include "include.h"

button_t *create_button(sfVector2i pos, sfVector2i size, void(*func)(gen_t *), char *name)
{
    button_t *button = malloc(sizeof(button_t));
    button->pos = pos;
    button->size = size;
    button->func = func;
    button->is_active = 1;
    button->is_held = 0;
    button->rect = create_rectangle((sfVector2f){pos.x, pos.y}, (sfVector2f){size.x, size.y}, sfColor_fromRGB(100, 100, 100));
    button->button_name = strdup(name);
    return button;
}

void button_behavior(gen_t *gen, int index)
{
    sfRectangleShape_setFillColor(gen->buttons[index]->rect, sfColor_fromRGB(160, 160, 160));
    if (gen->buttons[index]->is_active == 0) {
        sfRectangleShape_setFillColor(gen->buttons[index]->rect, sfColor_fromRGB(50, 50, 50));
        return;
    }
    if (mouse_in_rect(gen->window, gen->buttons[index]->size, gen->buttons[index]->pos))
        if (gen->pressed) {
            sfRectangleShape_setFillColor(gen->buttons[index]->rect, sfColor_fromRGB(50, 50, 50));
            gen->buttons[index]->func(gen);
            return;
        }
    if (mouse_in_rect(gen->window, gen->buttons[index]->size, gen->buttons[index]->pos))
        sfRectangleShape_setFillColor(gen->buttons[index]->rect, sfColor_fromRGB(200, 200, 200));

}

void manage_buttons(gen_t *gen)
{
    for (int i = 0; gen->buttons[i]; i++) {
        button_behavior(gen, i);
        sfRenderWindow_drawRectangleShape(gen->window, gen->buttons[i]->rect, NULL);
        show_text(gen->window, gen->buttons[i]->button_name, (sfVector2f){gen->buttons[i]->pos.x + 50, gen->buttons[i]->pos.y + 5}, 35, "rs/regular.ttf");
    }
}