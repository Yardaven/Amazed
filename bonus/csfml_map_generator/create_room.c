/*
** EPITECH PROJECT, 2024
** room
** File description:
** room
*/

#include "include.h"

int char_is_ok(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    if (c >= 'a' && c <= 'z')
        return 1;
    if (c >= '0' && c <= '9')
        return 1;
    if (c == '_')
        return 1;
    return 0;
}

static void check_mouse_pos(sfRenderWindow *window)
{
    sfVector2i pos;

    pos = sfMouse_getPositionRenderWindow(window);
    if (pos.x <= 15 || pos.x >= 600 || pos.y <= 15 || pos.y >= 600)
        sfMouse_setPositionRenderWindow((sfVector2i){300, 300}, window);
}

static void manage_event(sfRenderWindow *window, room_t *room, get_room_t *get_room)
{
    sfEvent event;
    char tmp[2];

    while(sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed || get_room->finished == 1)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed) {
            if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
                if (get_room->final_line)
                    free(get_room->final_line);
                get_room->final_line = strdup(get_room->line);
                free(get_room->line);
                get_room->line = strdup("");
            }
        }
        if (event.type == sfEvtMouseButtonPressed)
            get_room->pressed = 1;
        else
            get_room->pressed = 0;
        if (get_room->can_write == 1) {
            if (event.type == sfEvtTextEntered) {
                tmp[0] = event.text.unicode;
                tmp[1] = '\0';
                if (tmp[0] != 8) {
                    if (char_is_ok(tmp[0])) {
                        if (strlen(get_room->line) < 13)
                            get_room->line = my_strcat(get_room->line, tmp, "");
                        else
                            get_room->line[strlen(get_room->line) - 1] = tmp[0];
                    }
                } else
                    get_room->line[strlen(get_room->line) - 1] = '\0';
            }
        }
    }
}

void manage_pressed(get_room_t *get_room)
{
    if (get_room->pressed == 1) {
        if (get_room->mouse_pos.x >= 65 && get_room->mouse_pos.x <= 515 && get_room->mouse_pos.y >= 100 && get_room->mouse_pos.y <= 150)
            get_room->can_write = 1;
        else
            get_room->can_write = 0;
        if (get_room->mouse_pos.x >= 175 && get_room->mouse_pos.x <= 425 && get_room->mouse_pos.y >= 400 && get_room->mouse_pos.y <= 500)
            get_room->finished = 1;
    }
}

static void create_display(get_room_t *get_room, int valid, sfRenderWindow *window)
{
    show_rect(window, (sfVector2f){450, 50}, (sfVector2i){65, 100}, sfWhite, sfBlack, 2);
    show_rect(window, (sfVector2f){250, 100}, (sfVector2i){175, 400}, sfGreen, sfBlack, 2);
    show_text(window, "Enter room name:", (sfVector2f){80, 50}, 35, "rs/regular.ttf");
    show_text(window, "(max length = 13 characters)", (sfVector2f){100, 155}, 20, "rs/regular.ttf");
    if (valid == 1)
        show_text(window, "*Room must have a name before quit.*", (sfVector2f){80, 0}, 25, "rs/regular.ttf");
    if (valid == 2)
        show_text(window, "*Name already taken.*", (sfVector2f){165, 0}, 25, "rs/regular.ttf");
    show_text(window, get_room->line, (sfVector2f){80, 100}, 35, "rs/regular.ttf");
    show_text(window, "Confirm this name ?", (sfVector2f){60, 250}, 35, "rs/regular.ttf");
    show_text(window, get_room->final_line, (sfVector2f){60, 300}, 35, "rs/regular.ttf");
    show_text(window, "CONFIRM", (sfVector2f){225, 425}, 35, "rs/regular.ttf");
    sfRenderWindow_display(window);
}

void mini_cleanup(get_room_t *get_room, sfRenderWindow *window)
{
    free(get_room->line);
    free(get_room->final_line);
    sfRenderWindow_destroy(window);
}

room_t *init_new_room(int valid, room_t **current_rooms)
{
    get_room_t get_room = {0};
    sfRenderWindow *window = window_create(600, 600, 32, 60);
    room_t *room = malloc(sizeof(room_t));

    get_room.can_write = 0;    
    get_room.pressed = 0;    
    get_room.line = strdup("");
    get_room.final_line = strdup("");
    get_room.finished = 0;
    room->x = 500;
    room->y = 500;
    sfMouse_setPositionRenderWindow((sfVector2i){300, 300}, window);
    while(sfRenderWindow_isOpen(window)) {
        get_room.mouse_pos = sfMouse_getPositionRenderWindow(window);
        sfRenderWindow_clear(window, sfColor_fromRGB(200, 200, 200));
        manage_event(window, room, &get_room);
        manage_pressed(&get_room);
        create_display(&get_room, valid, window);
        
    }
    if (strlen(get_room.final_line) == 0) {
        mini_cleanup(&get_room, window);
        return init_new_room(1, current_rooms);
    }
    if (current_rooms != NULL)
        for (int i = 0; current_rooms[i]; i++)
            if (strcmp(get_room.final_line, current_rooms[i]->id) == 0) {
                mini_cleanup(&get_room, window);
                return init_new_room(2, current_rooms);
            }
    room->id = strdup(get_room.final_line);
    mini_cleanup(&get_room, window);
    return room;
}