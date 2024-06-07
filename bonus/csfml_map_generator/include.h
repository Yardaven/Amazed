/*
** EPITECH PROJECT, 2024
** include
** File description:
** include
*/

#ifndef MY_GEN
    #define MY_GEN
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Config.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window/Export.h>
    #include <SFML/Window/Types.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/Graphics/Transform.h>
    #include <SFML/Audio/Export.h>
    #include <SFML/Audio/SoundStatus.h>
    #include <SFML/Audio/Types.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Vector3.h>
    #include <SFML/Audio/Sound.h>
    #include <SFML/Audio/SoundBuffer.h>
    #include <math.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <sys/fcntl.h>
    #include <string.h>

struct gen_s;

typedef struct get_room_s {
    char *line;
    char *final_line;
    int pressed;
    sfVector2i mouse_pos;
    int can_write;
    int finished;
} get_room_t;

typedef struct room_s {
    char *id;
    int x;
    int y;
    int drag;
} room_t;

typedef struct amazed_s {
    int nb_robots;
    room_t **room_info;
    char *start_id;
    char *end_id;
    char **tunnels;
} amazed_t;

typedef struct button_s {
    int is_active;
    int is_held;
    sfVector2i pos;
    sfRectangleShape *rect;
    sfVector2i size;
    void(*func)(struct gen_s *, amazed_t *);
    char *button_name;
} button_t;

typedef struct cursor_s {
    sfRectangleShape *rect;
    sfVector2i pos;
    sfVector2i size;
    int len;
    int x_min;
    int x_max;
    int hold;
    sfVector2i bar_pos;
} cursor_t;

typedef struct gen_s {
    int mode;
    int hold;
    int pressed;
    int released;
    sfVector2i pressed_pos;
    sfVector2i release_pos;
    sfRenderWindow *window;
    button_t **buttons;
    cursor_t *cursor;
} gen_t;


sfRenderWindow *window_create(int width, int height, int bPP, int framerate);
sfRectangleShape *create_rectangle(sfVector2f pos, sfVector2f size, sfColor color);
void show_text(sfRenderWindow *window, char *str, sfVector2f pos, int size, char *font);
void show_rect(sfRenderWindow *window, sfVector2f size, sfVector2i pos, sfColor color_in, sfColor color_out, float thickness);
void show_circle(sfRenderWindow *w, sfVector2f pos, float rad, sfColor color);
void show_trace(gen_t *gen);

button_t *create_button(sfVector2i pos, sfVector2i size, void(*func)(gen_t *, amazed_t *), char *name);
void add_new_room(gen_t *gen, amazed_t *amazed);
void set_link_mode(gen_t *gen, amazed_t *amazed);
void set_cursor_mode(gen_t *gen, amazed_t *amazed);
void set_erase_mode(gen_t *gen, amazed_t *amazed);
void done_func(gen_t *gen, amazed_t *amazed);
void manage_buttons(gen_t *gen, amazed_t *amazed);
int mouse_in_rect(sfRenderWindow *window, sfVector2i size, sfVector2i pos);

room_t *init_new_room(int valid, room_t **current_rooms);
void push_to_room(room_t *room, amazed_t *amazed);
room_t *create_room(char *id, int x, int y);
void room_displayer(amazed_t *amazed, gen_t *gen);
void update_pos(amazed_t *amazed, sfRenderWindow *window);
void avoid_collision(amazed_t *amazed);
void create_link(amazed_t *amazed, gen_t *gen);
void display_links(amazed_t *amazed, gen_t *gen);
room_t *get_room_from_id(char *id, amazed_t *amazed);
room_t *get_room_from_pos(sfVector2i pos, amazed_t *amazed);
void push_to_tunnel(char *link, amazed_t *amazed);
void clean_all(amazed_t *amazed, gen_t *gen);
cursor_t *create_cursor(sfVector2i pos, sfVector2i size, int len, int x_min, int x_max);
void manage_cursor(gen_t *gen, amazed_t *amazed);
void remove_room(gen_t *gen, amazed_t *amazed);

char *my_number_to_str(int nb);
char *my_strcat(char *dest, char *src, char *sep);
double get_distance(sfVector2i posA, sfVector2i posB);
float get_angle(sfVector2i start, sfVector2i finish);
char **my_str_to_array(char *str, char *delim);
char *fileread(char *filepath);
#endif
