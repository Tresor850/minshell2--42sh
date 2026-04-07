/*
** EPITECH PROJECT, 2026
** epitech
** File description:
** projet
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include "../include/mysh.h"

void if_clause(void)
{
    if (isatty(0))
        write(1, "\n", 1);
}

char *create_my_home(void)
{
    char *home;
    char *promt;

    getcwd(home, 100);
    promt = my_strcat(home, "$> ");
    return promt;
}

void free_body(env_dup_t *env_copy, char *ligne)
{
    free_env_dup(env_copy);
    free(ligne);
}

void sigint_handle(int sig)
{
    my_putstr("\n\033[1;32m$>\033[0m ");
}

int main(int ac, char **av, char **env)
{
    char *ligne = NULL;
    size_t taille = 0;
    env_dup_t *env_copy = duplicate_env(env);
    ssize_t lus;

    signal(SIGINT, sigint_handle);
    while (1) {
        if (isatty(0))
            my_putstr("\033[1;32m$>\033[0m ");
        lus = getline(&ligne, &taille, stdin);
        if (lus == -1) {
            if_clause();
            break;
        }
        if (lus > 0 && ligne[lus - 1] == '\n')
            ligne[lus - 1] = '\0';
        if (ligne[0] != '\0')
            handle_command(ligne, &env_copy, ac);
    }
    free_body(env_copy, ligne);
    return 0;
}
