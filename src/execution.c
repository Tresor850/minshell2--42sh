/*
** EPITECH PROJECT, 2026
** epitech
** File description:
** projet
*/

#include <errno.h>
#include <signal.h>
#include "../include/mysh.h"

static void memory_error(char *command)
{
    if (errno == ENOMEM) {
        write(2, command, my_strlen(command));
        write(2, "Cannot allocate memory\n", 23);
        return;
    }
}

static void exec_error(char *command)
{
    if (errno == ENOEXEC) {
        write(2, command, my_strlen(command));
        write(2, ": Exec format error. Binary file not executable.\n", 50);
        return;
    }
}

static void dir_error(char *command, char **args)
{
    if (errno == ENOTDIR) {
        write(2, args[1], my_strlen(args[1]));
        write(2, ":Not a directory.\n", 16);
        return;
    }
}

static void access_error(char *command)
{
    if (errno == EACCES) {
        write(2, command, my_strlen(command));
        write(2, ": Permission denied.\n", 21);
        return;
    }
}

static void cat_error(char *command, char **args)
{
    if (errno == EISDIR) {
        write(2, args[1], my_strlen(args[1]));
        write(2, "Is a directory\n", 15);
        return;
    }
}

static void found_error(char *command)
{
    if (access(command, F_OK) == -1) {
        write(2, command, my_strlen(command));
        write(2, ": Command not found.\n", 21);
        return;
    }
}

void systeme_error_handing(char *command, char **args)
{
    access_error(command);
    cat_error(command, args);
    dir_error(command, args);
    exec_error(command);
    memory_error(command);
    found_error(command);
}

int signal_handle(int status)
{
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == SIGSEGV)
            write(2, "Segmentation fault", 18);
        if (WTERMSIG(status) == SIGFPE)
            write(2, "Floating exception", 18);
        if (WCOREDUMP(status))
            write(2, " (core dumped)", 14);
        write(2, "\n", 1);
        return (128 + WTERMSIG(status));
    }
    return 0;
}

int execution(char *input, char **env)
{
    char **args = my_str_to_word_array(input);
    char *path = find_command_path(args[0], env);
    pid_t pid = fork();
    int status;

    if (args == NULL || args[0] == NULL)
        return (0);
    if (path == NULL)
        path = args[0];
    if (pid == 0) {
        exec_redirections(args, env);
        if (execve(path, args, env) == -1) {
            systeme_error_handing(args[0], args);
            exit(84);
        }
    } else {
        wait(&status);
        signal_handle(status);
    }
    return (status);
}
