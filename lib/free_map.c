/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** free_map.c
*/

#include "lib.h"

void free_map(char **map)
{
    if (map == NULL)
        return;
    for (int i = 0; map[i]; i++)
        free(map[i]);
}
