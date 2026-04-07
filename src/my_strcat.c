/*
** EPITECH PROJECT, 2026
** epitech
** File description:
** projet
*/

#include "../include/mysh.h"

char *my_strcat(char *path, char *cmd)
{
    int i = 0;
    int j = 0;

    while (path[i] != '\0')
        i++;
    while (cmd[j] != '\0') {
        path[i] = cmd[j];
        i++;
        j++;
    }
    path[i] = '\0';
    return (path);
}
