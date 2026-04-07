/*
** EPITECH PROJECT, 2026
** epitech
** File description:
** projet
*/

#include "../include/mysh.h"

static void print_env(char **env)
{
    int i;

    for (i = 0; env[i] != NULL; i++) {
        my_putstr(env[i]);
        my_putchar('\n');
    }
}

char *get_env_var(char **env, char *key)
{
    int len = 0;

    while (key[len])
        len++;
    for (int i = 0; env && env[i]; i++) {
        if (my_strncmp(env[i], key, len) == 0 && env[i][len] == '=')
            return &env[i][len + 1];
    }
    return NULL;
}

static void clause(char *new_var)
{
    if (!new_var)
        return;
}

static void setenv_clause(env_dup_t *env, char **args)
{
    int count = 0;

    for (count = 0; args[count] != NULL; count++);
    if (count == 1) {
        display_env(env);
        return;
    }
    if (count > 3) {
        write(2, "setenv: Too many arguments.\n", 28);
        return;
    }
    if (count == 3) {
        set_env_var(&env, args[1], args[2]);
        return;
    }
    if (count == 2) {
        set_env_var(&env, args[1], args[2]);
        return;
    }
}

static void check_unsetenv(char **args, env_dup_t **env)
{
    if (my_strcmp(args[0], "unsetenv") == 0) {
        if (args[1] != NULL)
            unset_env_var(env, args[1]);
        return;
    }
}

void handle_built_in(char **args, env_dup_t **env, int argc)
{
    char **env_list = list_to_tab(*env);

    if (my_strcmp(args[0], "exit") == 0) {
        my_putstr("exit\n");
        exit(0);
    }
    if (my_strcmp(args[0], "cd") == 0) {
        change_directory(args[1], *env, args);
        return;
    }
    if (my_strcmp(args[0], "env") == 0) {
        print_env(env_list);
        return;
    }
    if (my_strcmp(args[0], "setenv") == 0) {
        setenv_clause(*env, args);
        return;
    }
    check_unsetenv(args, env);
}

int check_built_in(char *cmd)
{
    if (my_strcmp(cmd, "exit") == 0 || my_strcmp(cmd, "cd") == 0 ||
        my_strcmp(cmd, "env") == 0 || my_strcmp(cmd, "setenv") == 0 ||
        my_strcmp(cmd, "unsetenv") == 0)
        return (1);
    return (0);
}

static void exit_clause(pid_t child_proc)
{
    if (child_proc == -1)
        exit(84);
}

int check_pipe(char **array)
{
    int i = 0;

    for (i = 0; array[i] != NULL; i++) {
        if (my_strcmp(array[i], "|") == 0 && array[i + 1] == NULL)
            write(2, "Invalid null command.\n", 21);
        if (my_strcmp(array[i], "|") == 0) {
            return i;
        } else {
            continue;
        }
    }
    return 0;
}

void handle_command(char *ligne, env_dup_t **env, int argc)
{
    char **commands = my_str_to_word_semicolon(ligne);
    char **env_tab = list_to_tab(*env);
    int i = 0;

    if (!commands)
        return;
    while (commands[i] != NULL) {
        process_single_command(commands[i], env, env_tab, argc);
        i++;
    }
    free_tab(env_tab);
    my_free_tab(commands);
}
