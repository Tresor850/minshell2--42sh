/*
** EPITECH PROJECT, 2026
** epitech
** File description:
** projet
*/

#include "../include/mysh.h"

env_dup_t *duplicate_env(char **env_prime)
{
    int i = 0;
    env_dup_t *head = malloc(sizeof(env_dup_t));
    env_dup_t *current = head;

    if (!env_prime || !env_prime[0])
        return NULL;
    for (i = 0; env_prime[i] != NULL; i++) {
        current->env_part = my_strdup(env_prime[i]);
        if (env_prime[i + 1] != NULL) {
            current->next = malloc(sizeof(env_dup_t));
            current = current->next;
        } else {
            current->next = NULL;
        }
    }
    return head;
}
