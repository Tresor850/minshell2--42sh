/*
** EPITECH PROJECT, 2026
** minshell2
** File description:
** redirections
*/

#include <fcntl.h>
#include "../include/mysh.h"

static int get_redir_type(char **args)
{
    for (int i = 0; args[i]; i++) {
        if (my_strcmp(args[i], ">") == 0)
            return 1;
        if (my_strcmp(args[i], ">>") == 0)
            return 2;
        if (my_strcmp(args[i], "<") == 0)
            return 3;
    }
    return 0;
}

static int apply_redir(char *file, int type)
{
    int fd = -1;

    if (type == 1)
        fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (type == 2)
        fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (type == 3)
        fd = open(file, O_RDONLY);
    if (fd == -1) {
        perror(file);
        exit(1);
    }
    if (type == 1 || type == 2)
        dup2(fd, STDOUT_FILENO);
    else
        dup2(fd, STDIN_FILENO);
    close(fd);
    return 0;
}

void exec_redirections(char **args, char **env)
{
    int type = get_redir_type(args);
    int i = 0;

    if (type == 0)
        return;
    while (args[i] && my_strcmp(args[i], ">") != 0 &&
        my_strcmp(args[i], ">>") != 0 && my_strcmp(args[i], "<") != 0)
        i++;
    if (args[i + 1] == NULL) {
        write(2, "Missing name for redirect.\n", 27);
        exit(1);
    }
    apply_redir(args[i + 1], type);
    args[i] = NULL;
}
