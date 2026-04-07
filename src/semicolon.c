/*
** EPITECH PROJECT, 2026
** semicolon
** File description:
** minishell2
*/

#include <stdlib.h>

static int count_semicolon(char const *str)
{
    int i = 0;
    int count = 0;

    while (str && str[i] != '\0') {
        if (str[i] == ';')
            count++;
        i++;
    }
    return (count + 1);
}

static int segment_len(char const *str, int start)
{
    int len = 0;

    while (str[start + len] != '\0' && str[start + len] != ';')
        len++;
    return (len);
}

static char *fill_segment(char const *str, int *k)
{
    int len = segment_len(str, *k);
    char *dest = malloc(sizeof(char) * (len + 1));
    int j = 0;

    if (!dest)
        return (NULL);
    while (j < len) {
        dest[j] = str[*k];
        *k = *k + 1;
        j++;
    }
    dest[j] = '\0';
    if (str[*k] == ';')
        *k = *k + 1;
    return (dest);
}

char **my_str_to_word_semicolon(char const *str)
{
    int nb_segments = count_semicolon(str);
    char **tab = malloc(sizeof(char *) * (nb_segments + 1));
    int i = 0;
    int k = 0;

    if (!tab)
        return (NULL);
    while (i < nb_segments) {
        tab[i] = fill_segment(str, &k);
        i++;
    }
    tab[i] = NULL;
    return (tab);
}
