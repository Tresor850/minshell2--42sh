/*
** EPITECH PROJECT, 2026
** epitech
** File description:
** projet
*/

#include "../include/mysh.h"

static char *ajouter_str(const char *str, int length)
{
    char *mot = malloc(sizeof(char) * (length + 1));
    int i = 0;

    if (!mot)
        return (NULL);
    for (i = 0; i < length; i++) {
        mot[i] = str[i];
    }
    mot[length] = '\0';
    return (mot);
}

static int my_strisalpha(char c)
{
    if (c != '\t' && c != '\0' && c != ' ' &&
        c != '\n' && c != ':' && c != '=')
        return (1);
    return (0);
}

static int compter_mot(const char *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i = i + 1) {
        if (my_strisalpha(str[i]) && (i == 0 || !my_strisalpha(str[i - 1])))
            nb = nb + 1;
    }
    return (nb);
}

static int skip_word(const char *str, int i)
{
    while (str[i] != '\0' && my_strisalpha(str[i])) {
        i = i + 1;
    }
    return (i);
}

char **my_str_to_word_array(const char *str)
{
    int nb = compter_mot(str);
    char **res = malloc(sizeof(char *) * (nb + 1));
    int i = 0;
    int m_idx = 0;
    int start;

    if (!res)
        return (NULL);
    while (str[i] != '\0') {
        if (my_strisalpha(str[i])) {
            start = i;
            i = skip_word(str, i);
            res[m_idx] = ajouter_str(&str[start], i - start);
            m_idx = m_idx + 1;
        } else {
            i = i + 1;
        }
    }
    res[m_idx] = NULL;
    return (res);
}
