/*
** EPITECH PROJECT, 2021
** LE-MIN
** File description:
** print_map.c
*/

#include "lib.h"

void print_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        write(1, map[i], my_strlen(map[i]));
        write(1, "\n", 1);
    }
}
