/*
** EPITECH PROJECT, 2026
** epitech
** File description:
** projet
*/

#include "../include/mysh.h"

char *my_strcat_path(char *path, char *cmd)
{
    int i = 0;
    int j = 0;
    int len = my_strlen(path) + my_strlen(cmd) + 2;
    char *res = malloc(sizeof(char) * len);

    if (!res)
        return (NULL);
    while (path[i]) {
        res[i] = path[i];
        i++;
    }
    res[i] = '/';
    i++;
    while (cmd[j]) {
        res[i] = cmd[j];
        i++;
        j++;
    }
    res[i] = '\0';
    return (res);
}
