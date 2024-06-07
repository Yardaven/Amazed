/*
** EPITECH PROJECT, 2023
** Parser.c
** File description:
** sucreeeh et parsing
*/

#ifndef PATH
    #define PATH
    #include <stdlib.h>
    #include <unistd.h>
    #include "my.h"
    #include <stdio.h>
    #include <sys/stat.h>

typedef struct weight_s {
    char *id;
    int room_i;
    int seen;
}weight_t;

typedef struct chain_s {
    //int id; //pas utile pour le moment
    struct room_s *room;
    struct chain_s *prev;
    struct chain_s *next;
}chain_t;

typedef struct bot_s {
    int id;
    int x;
    int y;
    int e_x;
    int e_y;
    int link;
    weight_t **weight;
    struct room_s *cur; //à malloc pour le robot
    struct room_s *target; //à malloc pour le robot
    chain_t *first; //à malloc pour le robot //pas sur de ça
    chain_t *chain; //à malloc pour le robot //pas sur de ça
}bot_t;

typedef struct room_s {
    char *id;
    int x;
    int y;
    int s_dist;
    int dist;
    int tot;
    int link;
    int busy;
    int room_i;
    struct room_s **next;
}room_t;


typedef struct map_s {
    int inc;
    int loop;
    int size;
    int num;
    int ret_val;
    char *id_start;
    int nb_start;
    int nb_end;
    int start;
    char *id_end;
    int end;
    char **tunnels;
    int t_num;
    room_t **room;
    bot_t **bots;//
}map_t;

map_t *parser(void);
int tab_len(char **tab);
void tunnel(char *line, map_t *map);
char *int_to_str(int n);
room_t *get_room_from_id(map_t *map, char *id);
int amazed(map_t *map, bot_t **bot);
int my_power(int nb, int p);
int get_dist(room_t *p1, room_t *p2);
int my_sqrt(int nb);
void display(map_t *map);
void set_bots(map_t *map, bot_t **bots);
int move_bot(map_t *map, bot_t *bot, room_t *target);
void update_chain(map_t *map, bot_t *bot);
int error_handling(map_t *map);
int is_garbage(char *line, map_t *map);
void mini_cleaner(char **tab, char *str);
map_t *parser_aux(char **content);
int get_room_total_number(char **content);
void get_end_and_start(map_t *map, char **content);
void get_tunnel(map_t *map, char **content);
void connect_room(room_t *room_1, room_t *room_2);
void connect_all_rooms(map_t *map);
int win_condition(map_t *map, bot_t **bots);
void mininit(map_t *map);
char *after_movement(bot_t *bot);
room_t *get_room_from_bot(map_t *map, char *id, bot_t *bot);
room_t *get_best(room_t *bot_r, bot_t *bot);
chain_t *get_best_path(map_t *map, bot_t *bot);
#endif
