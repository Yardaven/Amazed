/*
** EPITECH PROJECT, 2023
** AMAZED
** File description:
** Pathfinding functions, moving robots
*/
#include "my.h"
#include "path.h"

void update_chain(map_t *map, bot_t *bot)
{
    if (my_strcmp(bot->cur->id, map->id_start) != 0
    && my_strcmp(bot->cur->id, map->id_end) != 0){
        bot->cur->busy = 1;
    }
}

static int get_link_nbr(room_t *room)
{
    int i = 0;

    for (; room->next[i]; i++);
    return i;
}

static int get_best_bis(room_t *bot_r, bot_t *bot)
{
    int min_id = -1;

    for (int i = bot->weight[bot->cur->room_i]->seen; bot_r->next[i]; i++) {
        if (bot_r->next[i]->busy == 0
        && bot->weight[bot->cur->room_i]->seen < get_link_nbr(bot->cur)){
            min_id = i;
            bot->weight[bot->cur->next[min_id]->room_i]->seen += 1;
            return min_id;
        }
    }
    return min_id;
}

room_t *get_best(room_t *bot_r, bot_t *bot)
{
    int min_id = 0;
    room_t *error = malloc(sizeof(room_t) + 1);

    error->id = "error";
    if (bot_r->next[0] == NULL)
        return bot_r;
    for (int i = 0; bot_r->next[i]; i++) {
        if (bot_r->next[i] == NULL)
            return bot_r;
    }
    min_id = get_best_bis(bot_r, bot);
    if (min_id == -1) {
        return error;
    }
    return bot_r->next[min_id];
}

static int block_dead_end(map_t *map)
{
    int j = 0;
    int cpt = 0;
    int ret_val = 1;

    for (int i = 0; map->room[i]; i++) {
        for (; map->room[i]->next[j]; j++) {
            cpt += (map->room[i]->next[j]->busy == 0) ? 1 : 0;
        }
        if (cpt < 2
        && my_strcmp(map->id_start, map->room[i]->id) != 0
        && my_strcmp(map->id_end, map->room[i]->id) != 0
        && map->room[i]->busy == 0) {
            map->room[i]->busy = 1;
            ret_val = 0;
        }
        cpt = 0;
        j = 0;
    }
    return ret_val;
}

static int amazed_loop(bot_t **bots, map_t *map, int moved, int first_move)
{
    char *str = "";

    for (int i = 0; bots[i]; i++) {
        if (my_strcmp(map->id_end, bots[i]->cur->id) == 0)
            continue;
        moved = move_bot(map, bots[i], get_best(bots[i]->cur, bots[i]));
        if (moved) {
            str = (first_move) ? my_strcat(str, after_movement(bots[i]), "") :
                my_strcat(str, after_movement(bots[i]), " ");
            first_move = 0;
            map->loop++;
        }
    }
    if (!map->loop)
        return 0;
    my_printf("%s\n", str);
    free(str);
    return 1;
}

int amazed(map_t *map, bot_t **bots)
{
    int moved = 0;

    while (block_dead_end(map) == 0);
    set_bots(map, bots);
    while (!win_condition(map, bots)) {
        map->loop = 0;
        if (!amazed_loop(bots, map, moved, 1)) {
            return 0;
            break;
        }
    }
    return 1;
}
