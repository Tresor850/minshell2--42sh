/*
** EPITECH PROJECT, 2026
** epitech
** File description:
** projet
*/

#include "../include/mysh.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

char *my_strdup(char *str)
{
    char *dest;
    int i = 0;

    dest = malloc(sizeof(char) * my_strlen(str) + 1);
    if (!dest)
        return NULL;
    for (i = 0; str[i] != '\0'; i++) {
        dest[i] = str[i];
    }
    dest[i] = '\0';
    return dest;
}

void free_env_dup(env_dup_t *env)
{
    env_dup_t *tmp;

    while (env != NULL) {
        tmp = env;
        env = env->next;
        free(tmp->env_part);
        free(tmp);
    }
}

env_dup_t *find_env_var(env_dup_t *env, char *path)
{
    int len = 0;

    for (len = 0; path[len] != '\0'; len++);
    while (env != NULL) {
        if (my_strncmp(env->env_part, path, len) == 0
            && env->env_part[len] == '=')
            return env;
        env = env->next;
    }
    return NULL;
}

static void list_clause(env_dup_t **env, env_dup_t *prev, env_dup_t *tmp)
{
    if (prev == NULL) {
        *env = tmp->next;
    } else {
        prev->next = tmp->next;
    }
}

env_dup_t *unset_env_var(env_dup_t **env, char *path)
{
    env_dup_t *tmp = *env;
    env_dup_t *prev = NULL;
    int len = 0;

    for (len = 0; path[len] != '\0'; len++);
    while (tmp != NULL) {
        if (my_strncmp(tmp->env_part, path, len) == 0
            && tmp->env_part[len] == '=') {
            list_clause(env, prev, tmp);
            free(tmp->env_part);
            free(tmp);
            return *env;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    return *env;
}

void display_env(env_dup_t *head)
{
    env_dup_t *tmp;

    if (head == NULL) {
        my_putstr("(L'environnement ent vide)\n");
        return;
    }
    tmp = head;
    while (tmp != NULL) {
        if (tmp->env_part != NULL) {
            my_putstr(tmp->env_part);
            my_putchar('\n');
        }
        tmp = tmp->next;
    }
}
