/*
** EPITECH PROJECT, 2023
** AMAZED
** File description:
** Pathfinding functions, moving robots
*/
#include "my.h"
#include "path.h"

static int shorter_bismillah(chain_t *new_node, int pre_sum, int sum_save)
{
    for (int j = 0; new_node->prev->room->next[j]; j++){
        if (pre_sum + new_node->prev->room->next[j]->tot < sum_save
        && my_strcmp(new_node->prev->room->next[j]->id,
        new_node->room->id) != 0
        && new_node->prev->room->next[j]->busy == 0){
            return 1;
        }
    }
    return 0;
}

int shorter_bis(chain_t *new_node, int pre_sum, int sum_save)
{
    for (int j = 0; new_node->prev->room->next[j]; j++){
        if (pre_sum + new_node->prev->room->next[j]->tot < sum_save
        && my_strcmp(new_node->prev->room->next[j]->id,
        new_node->room->id) != 0
        && new_node->prev->room->next[j]->busy == 0){
            new_node->room = new_node->prev->room->next[j];
            return pre_sum + new_node->prev->room->next[j]->tot;
        }
    }
    return 0;
}

int shorter(chain_t *new_node, int pre_sum, int sum_save)
{
    for (int i = 0; new_node->prev != NULL; i++) {
        if (shorter_bismillah(new_node, pre_sum, sum_save))
            return shorter_bis(new_node, pre_sum, sum_save);
        pre_sum -= new_node->room->tot;
        new_node = new_node->prev;
    }
    return sum_save;
}
