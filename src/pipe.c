/*
** EPITECH PROJECT, 2026
** pipe
** File description:
** minishell2
*/

#include "../include/mysh.h"

static void child_process(int p_fd[2], int prev_fd, char *cmd, char **env)
{
    if (prev_fd != STDIN_FILENO) {
        dup2(prev_fd, STDIN_FILENO);
        close(prev_fd);
    }
    if (p_fd[1] != STDOUT_FILENO) {
        dup2(p_fd[1], STDOUT_FILENO);
        close(p_fd[0]);
        close(p_fd[1]);
    }
    execution(cmd, env);
    exit(0);
}

void exec_multiple_pipes(char **piper, char **env)
{
    int p_fd[2];
    int prev_fd = STDIN_FILENO;
    int i = 0;

    for (i = 0; piper[i] != NULL; i++) {
        if (piper[i + 1] != NULL)
            pipe(p_fd);
        else
            p_fd[1] = STDOUT_FILENO;
        if (fork() == 0)
            child_process(p_fd, prev_fd, piper[i], env);
        if (prev_fd != STDIN_FILENO)
            close(prev_fd);
        if (piper[i + 1] != NULL) {
            close(p_fd[1]);
            prev_fd = p_fd[0];
        }
    }
    while (wait(NULL) > 0);
}
