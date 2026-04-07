/*
** EPITECH PROJECT, 2026
** epitech
** File description:
** bibliotheque
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#ifndef MYSH_H
    #define MYSH_H

typedef struct env_dup_s {
    char *env_part;
    struct env_dup_s *next;
} env_dup_t;

int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
char *my_strcat_path(char *path, char *cmd);
char **my_str_to_word_array(const char *str);
void my_putchar(char c);
void my_putstr(char *str);
void print_arg(char **arg);
char *parser(char *path, char *cmd);
char *get_env_path(char **env);
char *find_command_path(char *cmd, char **env);
int execution(char *input, char **env);
env_dup_t *duplicate_env(char **env_prime);
void add_to_env_list(env_dup_t **env, char *new_line);
void set_env_var(env_dup_t **env, char *name, char *value);
void display_env(env_dup_t *head);
env_dup_t *unset_env_var(env_dup_t **env, char *path);
char **list_to_tab(env_dup_t *list);
void handle_command(char *ligne, env_dup_t **env, int argc);
int is_built_in(char *cmd);
char *my_strdup(char *str);
void free_env_dup(env_dup_t *env);
int my_strncmp(char const *s1, char const *s2, int n);
void set_env_var(env_dup_t **env, char *name, char *value);
void update_env_list(env_dup_t *env, char *key, char *value);
void change_directory(char *str, env_dup_t *env_list, char **argv);
char **list_to_tab(env_dup_t *list);
char *get_env_var(char **env, char *key);
char *my_strcpy(char *dest, char *src);
int count_nodes(env_dup_t *list);
char *my_strcat(char *path, char *cmd);
int pipe_execution(char *b_pipe, char *a_pipe, char **env);
char **my_str_to_word_pipe(char const *str);
void my_free_tab(char **tab);
void free_tab(char **env_tab);
int check_pipe(char **array);
int check_built_in(char *cmd);
void handle_built_in(char **args, env_dup_t **env, int argc);
char **my_str_to_word_semicolon(char const *str);
void exec_multiple_pipes(char **piper, char **env);
void exec_redirections(char **args, char **env);
void process_single_command(char *cmd, env_dup_t **env,
    char **env_tab, int argc);
env_dup_t *find_env_var(env_dup_t *env, char *path);
#endif
