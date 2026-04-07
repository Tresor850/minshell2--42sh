/*
** EPITECH PROJECT, 2026
** epitech
** File description:
** projet
*/

#include "../include/mysh.h"

char **list_to_tab(env_dup_t *list)
{
    int size = count_nodes(list);
    char **tab = malloc(sizeof(char *) * (size + 1));
    int i = 0;

    if (!tab)
        return NULL;
    while (list) {
        tab[i] = my_strdup(list->env_part);
        list = list->next;
        i++;
    }
    tab[i] = NULL;
    return tab;
}
