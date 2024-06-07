/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** Prototypes needed functions
*/

#ifndef MY_H
    #define MY_H
    #include <stdlib.h>
int error_checker(char **tab);
int signal_handler(int id);
void error_message(char *input);
char *adding_empty(char **env, char **empty_tab, char **tab, int i);
void add_var(char **env, char **tab, int len_var);
void unset(char **env, int i);
char *adding(char **env, char **empty_tab, char **tab, int i);
char **tab_cpy(char **empty_tab, char **tab);
void var_replaced(char **env, char **tab, int i);
int do_setenv(char **env, char **tab);
char *get_oldpwd(char *oldpwd);
void set_owd(char **env, int i);
void set_pwd(char **env);
int tab_len(char **tab);
char *get_env(char *name, char **env);
void do_cd(char *input, char **env);
void do_env(char **env);
int do_unsetenv(char **env, char **tab);
char *rm_esc_seq(char *str);
char *parse_path(char **env, char *input);
char **my_path_to_word_array(char *buffer);
int path_word_nbr(const char *str);
char **get_path_cmd(char **env, char *input);
void path_create_tab(char **tab, int num_words, char *buffer);
int path_inc_k(char c, char **tab, int k, int j);
int nanagram(char const *s1, char const *s2, int limit);
int my_strncmp(char const *s1, char const *s2, int limit);
int word_nbr(char const *str);
char **my_str_to_word_array(char *str);
int inc_k(char c, char **tab, int k, int j);
void end_tab(char **tab, int j, int k);
void my_putchar(char c);
int my_printf(const char *format, ...);
int my_isneg(int nb);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strdup(char const *src);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src, char *sep);
char *my_strncat(char *dest, char const *src, int nb);
char **my_str_to_array(char *str, char *delim);
void *my_realloc(void *ptr, size_t size);
void my_memcopy(void *dest, const void *src, size_t size);
#endif
