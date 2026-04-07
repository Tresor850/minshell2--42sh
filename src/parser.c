/*
** EPITECH PROJECT, 2026
** epitech
** File description:
** projet
*/

#include "../include/mysh.h"

char *parser(char *path, char *cmd)
{
    char *full_path = my_strcat_path(path, cmd);

    if (full_path == NULL)
        return (NULL);
    if (access(full_path, X_OK) == 0) {
        return (full_path);
    }
    free(full_path);
    return (NULL);
}
