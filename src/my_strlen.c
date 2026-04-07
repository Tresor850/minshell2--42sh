/*
** EPITECH PROJECT, 2026
** epitech
** File description:
** projet
*/

#include "../include/mysh.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}
