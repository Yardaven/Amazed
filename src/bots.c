/*
** EPITECH PROJECT, 2024
** setbots
** File description:
** auxilary file to set or move bots
*/
#include "path.h"
#include "my.h"

char *after_movement(bot_t *bot)
{
    char *str = "P";

    str = my_strcat(str, int_to_str(bot->id + 1), "");
    str = my_strcat(str, bot->cur->id, "-");
    return str;
}

int win_condition(map_t *map, bot_t **bots)
{
    for (int i = 0; bots[i]; i++) {
        if (my_strcmp(map->id_end, bots[i]->cur->id) != 0)
            return 0;
    }
    return 1;
}

int move_bot(map_t *map, bot_t *bot, room_t *target)
{
    for (int i = 0; bot->cur->next[i] && target; i++) {
        if (my_strcmp(bot->cur->next[i]->id, target->id) == 0
        && target->busy == 0){
            bot->cur->busy = 0;
            bot->cur = bot->cur->next[i];
            update_chain(map, bot);
            return 1;
        }
    }
    return 0;
}

static int get_room_number(map_t *map)
{
    int i = 0;

    for (; map->room[i]; i++);
    return i;
}

static weight_t **set_weight(map_t *map)
{
    weight_t **tmp = malloc(sizeof(weight_t *) * get_room_number(map));

    for (int i = 0; map->room[i]; i++) {
        tmp[i] = malloc(sizeof(weight_t) + 1);
        tmp[i]->seen = 0;
        tmp[i]->room_i = i;
        tmp[i]->id = map->room[i]->id;
    }
    return tmp;
}

void set_bots(map_t *map, bot_t **bots)
{
    int i = 0;

    for (; i < map->size; i++) {
        bots[i] = malloc(sizeof(bot_t));
        bots[i]->id = i;
        bots[i]->cur = malloc(sizeof(room_t));
        bots[i]->cur = map->room[map->start];
        bots[i]->x = map->room[map->start]->x;
        bots[i]->y = map->room[map->start]->y;
        bots[i]->e_x = map->room[map->end]->x;
        bots[i]->e_y = map->room[map->end]->y;
        bots[i]->weight = set_weight(map);
    }
    bots[i] = NULL;
}
