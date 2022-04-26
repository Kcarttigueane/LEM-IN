/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** my_strdup.c
*/

#include "lib.h"

char *my_strdup(char *str)
{
    if (str == NULL)
        return NULL;
    char *dupplicate = malloc(sizeof(char) * (my_strlen(str) + 1));
    my_strcpy(dupplicate, str);
    return (dupplicate);
}
