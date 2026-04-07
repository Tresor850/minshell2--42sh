/*
** EPITECH PROJECT, 2026
** epitech
** File description:
** projet
*/

#include "../include/mysh.h"

char *find_command_path(char *cmd, char **env)
{
    char *path_str = get_env_path(env);
    char **path_dirs;
    char *valid_path = NULL;

    if (path_str == NULL)
        return (NULL);
    path_dirs = my_str_to_word_array(path_str);
    for (int i = 0; path_dirs[i] != NULL; i++) {
        valid_path = parser(path_dirs[i], cmd);
        if (valid_path != NULL)
            return (valid_path);
    }
    return (NULL);
}
