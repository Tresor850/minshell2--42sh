/*
** EPITECH PROJECT, 2026
** epitech
** File description:
** projet
*/

#include "../include/mysh.h"

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    return dest;
}
