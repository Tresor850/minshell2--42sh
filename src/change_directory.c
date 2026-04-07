/*
** EPITECH PROJECT, 2026
** epitech
** File description:
** projet
*/

#include "../include/mysh.h"

int count_args(char **argv)
{
    int i = 0;

    if (!argv)
        return (84);
    while (argv[i] != NULL) {
        i++;
    }
    return (i);
}

static void update_pwd_env(env_dup_t *env_list, char *old_path)
{
    update_env_list(env_list, "OLDPWD", old_path);
}

static char *get_target_path(char *str, char **temp_tab)
{
    if (str == NULL || my_strcmp(str, "~") == 0)
        return (get_env_var(temp_tab, "HOME"));
    if (my_strcmp(str, "-") == 0)
        return (get_env_var(temp_tab, "OLDPWD"));
    return (str);
}

void change_directory(char *str, env_dup_t *env_list, char **argv)
{
    char cur[1024];
    char *path = NULL;
    char **temp_tab = list_to_tab(env_list);

    if (count_args(argv) > 2) {
        write(2, "cd: Too many arguments.\n", 24);
        return;
    }
    getcwd(cur, 1024);
    path = get_target_path(str, temp_tab);
    if (path && chdir(path) == 0) {
        update_pwd_env(env_list, cur);
    } else if (path) {
        write(2, argv[1], my_strlen(argv[1]));
        write(2, ": Not a directory.\n", 19);
    }
    for (int i = 0; temp_tab[i]; i++)
        free(temp_tab[i]);
    free(temp_tab);
}
