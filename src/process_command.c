/*
** EPITECH PROJECT, 2026
** epitech
** File description:
** minishell2
*/

#include "../include/mysh.h"

static void exec_pipeline(char *cmd, char **env_tab)
{
    char **piper = my_str_to_word_pipe(cmd);

    if (piper == NULL)
        return;
    exec_multiple_pipes(piper, env_tab);
    my_free_tab(piper);
}

void process_single_command(char *cmd, env_dup_t **env,
    char **env_tab, int argc)
{
    char **args = my_str_to_word_array(cmd);

    if (args == NULL || args[0] == NULL)
        return;
    if (check_built_in(args[0])) {
        handle_built_in(args, env, argc);
    } else if (check_pipe(args) != 0) {
        exec_pipeline(cmd, env_tab);
    } else {
        execution(cmd, env_tab);
    }
    my_free_tab(args);
}
