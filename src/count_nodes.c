/*
** EPITECH PROJECT, 2026
** epitech
** File description:
** projet
*/

#include "../include/mysh.h"

int count_nodes(env_dup_t *list)
{
    int i = 0;

    while (list) {
        i++;
        list = list->next;
    }
    return i;
}
