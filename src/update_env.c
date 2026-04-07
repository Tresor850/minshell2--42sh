/*
** EPITECH PROJECT, 2026
** epitech
** File description:
** projet
*/

#include "../include/mysh.h"

void update_env_list(env_dup_t *env, char *key, char *value)
{
    env_dup_t *node = find_env_var(env, key);
    char *new_str;
    int len = my_strlen(key) + my_strlen(value) + 2;

    new_str = malloc(sizeof(char) * len);
    if (!new_str)
        return;
    my_strcpy(new_str, key);
    my_strcat(new_str, "=");
    my_strcat(new_str, value);
    if (node) {
        free(node->env_part);
        node->env_part = new_str;
    }
}
