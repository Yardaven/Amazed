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

typedef struct room_s {
    char *id;
    int x;
    int y;
} room_t;

typedef struct button_s {
    int is_active;
    int is_held;
    sfVector2i pos;
    sfRectangleShape *rect;
    sfVector2i size;
    void(*func)(struct gen_s *);
    char *button_name;
} button_t;

typedef struct robots_s {
    sfVector2f pos;
    int index;
} robot_t;

typedef struct gen_s {
    int hold;
    int line_index;
    int pressed;
    int released;
    int nb_robots;
    char *id_start;
    sfVector2f start_pos;
    char **tunnels;
    char **moves;
    room_t *start;
    room_t **rooms;
    robot_t **robots;
    sfRenderWindow *window;
    button_t **buttons;
} gen_t;

sfRenderWindow *window_create(int width, int height, int bPP, int framerate);
sfRectangleShape *create_rectangle(sfVector2f pos, sfVector2f size, sfColor color);
void show_text(sfRenderWindow *window, char *str, sfVector2f pos, int size, char *font);
void show_rect(sfRenderWindow *window, sfVector2f size, sfVector2i pos, sfColor color_in, sfColor color_out, float thickness);
void show_circle(sfRenderWindow *w, sfVector2f pos, float rad, sfColor color);
void show_sprite(sfRenderWindow *window, char *path, sfVector2f pos, float scale);

void restart_func(gen_t *gen);
void quit_func(gen_t *gen);


button_t *create_button(sfVector2i pos, sfVector2i size, void(*func)(gen_t *), char *name);
room_t *create_room(char *id, int x, int y);
room_t *get_room_from_id(char *id, gen_t *gen);
char **get_content();
float get_a(sfVector2f pos1, sfVector2f pos2);
void parser(gen_t *gen, char **content);
void manage_buttons(gen_t *gen);


char *my_number_to_str(int nb);
int my_strlen(char *str);
char *my_strcat(char *dest, char *src, char *sep);
double get_distance(sfVector2i posA, sfVector2i posB);
float get_angle(sfVector2i start, sfVector2i finish);
char **my_str_to_array(char *str, char *delim);
int mouse_in_rect(sfRenderWindow *window, sfVector2i size, sfVector2i pos);
void display_links(gen_t *gen);
char *fileread(char *filepath);
int my_tablen(char **tab);
void mini_cleaner(char **tab, char *str);
void my_put(void *pointer, char type, int nb);
#endif
