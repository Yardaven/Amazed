/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include "include.h"

void display_room(gen_t *gen)
{   
    sfVector2f pos;

    for (int i = 0; gen->rooms[i]; i++)
    {
        pos = (sfVector2f){gen->rooms[i]->x, gen->rooms[i]->y};
        show_circle(gen->window, pos, 10, sfBlue);
        show_text(gen->window, gen->rooms[i]->id, (sfVector2f){pos.x, pos.y + 10}, 25, "rs/regular.ttf");
    }
}

robot_t **init_robots(gen_t *gen)
{
    robot_t **robots = malloc(sizeof(robot_t *) * (gen->nb_robots + 1));
    int i = 0;

    for (i = 0; i < gen->nb_robots; i++) {
        robots[i] = malloc(sizeof(robot_t));
        robots[i]->index = i + 1;
        robots[i]->pos = gen->start_pos;
    }
    robots[i] = NULL;
    return robots;
}

void disp_robots(gen_t *gen)
{
    char *index;
    for (int i = 0; gen->robots[i]; i++) {
        show_sprite(gen->window, "rs/bot.png", gen->robots[i]->pos, 0.09);
        index = my_number_to_str(gen->robots[i]->index);
        show_text(gen->window, index, (sfVector2f){gen->robots[i]->pos.x + 14, gen->robots[i]->pos.y + 12}, 15, "rs/regular.ttf");
    }
}

robot_t *get_bot_from_id(gen_t *gen, int index)
{
    for (int i = 0; gen->robots[i]; i++) {
        if (gen->robots[i]->index == index)
            return gen->robots[i];
    }
    return NULL;
}

void move_turn(gen_t *gen, int line_index)
{
    char *line = strdup(gen->moves[line_index]);
    char **tmp_tab = my_str_to_array(line, " ");
    int len = my_tablen(tmp_tab);
    robot_t *robot;
    room_t *room;
    char ***true_tab = malloc(sizeof(char **) * (len + 1));
    int i = 0;
    for (i = 0; tmp_tab[i]; i++) {
        true_tab[i] = my_str_to_array(tmp_tab[i], "P-");
    }
    true_tab[i] = NULL;
    mini_cleaner(tmp_tab, line);
    for (i = 0; true_tab[i]; i++) {
        robot = get_bot_from_id(gen, atoi(true_tab[i][0]));
        room = get_room_from_id(true_tab[i][1], gen);
        robot->pos = (sfVector2f){room->x, room->y};
    }
}

char ***get_move_command(char *cmd)
{
    char *line = strdup(cmd);
    char **tmp_tab = my_str_to_array(line, " ");
    int len = my_tablen(tmp_tab);
    char ***true_tab = malloc(sizeof(char **) * (len + 1));
    int i = 0;

    for (i = 0; tmp_tab[i]; i++) {
        true_tab[i] = my_str_to_array(tmp_tab[i], "P-");
    }
    true_tab[i] = NULL;
    return true_tab;
}

int all_robots_at_goal(gen_t *gen)
{
    robot_t *robot;
    room_t *room;
    char ***true_tab = get_move_command(gen->moves[gen->line_index]);

    for (int i = 0; true_tab[i]; i++) {
        robot = get_bot_from_id(gen, atoi(true_tab[i][0]));
        room = get_room_from_id(true_tab[i][1], gen);
        if (robot->pos.x != room->x)
            return 0;
    }
    return 1;
}

void travelling(gen_t *gen)
{
    char ***tab;
    robot_t *robot;
    room_t *room;

    if (all_robots_at_goal(gen)) {
        gen->line_index++;
        return;
    }
    tab = get_move_command(gen->moves[gen->line_index]);
    for (int i = 0; tab[i]; i++) {
        robot = get_bot_from_id(gen, atoi(tab[i][0]));
        room = get_room_from_id(tab[i][1], gen);
        if (robot->pos.x < room->x) {
            robot->pos.y += get_a(robot->pos, (sfVector2f){room->x, room->y});
            robot->pos.x++;
        }
        if (robot->pos.x > room->x) {
            robot->pos.y += get_a((sfVector2f){room->x, room->y}, robot->pos);
            robot->pos.x--;
        }
    }
}

void disp_moves(gen_t *gen)
{
    char *cmd = strdup(gen->moves[gen->line_index]);
    char **tab = my_str_to_array(cmd, " ");

    for (int i = 0; tab[i]; i++) {
        show_text(gen->window, tab[i], (sfVector2f){1680, (200 + (i * 50))}, 35, "rs/regular.ttf");
    }
    mini_cleaner(tab, cmd);
}

void manage_event(gen_t *gen)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(gen->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(gen->window);
        if (event.type == sfEvtKeyPressed) {
            if (sfKeyboard_isKeyPressed(sfKeyQ))
                sfRenderWindow_close(gen->window);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            gen->pressed = 1;
            gen->hold = 1;
        }else
            gen->pressed = 0;
        if (event.type == sfEvtMouseButtonReleased) {
            gen->released = 1;
            gen->hold = 0;
        }else
            gen->released = 0;
    }
}


void init_buttons(gen_t *gen)
{
    button_t **button = malloc(sizeof(button_t *) * 3);
    button[0] = create_button((sfVector2i){1650, 50}, (sfVector2i){200, 50}, &restart_func, "Restart");
    button[1] = create_button((sfVector2i){1650, 800}, (sfVector2i){200, 50}, &quit_func, "Finish");
    button[2] = NULL;
    gen->buttons = button;
}


int main(void)
{
    char **content = get_content();
    gen_t gen = {0};
    parser(&gen, content);
    gen.robots = init_robots(&gen);
    gen.window = window_create(1920, 1080, 32, 144);
    gen.line_index = 0;
    init_buttons(&gen);
    while (sfRenderWindow_isOpen(gen.window)) {
        manage_event(&gen);
        sfRenderWindow_clear(gen.window, sfWhite);
        display_links(&gen);
        display_room(&gen);
        disp_robots(&gen);
        show_rect(gen.window, (sfVector2f){400, 1080}, (sfVector2i){1520, 0}, sfColor_fromRGB(150, 150, 150), sfBlack, 2);
        show_text(gen.window, "Actual move:", (sfVector2f){1600, 150}, 35, "rs/regular.ttf");
        if (gen.line_index < my_tablen(gen.moves))
            disp_moves(&gen);
        manage_buttons(&gen);
        sfRenderWindow_display(gen.window);
        if (gen.line_index >= my_tablen(gen.moves))
            continue;
        travelling(&gen);
        continue;
    }
    return 0;
}