/*
** EPITECH PROJECT, 2026
** epitech
** File description:
** projet
*/

#include "../include/mysh.h"

void print_arg(char **arg)
{
    while (*arg) {
        my_putstr(*arg);
        my_putchar('\n');
        arg++;
    }
}
