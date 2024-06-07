/*
** EPITECH PROJECT, 2024
** fnc
** File description:
** func
*/

#include "include.h"

void restart_func(gen_t *gen)
{
    gen->line_index = 0;
    for (int i = 0; gen->robots[i]; i++) {
        gen->robots[i]->pos = gen->start_pos;
    }
}

void quit_func(gen_t *gen)
{
    sfRenderWindow_close(gen->window);
}