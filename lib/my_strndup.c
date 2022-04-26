/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** my_strndup.c
*/

#include "lib.h"

char *my_strndup(const char *str, int n)
{
    int i = 0;
    char *dupplicate = malloc(sizeof(char) * (n + 1));

    for (; str[i] != '\0' && i < n; i++)
        dupplicate[i] = str[i];
    dupplicate[i] = '\0';
    return (dupplicate);
}
