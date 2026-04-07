/*
** EPITECH PROJECT, 2026
** epitech
** File description:
** projet
*/

#include "../include/mysh.h"

char *get_env_path(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "PATH=", 5) == 0)
            return (env[i] + 5);
    }
    return (NULL);
}
