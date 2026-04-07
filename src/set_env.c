/*
** EPITECH PROJECT, 2026
** epitech
** File description:
** projet
*/

#include "../include/mysh.h"

static int var_name_checker(char *name)
{
    int i = 0;

    for (i = 0; name[i] != '\0'; i++) {
        if (name[0] >= 'a' && name[0] <= 'z'
            || name[0] >= 'A' && name[0] <= 'Z') {
            continue;
        } else {
            my_putstr("setenv: Variable name must begin with a letter.\n");
            return 1;
        }
    }
    return 0;
}

static char *is_not_array(char *new_line, char *name, char *value)
{
    new_line = my_strdup(name);
    my_strcat(new_line, "=");
    my_strcat(new_line, value);
    return new_line;
}

void set_env_var(env_dup_t **env, char *name, char *value)
{
    env_dup_t *existing = find_env_var(*env, name);
    char *new_line;
    int len;

    if (!new_line)
        return;
    if (var_name_checker(name) == 1)
        return;
    if (value == NULL) {
        new_line = my_strdup(name);
        my_strcat(new_line, "=");
    } else if (value != NULL) {
        new_line = is_not_array(new_line, name, value);
    }
    if (existing) {
        free(existing->env_part);
        existing->env_part = new_line;
    } else {
        add_to_env_list(env, new_line);
    }
}

void add_to_env_list(env_dup_t **env, char *new_line)
{
    env_dup_t *new_node = malloc(sizeof(env_dup_t));
    env_dup_t *tmp = *env;

    if (!new_node)
        return;
    new_node->env_part = new_line;
    new_node->next = NULL;
    if (*env == NULL) {
        *env = new_node;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new_node;
}
