/*
** EPITECH PROJECT, 2026
** free
** File description:
** minishell2
*/

#include "../include/mysh.h"

void my_free_tab(char **tab)
{
    int i = 0;

    if (tab == NULL)
        return;
    while (tab[i] != NULL) {
        free(tab[i]);
        i++;
    }
    free(tab);
}

void free_tab(char **env_tab)
{
    int i = 0;

    for (i = 0; env_tab[i]; i++)
        free(env_tab[i]);
    free(env_tab);
}
