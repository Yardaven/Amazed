/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include "include.h"

room_t *create_room(char *id, int x, int y)
{
    room_t *room = malloc(sizeof(room_t));

    room->id = strdup(id);
    room->x = x;
    room->y = y;
    return room;
}

void disp(amazed_t *amazed)
{
    printf("%d\n", amazed->nb_robots);
    if (amazed->room_info != NULL)
        for (int i = 0; amazed->room_info[i] != NULL; i++) {
            if (!amazed->room_info[i]->id)
                break;
            if (strcmp(amazed->room_info[i]->id, amazed->start_id) == 0)
                printf("##start\n");
            if (strcmp(amazed->room_info[i]->id, amazed->end_id) == 0)
                printf("##end\n");
            printf("%s ", amazed->room_info[i]->id);
            printf("%d ", amazed->room_info[i]->x);
            printf("%d\n", amazed->room_info[i]->y);
        }
    if (amazed->tunnels)
        for (int i = 0; amazed->tunnels[i] != NULL; printf("%s\n", amazed->tunnels[i++]));
}

void create_gen_file(amazed_t *amazed)
{
    int fd = open("generated_map.txt", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU, S_IRWXO, S_IRWXG);

    dup2(fd, 1);
    disp(amazed);
    close(fd);
    return;
}

amazed_t *init_amazed(void)
{
    amazed_t *amazed = malloc(sizeof(amazed_t));
    room_t **rooms = malloc(sizeof(room_t *) * 3);

    rooms[0] = create_room("start", 100, 500);
    rooms[1] = create_room("end", 1000, 500);
    rooms[2] = NULL;
    amazed->nb_robots = 10;
    amazed->start_id = strdup("start");
    amazed->end_id = strdup("end");
    amazed->room_info = rooms;
    amazed->tunnels = NULL;
    return amazed;
}

void manage_events(gen_t *gen, amazed_t *amazed)
{
    sfEvent event;
    room_t *room = NULL;
    while (sfRenderWindow_pollEvent(gen->window, &event)) {
        if (event.type == sfEvtKeyPressed) {
            if (sfKeyboard_isKeyPressed(sfKeyQ))
                sfRenderWindow_close(gen->window);
        }
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(gen->window);
        if (event.type == sfEvtMouseButtonPressed) {
            gen->hold = 1;
            gen->pressed = 1;
            gen->pressed_pos = sfMouse_getPositionRenderWindow(gen->window);
        } else
            gen->pressed = 0;
        if (event.type == sfEvtMouseButtonReleased) {
            gen->released = 1;
            gen->release_pos = sfMouse_getPositionRenderWindow(gen->window);
            gen->hold = 0;
            if (amazed->room_info)
                for (int i = 0; amazed->room_info[i]; amazed->room_info[i++]->drag = 0);
        } else
            gen->released = 0;
    }
}

void init_gen(gen_t *gen)
{
    gen->window = window_create(1920, 1080, 32, 60);
    gen->hold = 0;
    gen->mode = 0;
    gen->buttons = malloc(sizeof(button_t *) * 6);
    gen->buttons[0] = create_button((sfVector2i){1400, 200}, (sfVector2i){450, 100}, &set_cursor_mode, "CURSOR MODE");
    gen->buttons[1] = create_button((sfVector2i){1400, 350}, (sfVector2i){450, 100}, &set_link_mode, "LINK MODE");
    gen->buttons[2] = create_button((sfVector2i){1400, 500}, (sfVector2i){450, 100}, &add_new_room, "CREATE ROOM");
    gen->buttons[3] = create_button((sfVector2i){1400, 780}, (sfVector2i){450, 100}, &done_func, "DONE");
    gen->buttons[4] = create_button((sfVector2i){1400, 650}, (sfVector2i){450, 100}, &set_erase_mode, "ERASE");
    gen->buttons[5] = NULL;
    gen->cursor = create_cursor((sfVector2i){1330, 100}, (sfVector2i){75, 45}, 500, 1330, 1830);
}

int main(int argc, char **argv)
{
    char *str = NULL;
    if (argc == 2) {
        if (strcmp(argv[1], "-h") == 0) {
            str = fileread("usage.txt");
            printf("%s\n", str);
            free(str);
            return 0;
        }
    }
    gen_t gen = {0};
    init_gen(&gen);
    amazed_t *amazed = init_amazed();
    char *result = NULL;
    char *robot_number_line = NULL;
    char *robot_number = NULL;

    while(sfRenderWindow_isOpen(gen.window)) {
        manage_events(&gen, amazed);
        sfRenderWindow_clear(gen.window, sfWhite);
        show_rect(gen.window, (sfVector2f){600, 1080}, (sfVector2i){1320, 0}, sfColor_fromRGB(180, 180, 180), sfBlack, 3);
        robot_number_line = strdup("robots number: ");
        robot_number = my_number_to_str(amazed->nb_robots);
        show_text(gen.window, strcat(robot_number_line, robot_number), (sfVector2f){1450, 50}, 35, "rs/regular.ttf");
        if (gen.released == 1 && gen.mode == 2) {
            create_link(amazed, &gen);
        }
        if (gen.released == 1 && gen.mode == 3) {
            remove_room(&gen, amazed);
        }
        if (gen.mode == 2 && gen.hold == 1)
            show_trace(&gen);
        display_links(amazed, &gen);
        avoid_collision(amazed);
        manage_buttons(&gen, amazed);
        room_displayer(amazed, &gen);
        update_pos(amazed, gen.window);
        manage_cursor(&gen, amazed);
        sfRenderWindow_display(gen.window);
        free(robot_number_line);
        free(robot_number);
        free(result);
    }
    create_gen_file(amazed);
    clean_all(amazed, &gen);
    return 0;
}